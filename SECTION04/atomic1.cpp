#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

std::mutex m;
long x = 0; // 모든 스레드가 공유.

void foo()
{
    for ( int i = 0; i < 100000; ++i)
    {
//        m.lock();
//        ++x;
//        m.unlock();

//        __asm
//        {
//            lock inc x
//        }
        InterlockedIncrement(&x); //
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
