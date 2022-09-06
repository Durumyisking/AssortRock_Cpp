#include <iostream>

using namespace std;

// unsigned int를 SIZE라는 이름으로 사용하겠다.
typedef unsigned int SIZE;

// 커스텀 함수
void PrintNumber()
{
	// main클래스에 함수 선언시 여기로 진입
	for (size_t i = 0; i < 10; ++i)
	{
		cout << i;
	}
}

int main()
{
	// 함수 실행
	PrintNumber();

	SIZE d = -2; // unsigned int에 음수 대입시 -1 비트를 양수일때로 읽음

	return 0;

}