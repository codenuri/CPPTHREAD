// g++ reorder1.cpp –S –masm=intel -O2
// cl reorder1.cpp /FAs /c /O2
#include <atomic>
int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;
    //----- fence -----------
    //__asm { mfence }
    std::atomic_thread_fence( std::memory_order_release);
    b = 1;
}

// thread B
void goo()
{
    if ( b == 1 )
    {
        // a == 1 을 보장할수 있을까 ?
    }
}






