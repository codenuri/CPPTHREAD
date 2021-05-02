#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::timed_mutex m;

int main()
{   
    std::unique_lock<std::timed_mutex> u1;
    std::unique_lock<std::timed_mutex> u2(m);

    //u1 = u2; // error
    u1 = std::move(u2); // ok

    std::cout << u1.owns_lock() << std::endl; // 1

    if ( u1 ) 
        std::cout << "acquire" << std::endl;
    
    u1.unlock();

    std::cout << u1.owns_lock() << std::endl;  // 0  

    if ( u1.try_lock_for(2s) )
    {
        //....
        u1.unlock();
    }

    u1.release();
}



