#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

struct  Account
{
    std::mutex m;
    int money = 100;
};

/*
void transfer(Account& acc1, Account& acc2, int cnt)
{
//    acc1.m.lock();
//    acc2.m.lock();
    std::lock(acc1.m, acc2.m);

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
    acc2.m.unlock();
    acc1.m.unlock();
}
*/
/*
void transfer(Account& acc1, Account& acc2, int cnt)
{
    std::lock(acc1.m, acc2.m);
    std::lock_guard<std::mutex> lg1(acc1.m, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(acc2.m, std::adopt_lock);

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
}
*/

void transfer(Account& acc1, Account& acc2, int cnt)
{
//    std::scoped_lock<std::mutex, std::mutex> lg(acc1.m, acc2.m);// ok
    std::scoped_lock lg(acc1.m, acc2.m);// ok

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
}

int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}
 
