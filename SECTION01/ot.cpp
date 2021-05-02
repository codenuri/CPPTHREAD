#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    int s = a + b;
    std::this_thread::sleep_for(1s);
    p.set_value(s);
}
int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();
    std::thread t(add, std::move(pm), 10, 20);

    int ret = ft.get();
    std::cout << ret << std::endl;
    t.join();
}
