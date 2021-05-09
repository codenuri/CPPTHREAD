#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <execution>
#include <mutex>
#include <chrono>
using namespace std::literals;

int main()
{
    std::vector<int> v(100, 0);

    for ( int i = 1 ; i <= 100; i++)
        v.push_back(i);  
    
//    std::mutex m;
//    int sum = 0;

    std::atomic<int> sum = 0;
    
    std::for_each(std::execution::par, v.begin(), v.end(), [&](int n) { 
            //std::lock_guard<std::mutex> lg(m);
            //sum += n;
            sum.fetch_add(n, std::memory_order_relaxed);
            std::this_thread::sleep_for(1ms);
        } );

    std::cout << sum << '\n';
}