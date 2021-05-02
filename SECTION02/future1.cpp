#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{	
	std::this_thread::sleep_for(1s);
	p.set_value(a+b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

    std::thread t(add, std::move(pm), 10, 20);

//    int n1 = ft.get();
    

    std::future_status ret = ft.wait_for(2s);

    if ( ret == std::future_status::ready )
        std::cout << "ready !" << std::endl;

    else if ( ret == std::future_status::timeout )
        std::cout << "timeout !" << std::endl;

    else // std::future_status::deferred
        std::cout << "deferred !" << std::endl;

	t.join();
}



