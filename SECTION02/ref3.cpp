#include <iostream>

template<typename T> struct reference_wrapper
{
    T* obj;
public:
    reference_wrapper(T& t) : obj(&t) {}    
    operator T&() { return *obj;}
};


void foo(int& a) { a = 200; }

template<typename T> 
void call_foo(T arg) // reference_wrapper<int> arg
{
    foo(arg);
}

template<typename T> reference_wrapper<T> ref(T& obj )
{
    return reference_wrapper<T>(obj);
}

int main()
{
    int n = 0;

    //call_foo(n);
    //reference_wrapper<int> rw = n;
    //call_foo(rw);

    call_foo( ref(n) ); // std::ref(n)

    std::cout << n << std::endl; // 200
}