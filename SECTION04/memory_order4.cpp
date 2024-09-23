#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;

int main()
{
    data1.store( 100, std::memory_order_seq_cst);
    data2.store( 200, std::memory_order_seq_cst);
    data2.store( 300);
}