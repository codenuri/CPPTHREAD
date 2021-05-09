#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

void foo()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(5);

    // 값에 의한 캡쳐
    std::thread t1( [ptr]() mutable 
    { 
        ptr = std::make_shared<int>(1); // --ref
    });

    std::thread t2( [ptr]() mutable 
    { 
        ptr = std::make_shared<int>(2);
    }); 
    t1.join();
    t2.join();
}

void goo()
{
//    std::shared_ptr<int> ptr = std::make_shared<int>(5);

    // C++20 부터 아래 코드 허용.
    std::atomic<std::shared_ptr<int>> ptr = std::make_shared<int>(5);

    // 참조에 의한 캡쳐
    std::thread t1( [&ptr]() //mutable 
    { 
        ptr = std::make_shared<int>(1);
    });

    std::thread t2( [&ptr]() //mutable 
    { 
        ptr = std::make_shared<int>(2);
    }); 
    t1.join();
    t2.join();
}

int main()
{
    foo();
}