#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

std::mutex m;

bool use_flag = false;

void work()
{
//	m.lock();
	while( use_flag );
	use_flag = true; // 사용중
	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;
	use_flag = false;
//	m.unlock();
}

int main()
{
	std::jthread t1(work),
				 t2(work);
}
