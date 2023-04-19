#include <iostream>
#include <thread>
#include <atomic>

struct Machine
{
	int data{ 0 };
	int count{ 0 };
};
Machine m;

void foo()
{
//	std::atomic<int> cnt{m.count};
//	int& cnt{m.count};
	std::atomic_ref<int> cnt{m.count};

	for (int i = 0; i < 1000000; i++)
	{
		//++(m.count);
		++cnt;
	}
}
int main()
{
	{
		std::jthread t1(foo), t2(foo), t3(foo);
	}
	std::cout << m.count << std::endl;
}
