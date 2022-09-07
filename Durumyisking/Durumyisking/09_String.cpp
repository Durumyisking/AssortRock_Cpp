#include <iostream>

using namespace std;

// 문자열 길이 구하기
// strlen함수
int myStrLen()
{
	int len = 0;
	char str[6] = "Hello";

	for (size_t i = 0; i < 6; ++i)
	{
		if (str[i] == '\0')	 // 문자열 배열에 있는 null문자를 만나면
		{
			len = i;
			// break; 반복문을 종료해도되고
			return len; // 이걸로 함수 종료해도됨
		}
	}
	return len;
}


// 문자열
int main()
{
	// 우리가 숫자 여러개를
	// int arr[10] 이렇게 선언하듯
	// 문자가 여러개 붙은 문자열은 char str[256] = {'A', 'B', 'C'}; 이렇게 선언
	// 그런데 번거로우니까
	char str[6] = "Hello"; // 이렇게 선언한다.
	// 근데 Hello는 5글자인데 왜 크기를 6으로 선언하나요?
	// 마지막에 문자열의 끝을 날리는 '\0'(null) 문자를 포함하기 때문
	// 따라서 char str[6] ={'h', 'e', 'l', 'l', 'o', '\0'};랑 같음

	// std에 이런 키워드도 있지만 나중에 쓰자~
	// std::string str2 = "ImHappy";

	




	return 0;
}