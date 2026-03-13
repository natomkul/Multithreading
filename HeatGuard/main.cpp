#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv_sens, cv_alarm;
int data;
bool ready = false;
bool processed = true;


void sensor()
{
    while (true)
    {
        std::unique_lock lk(mtx);
        cv_sens.wait(lk, []{ return processed; });
    
        data = rand() % 110;
        printf("sensor noted temperature: %d \n", data);

        ready = true;
        processed = false;
        cv_alarm.notify_one();
    }
}

void alarm()
{
    while (true)
    {
        std::unique_lock lk(mtx);
        cv_alarm.wait(lk, []{ return ready; });

        if (data > 100)
        {
            printf("CRITICAL STATE temperature: %d \n", data);
        }
        else if (data > 85)
        {
            printf("TOO HOT temperature: %d \n", data);
        }
        else if (data > 50)
        {
            printf("little warm but normal: %d \n", data);
        }
        else
        {
            printf("normal: %d \n", data);
        }

        data = 0;

        ready = false;
        processed = true;
        cv_sens.notify_one();
    }
}

int main()
{
    std::thread Sensor(sensor);
    std::thread Alarm(alarm);

    Sensor.join();
    Alarm.join();
}
