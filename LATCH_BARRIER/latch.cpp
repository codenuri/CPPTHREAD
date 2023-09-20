#include <iostream>
#include <mutex>
#include <latch>
#include <thread>

std::latch complete{3};
std::latch gohome{1};

void foo(std::string name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;
	complete.count_down(); // --count
	gohome.wait();
	std::cout << "go home     : " << name << std::endl;
}

int main()
{
	std::jthread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");

	complete.wait(); // 카운트가 0일때를 대기.

	std::cout << "receive signal" << std::endl;
	gohome.count_down();
}
