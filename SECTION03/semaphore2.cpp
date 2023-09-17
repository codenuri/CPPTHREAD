#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>
using namespace std::literals;

std::counting_semaphore<3> sem(3); 



void Download(std::string name)
{ 
    sem.acquire(); // -- sem.counter

    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }

    sem.release(); // sem.counter += 1
}
int main() 
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    std::this_thread::sleep_for(2s);
    std::cout << "\n main \n";
    //sem.release();
    sem.release(2);  // 단, 이경우 반드시 update값(2) <= max() - counter 이어야 합니다.
                    // 최대값 보다 커질경우 undefined 입니다.

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();   
}
