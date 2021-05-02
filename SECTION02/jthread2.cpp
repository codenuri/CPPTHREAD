#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

void foo()
{
    for( int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;
    }
}
void goo( std::stop_token token ) 
{     
    for( int i = 0; i < 10; i++)
    {
        if ( token.stop_requested() )
        {
            std::cout << "중지요청" << std::endl;
            return ;
        }

        std::this_thread::sleep_for(500ms);
        std::cout << "goo : " << i << std::endl;
    }
}
int main() 
{
    std::jthread j1(foo);
    std::jthread j2(goo);
    std::this_thread::sleep_for(2s);

    j1.request_stop();
    j2.request_stop();
}