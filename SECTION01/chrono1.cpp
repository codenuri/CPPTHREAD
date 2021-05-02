#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

int main()
{
    std::chrono::hours        h(10);
    std::chrono::minutes      m(10);    
    std::chrono::seconds      s1(10);
    std::chrono::milliseconds s2(10);
    std::chrono::nanoseconds  s3(10);

    std::cout << s1.count() << std::endl;

    std::chrono::duration<long long>    d1(10);

    auto a1 = 10s;
    auto a2 = 10ms;
    auto a3 = 10min;

    std::this_thread::sleep_for( std::chrono::duration<long long>(10) );
    std::this_thread::sleep_for( std::chrono::seconds(10) );
    std::this_thread::sleep_for( 10s );
}



