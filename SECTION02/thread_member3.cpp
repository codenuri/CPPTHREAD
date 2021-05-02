#include <iostream>
#include <thread>

int main()
{
    std::thread t;

    if ( t.joinable() )
    {
        t.join();
    }
}


/*
int main()
{
    std::thread t;
    try 
    {
        t.join();
    }
    catch(std::exception& e)
    {
        std::cout << "예외 : " << e.what() << std::endl;
    }
}
*/