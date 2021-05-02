#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2(10);

    std::promise<void> pm1;
    std::future<void>  ft1 = pm1.get_future();

    std::promise<int> pm2;
    std::future<int>  ft2 = pm2.get_future();

    std::thread t( [&]{
        std::partial_sum(v1.begin(), v1.end(), v2.begin()); // 부분합 구하기

        pm1.set_value( );  // 1번째 연산이 종료되었음을 알린다.

        int s = std::accumulate(v2.begin(), v2.end(), 0);   // 구간의 합 구하기

        pm2.set_value(s);
        });

    ft1.get();
    for( auto n : v2)
        std::cout << n << ", ";

    int ret = ft2.get();
    std::cout << "\n" << ret << std::endl;

    t.join();
}



