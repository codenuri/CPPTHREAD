#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

std::chrono::system_clock::time_point 
createDateTime(int year, int month, int day, int hour, int minute, int second);

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::this_thread::sleep_for(3s); // 3ms, 3ns, 3min
    //std::this_thread::sleep_for(3);  // error

    std::chrono::time_point tp1 = std::chrono::steady_clock::now();
    std::this_thread::sleep_until( tp1 + 2000ms );    

    auto tp2 = createDateTime(2021, 4, 11, 12, 39, 00);
    std::this_thread::sleep_until( tp2 );    
}

time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
    std::time_t tt = _mkgmtime(&timeinfo);
#else
    time_t tt = timegm(&timeinfo);
#endif
    return tt;
}

std::chrono::system_clock::time_point 
createDateTime(int year, int month, int day, int hour, int minute, int second)
{
    tm timeinfo1 = tm();
    timeinfo1.tm_year = year - 1900;
    timeinfo1.tm_mon = month - 1;
    timeinfo1.tm_mday = day;
    timeinfo1.tm_hour = hour;
    timeinfo1.tm_min = minute;
    timeinfo1.tm_sec = second;
    tm timeinfo = timeinfo1;
    time_t tt = toUTC(timeinfo);
    return std::chrono::system_clock::from_time_t(tt);
}