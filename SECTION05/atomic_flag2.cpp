#include <iostream>
#include <atomic>
#include <thread>


//std::atomic_flag = ATOMIC_FLAG_INIT; // until C++20

std::atomic_flag flag;  // C++20 부터
						// false 초기화.
void work()
{
	while( flag.test_and_set() );

	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;

	flag.clear(); // flag = false;
}

int main()
{
	std::jthread t1(work),
				 t2(work);
}
