#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
}

void consume(std::shared_future<int> sf)
{
    sf.get();
    std::cout << "finish foo" << std::endl;
}
int main()
{
    std::promise<int> pm;
//    std::future<int> ft = pm.get_future();
    //std::future<int> ft2 = ft; // error
//    std::shared_future<int> sft = ft.share();

    std::shared_future<int> sft = pm.get_future();
 
    std::thread t(add, std::move(pm), 10, 20);

    std::thread t1(consume, sft);
    std::thread t2(consume, sft);

    t.join();
    t1.join();
    t2.join();
}



