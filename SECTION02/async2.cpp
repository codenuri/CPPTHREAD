#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;    
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
    std::future<int> ft = std::async( std::launch::async,    add, 10, 20);
//    std::future<int> ft = std::async( std::launch::deferred, add, 10, 20); // 지연된 실행
//    std::future<int> ft = std::async( std::launch::async | std::launch::deferred , add, 10, 20);
//    std::future<int> ft = std::async( add, 10, 20);

    std::cout << "continue main : " << std::this_thread::get_id() << std::endl;    
    std::this_thread::sleep_for(2s);
    int ret = ft.get();

    std::cout << "result : " << ret << std::endl;
}

 

