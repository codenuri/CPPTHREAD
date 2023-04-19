#include <iostream>
#include <atomic>
#include <thread>

class spinlock
{
	std::atomic_flag flag; // = ATOMIC_FLAG_INIT;
public:
	void lock()   { while(flag.test_and_set()); }
	void unlock() { flag.clear();}
};
spinlock spin;

void work()
{
	spin.lock();
	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;
	spin.unlock();
}

int main()
{
	std::jthread t1(work),
				 t2(work);
}
