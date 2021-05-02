#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void divide(std::promise<int>&& p, int a, int b)
{
    try
    {
        if ( b == 0 ) 
            throw std::runtime_error("divide by zero");

        p.set_value(a / b);
    }
    catch(...)
    {
        //p.set_exception( std::current_exception() );
        p.set_exception_at_thread_exit( std::current_exception() );
    }
}

int main()
{
	std::promise<int> pm;
	std::future<int>  ft = pm.get_future();

	std::thread t(divide, std::move(pm), 10, 0);

    try
    {
   	    int ret = ft.get(); 
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

	t.join();
}



