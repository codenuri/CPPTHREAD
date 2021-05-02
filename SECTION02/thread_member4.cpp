#include <thread>

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

    t1.swap(t2);

//    std::thread t3 = t1;  // error  
    std::thread t4 = std::move(t1);  // ok

//    t1.join(); // 예외.
    t2.join();
    t4.join();
}

