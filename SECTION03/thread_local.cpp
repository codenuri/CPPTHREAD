#include <iostream>
#include <thread>
#include <string_view>

thread_local int x = 0;

int next3times()
{
//	thread_local static int n = 0;
	thread_local int n = 0;
	n = n + 3;
	return n;
}
void foo(std::string_view name)
{
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
}
int main()
{
//	foo("A");
	std::thread t1(foo, "A");
	std::thread t2(foo, "\tB");

	t1.join();
	t2.join();
}



