#include <iostream>
#include <string>
#include <thread>

void f1()                { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100;}

int main()
{
    int n = 0;
    std::string s = "hello";

    std::thread t1(&f1);
    std::thread t2(&f2, 10, 3.4);
    std::thread t3(&f3, 10, std::ref(n), std::move(s) );
    t1.join();
    t2.join();
    t3.join();

    std::cout << s << std::endl; // ""
    std::cout << n << std::endl; // 100
}

