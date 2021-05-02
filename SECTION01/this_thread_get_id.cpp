#include <iostream>
#include <thread>

int main()
{
    std::cout << std::this_thread::get_id() << std::endl;

    std::thread::id tid1 = std::this_thread::get_id();
    std::thread::id tid2 = std::this_thread::get_id();
  
    tid1 == tid2;
    tid1 < tid2;

    std::hash<std::thread::id> h;

    std::cout << h(tid1) << std::endl;
}
