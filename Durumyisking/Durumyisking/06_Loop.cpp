#include <iostream>

// 전역변수
int gData = 0;

// std : standard
// std라이브러리를 std::로 참조안하고 using 키워드를 사용해 항상 참조하겠다.
using namespace std;

// namespace 키워드
namespace MyLib
{
	int Pos;
	int Dir;
}

int main()
{

	// for문
	int x = 0;
	for (x = 1; x < 10; ++x)
	{
		std::cout << "Hello World!\n";
		if (x == 5)
		{
			// 반복문 탈출
			break;
		}
		if (x == 7)
		{
			// 특정 조건에서 스킵
			continue;
		}
	}

	// while문
	int y = 0;
	while (y < 10)
	{
		std::cout << "Hello World!\n";
		y++;
	}

	// do - while문
	// 조건이 거짓이어도 do 코드블럭 내의 코드는 한번 실행
	// 조건이 참이면 무한반복
	int z = 0;
	do
	{
		std::cout << "Hello World!\n";
		z++;
	} while (z < 10);

	// 향상된 for문
	int arr[5] = {0,1,2,3,4};
	for (int indexValue : arr)
	{
		// 이렇게하면 indexValue에 arr의 값을 인덱스0부터 순회함
		cout << indexValue << endl;
	}


	// 전역변수는 어디서 쓰나 다 똑같은놈
	gData = 5;
	{
		gData = 8;
	}

	// namespace로 만든 라이브러리 사용법
	int myDir = MyLib::Dir;



	return 0;
}