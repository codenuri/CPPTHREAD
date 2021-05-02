#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
     //add(10, 20); // 동기 호출
     std::future<int> ft = std::async(add, 10, 20);
     std::cout << "continue main" << std::endl;
     int ret = ft.get();
     std::cout << "result : " << ret << std::endl;
    
}

