#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std::literals;
  
std::mutex m;
std::condition_variable cv;
int shared_data = 0;

void consumer()
{       
    std::this_thread::sleep_for(200ms);
    //std::lock_guard<std::mutex> lg(m);  
    std::unique_lock<std::mutex> ul(m);  
    cv.wait( ul );
    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{      
    std::this_thread::sleep_for(10ms);
    {
        std::lock_guard<std::mutex> lg(m);        
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;    
    }
    cv.notify_one();
    //std::this_thread::sleep_for(3s);
}




int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); t2.join();
}