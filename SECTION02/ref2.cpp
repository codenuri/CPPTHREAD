#include <iostream>

template<typename T> struct reference_wrapper
{
    T* obj;
public:
    reference_wrapper(T& t) : obj(&t) {}    
    operator T&() { return *obj;}
};

int main()
{
    int n = 0;
    reference_wrapper<int> rw = n;
  
    int& r = rw; // rw.operator int&() 
    r = 100;
  
    std::cout << n << std::endl; // 100
}