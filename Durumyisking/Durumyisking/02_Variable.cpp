#include <iostream>



int main()

{
	int i = 400;   // 초기화
	i = 200;      // 대입

	char ch = 'A';
	// int char = 0;   // 이미 예약되어있는 키워드는 식별자(이름)이 될 수가 없다.
	char CH = 'A';      // 대소문자는 구별이 된다.
	//char 가나다 = 'A';   // 이름은 대소문자, 숫자, 및 문자로만 구성이 가능하다
	char c_H = 'A';      // 대소문자와 함께 _는 이름으로 사용이 가능하다.

	// 문자유형
	// literal
	char ch_ = 'A'; // 이 코드에서 'A' 는 변하지 않는 글자임 _ch는 변하는 'A'라는건 연산으로 바꿀수가 없음

	// 부동 소수점 유형
	// 정수 실수 (소수 표현)
	float pi = 3.141592f;

	// true(1) false(0)
	bool T = true;
	bool F = false;


	signed int m_ch; // == int g_ch; 사실은 앞에 signed가 붙어있다. (소수는 불가능)
	unsigned int g_ch; // 양수만 쓸거임


	// 추가기능
	// 자료형 자동 유추
	auto num = 8888888888888888888; // 인텔리전스가 자동으로 데이터타입 유추해서 사용

	// 자료형 추론
	// 내가 변수 타입 기억 안날때 decltype(변수명) 넣으면 자료형을 return;
	decltype(ch) character;



	// 문자
	wchar_t wc = L'★'; // wchar_t는 2바이트 문자
	sizeof(wc);


	return 0;
}