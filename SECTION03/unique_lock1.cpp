#include <mutex>

std::mutex m;

int main()
{
	// lock_guard 를 사용하는 2가지 방법
	// 1. 생성자에서 lock 획득
	{
    	std::lock_guard<std::mutex> lg(m);
	
	}
	
	// 2. 이미 lock 획득한 상태의 뮤텍스 관리
	if ( m.try_lock() )
	{
		std::lock_guard<std::mutex> lg(m, std::adopt_lock);
	
	}	
}



