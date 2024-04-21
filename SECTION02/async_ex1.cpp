#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 10000000; 

std::vector<int> v1, v2;

void fill_vector()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(0, 100);

    v1.reserve(NUM);
    v2.reserve(NUM);

    for (int i = 0; i < NUM; ++i)
    {
        v1.push_back(dist(engine));
        v2.push_back(dist(engine));
    }
}


long long f1()
{
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0LL);
}

long long f2()
{
    std::size_t bsize = v1.size() / 4;

    auto v1_start = v1.begin();
    auto v1_end   = std::next(v1.begin(), bsize);
    auto v2_start = v2.begin();

    auto future1 = std::async([v1_start, v1_end, v2_start] {return std::inner_product(v1_start, v1_end, v2_start, 0LL); });

    v1_start = v1_end;

    std::advance(v1_end, bsize);
    std::advance(v2_start, bsize);

    auto future2 = std::async([v1_start, v1_end, v2_start] {return std::inner_product(v1_start, v1_end, v2_start, 0LL); });
    
    v1_start = v1_end;
    std::advance(v1_end, bsize);
    std::advance(v2_start, bsize);
    
    auto future3 = std::async([v1_start, v1_end, v2_start] {return std::inner_product(v1_start, v1_end, v2_start, 0LL); });
    
    v1_start = v1_end;
    v1_end   = v1.end();
    std::advance(v2_start, bsize);
    

    auto future4 = std::async([v1_start, v1_end, v2_start] {return std::inner_product(v1_start, v1_end, v2_start, 0LL); });

    return future1.get() + future2.get() + future3.get() + future4.get();
}

void measure_execution_time(std::string name, long long(*f)())
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    long long result = f();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::cout << name << " : " << result << ", " << time_span.count() << " seconds." << std::endl;;
}

int main()
{
    fill_vector();
    std::cout << "start.. inner_product" << std::endl;
    measure_execution_time("f1", f1);
    measure_execution_time("f2", f2);
}
