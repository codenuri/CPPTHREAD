#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

//std::mutex m;
std::recursive_mutex m;
int share_data = 0;

void foo()
{
    m.lock();
    m.lock(); // 2회 소유
    share_data = 100;
    std::cout << "using share_data" << std::endl;
    m.unlock();
    m.unlock();
}
int main()
{
	std::thread t1(foo);
    std::thread t2(foo);
	t1.join();
	t2.join();
}




