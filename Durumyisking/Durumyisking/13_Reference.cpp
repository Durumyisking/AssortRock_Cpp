#include <iostream>


using namespace std;

int main()
{
	// reference
	// 참조연산자
	int num = 200;
	int* pNum = &num; // 초기화시 반드시 다른 값을 참조해야함

	// 참조한다는것은
	// 주소에다가 변수이외의 이름을 더 붙여준다는것
	int& num2 = num; // 여기서는 200을담고있는 변수 num에 num2라는 이름을 추가로 붙여줌
	num = 300;
	*(pNum) = 500;
	num2 = 800;



	return 0;
}