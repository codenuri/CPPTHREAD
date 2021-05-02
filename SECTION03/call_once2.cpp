#include <iostream>
#include <thread>
#include <mutex>
using namespace std::literals;

class Singleton
{
private:
    Singleton() = default;
    static Singleton* sinstance;
    static std::once_flag create_flag;
public:
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

    static Singleton* getInstance() 
    {
        std::call_once(create_flag, initSingleton);
        return sinstance;
    }
    static void initSingleton()
    {
        sinstance = new Singleton;
    }
};
Singleton* Singleton::sinstance = nullptr;
std::once_flag Singleton::create_flag;
int main()
{
    std::cout << Singleton::getInstance() << std::endl;
    std::cout << Singleton::getInstance() << std::endl;
}



