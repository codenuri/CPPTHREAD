#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std::literals;
  
std::mutex m;
std::condition_variable cv;
bool data_ready = false;
int shared_data = 0;

void consumer()
{       
    std::unique_lock<std::mutex> ul(m);  
    cv.wait( ul, [] { return data_ready;} );
    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{     
    std::this_thread::sleep_for(100ms); 
    {
        std::lock_guard<std::mutex> lg(m);        
        shared_data = 100;
        data_ready = true;
        std::cout << "produce : " << shared_data << std::endl;    
    }
    cv.notify_all();
//    cv.notify_one();
//    std::this_thread::sleep_for(500ms); 
//    cv.notify_one();
//    std::this_thread::sleep_for(500ms); 
//    cv.notify_one();
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    std::thread t3(consumer);
    std::thread t4(consumer);
    t1.join(); t2.join();
    t3.join(); t4.join();
}