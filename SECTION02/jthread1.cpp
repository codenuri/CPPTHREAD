#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo(int a, double d)
{
	std::cout << "start foo" << std::endl;
	std::this_thread::sleep_for(2s);
	std::cout << "finish foo" << std::endl;
}

class mythread
{
	std::thread th;
public:
	template<typename F, typename ... ARGS> 
	explicit mythread(F&& f, ARGS&& ... args)
		: th(std::forward<F>(f), std::forward<ARGS>(args)...) {}

	~mythread()
	{
		if (th.joinable())
			th.join();
	}
};

int main()
{
    std::jthread t(foo, 10, 3.4);

//    mythread t(foo, 10, 3.4);
//	std::thread t(foo, 10, 3.4);
//    t.join();
}





