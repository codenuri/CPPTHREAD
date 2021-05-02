#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "start add" << std::endl;    
    std::this_thread::sleep_for(2s);
    std::cout << "finish add" << std::endl;    
    return a + b;
}
int main()
{
//    std::future<int> ft = std::async( std::launch::async, add, 10, 20);
    
    std::async( std::launch::async, add, 10, 20);
//    std::async( std::launch::async, add, 10, 20);

    std::cout << "continue main " << std::endl;    

//    int ret = ft.get();
}

 

