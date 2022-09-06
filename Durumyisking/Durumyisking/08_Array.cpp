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

	arr[0] = 7;
	arr[3] = 100;
	// arr[4] = 500; 배열 크기외의 인덱스에 접근



	return 0;
}