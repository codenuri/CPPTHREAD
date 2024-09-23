#include <thread>
#include <atomic>

std::atomic<int> x = 0;
std::atomic<int> y = 0;

void foo()
{
    int n1 = y.load( std::memory_order_relaxed);
    x.store(n1, std::memory_order_relaxed);
}

void goo()
{
    int n2 = x.load(std::memory_order_relaxed);
    y.store(100, std::memory_order_relaxed);
}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}