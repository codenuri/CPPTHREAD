#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

int main()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(5);

    std::thread t1( [ptr]() mutable { 
        ptr = std::make_shared<int>(1);
    });
    std::thread t2( [ptr]() mutable { 
        ptr = std::make_shared<int>(2);
    });

    t1.join();
    t2.join();

}