#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

void mysleep(std::chrono::microseconds us)
{
    auto target = std::chrono::high_resolution_clock::now() + us;

    while (std::chrono::high_resolution_clock::now() < target)
        std::this_thread::yield();   
} 

int main()
{
    mysleep(1s);
}