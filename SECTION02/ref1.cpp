#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

template<typename T> void call_foo(T arg)
{
    foo(arg);
}

int main()
{
    int n = 0;
    
    //foo(n);
    //call_foo(n);
    call_foo( std::ref(n) );

    std::cout << n << std::endl;
}