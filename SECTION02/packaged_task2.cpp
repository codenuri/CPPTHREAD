#include <iostream>
#include <thread>
#include <future>

int add(int a, int b)
{
    std::cout << "add" << std::endl;
    return a + b;
}
int main()
{
    std::packaged_task<int(int, int)> task(add);
    std::future<int> ft = task.get_future();

    //task(10, 20); // add(10, 20)
    std::thread t(std::move(task), 10, 20);
    std::cout << "continue main" << std::endl;
    
    int ret = ft.get();
    std::cout << ret << std::endl;
    t.join();
}