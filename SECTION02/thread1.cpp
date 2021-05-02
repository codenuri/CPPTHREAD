#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for( int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}
int main()
{
    std::thread t(&foo);

 //   t.join();
    t.detach();
    std::cout << "end" << std::endl;

    int n;
    std::cin >> n;
}

