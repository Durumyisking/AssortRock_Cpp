#include <iostream>

// 배열

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;


	std::cout << a << b << c << d<<std::endl;

	int arr[4] = { 1,2,3,4 };
	// 인덱스 : 접근하고싶은 위치 arr[인덱스]
	arr[0] = 7;
	arr[3] = 100;
	// arr[4] = 500; 배열 크기외의 인덱스에 접근

	// 배열은 반복문으로 쉽게 사용이 가능하다.
	for (int i = 0; i < 4; ++i)
	{
		std::cout << arr[i] << std::endl;
	}


	return 0;
}