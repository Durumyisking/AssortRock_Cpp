#include <iostream>

using namespace std;

// unsigned int를 SIZE라는 이름으로 사용하겠다.
typedef unsigned int SIZE;

// 커스텀 함수
// 반환값 함수명(전달인자)
void PrintNumber()
{
	// main클래스에 함수 선언시 여기로 진입
	for (size_t i = 0; i < 10; ++i)
	{
		cout << i;
	}

	return; // void형은 반환이 필요없기때문에 이놈이 생략되어있음
}

// 함수 오버로딩
// 위의 함수와 이름이 같으나 매개인자가 달라서 선언 가능
void PrintNumber(int num)
{
	cout << num;
}

// 위의 함수와 이름이 같으나 반환자료형이 달라서 선언 가능
// _a, _b, result만있어서 12바이트 같지만
// 사실 temp에 결과값이 저장되고 그 값을 main으로 넘겨주기때문에
// 16바이트가 사용된다.
int add(int _a, int _b)
{
	int result = _a + _b;
	return result;
}

// 함수 템플릿
// 여기서 T는 자료형 type
template <typename T>
T add(T a, T b)
{
	return a + b;
}

// 템플릿 특수화
template <>
float add(float a, float b)
{
	// 이럼 add함수를 반환형 float 인자 (float, float) 쓸때는 여기로 옴
	// 안쓰는 기능임ㅋ
	return (int)(a + b);
}

	
int main()
{
	// 함수 실행
	PrintNumber();

	SIZE d = -2; // unsigned int에 음수 대입시 -1 비트를 양수일때로 읽음

	int result = add(5, 3);

	
	// 템플릿
	char ch = static_cast<char>(65); // 우리가 사용하는 static_cast도 <>안에 T가 들어가있음

	// add<T>(매개인자)
	float	fSum = add<float>(3.0f, 0.14159f);
	int		iSum = add<int>(5, 5);


	return 0;

}