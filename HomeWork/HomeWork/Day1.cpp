#include <iostream>

int main()
{

	// Level 2

	// 1번
	std::cout << "1주동안의 운동 횟수를 입력하시오 : ";
	int iInput;
	std::cin >> iInput;
	std::cout << "멋지군요!! 칭찬합니다." << std::endl;

	// 2번
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> iInput;
	std::cout << iInput << " 입력하셨군요" << std::endl;

	// 3번
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> iInput;
	std::cout << iInput << " "<< iInput << " " << iInput << std::endl;

	// 4번
	int a, b, c;
	std::cout << "a를 입력하시오 : ";
	std::cin >> a;
	std::cout << "b를 입력하시오 : ";
	std::cin >> b;
	std::cout << "c를 입력하시오 : ";
	std::cin >> c;
	std::cout << a << " " << a << " " << a << std::endl;
	std::cout << b << " " << b << " " << b << std::endl;
	std::cout << c << " " << c << " " << c << std::endl;

	// 5번
	int num1, num2;
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;
	std::cout << "두 숫자의 차는 " << num1 - num2 << " 입니다." << std::endl;

	// 6번
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;
	std::cout << num1 << "+" << num2 << "=" << num1 + num2 << std::endl;
	std::cout << num1 << "*" << num2 << "=" << num1 * num2 << std::endl;
	std::cout << num1 << "/" << num2 << "=" << num1 / num2 << std::endl;

	// 7번
	std::cout << "a를 입력하시오 : ";
	std::cin >> a;
	std::cout << "b를 입력하시오 : ";
	std::cin >> b;
	if (a > b)
	{
		std::cout << "a가 b보다 크다." << std::endl;
	}
	else
	{
		std::cout << "b가 a보다 크거나 같다." << std::endl;
	}

	// 8번
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;

	if (num1 > num2)
	{
		std::cout << num1 << num1 << num1 << num1 << std::endl;
	}
	else if (num2 > num1)
	{
		std::cout << num2 << num2 << num2 << num2 << std::endl;
	}

	// 9번
	std::cout << "a를 입력하시오 : ";
	std::cin >> a;
	std::cout << a++ << " 입력함" << std::endl;
	std::cout << "a++을 수행하면" << a << "이 됩니다." << std::endl;

	// 10번
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> iInput;
	if (iInput > 3)
	{
		iInput++;
		std::cout << iInput << std::endl;
	}
	else
	{
		iInput--;
		std::cout << iInput << std::endl;
	}

	// 11번
	int num;
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> num;

	if (num > 0)
	{
		std::cout << "###" << std::endl << "###" << std::endl << "###" << std::endl;
	}
	else if (num < 0)
	{
		std::cout << "$$$" << std::endl << "$$$" << std::endl;
	}
	
	// 12번
	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> c;

	if (a + b + c >= a * b * c)
	{
		std::cout << "행운의 수" << std::endl;
	}
	else
	{
		std::cout << "소소한 수" << std::endl;
	}

	return 0;



	// Level2.5
	
	// 1번
	std::cout << "WWW.\"LJJ\"CODING.CO.KR" << std::endl;

	// 2번
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;
	if (num1 == num2)
	{
		std::cout << "같습니다" << std::endl;
	}
	else
	{
		std::cout << "다릅니다" << std::endl;
	}

	// 3번
	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> c;

	std::cout << "첫번째 숫자를 입력하세요 : " << a << std::endl;
	std::cout << "두번째 숫자를 입력하세요 : " << b << std::endl;
	std::cout << "세번째 숫자를 입력하세요 : " << c << std::endl;

	// 4번
	int d;

	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> c;
	std::cout << "네번째 숫자를 입력하세요 : ";
	std::cin >> d;
	std::cout << "a+b=" << a + b << std::endl;
	std::cout << "c+d=" << c + d << std::endl;
	std::cout << "ALL SUM" << a + b + c + d << std::endl;

	// 5번
	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> c;
	if (a == b)
	{
		if (b == c)
		{
			std::cout << "만세" << std::endl;
		}
	}

	// 6번
	int b1, b2, b3, b4;
	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> b1;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b2;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> b3;
	std::cout << "네번째 숫자를 입력하세요 : ";
	std::cin >> b4;
	if (b1 > b2)
	{
		if (b1 > b3)
		{
			if (b1 > b4)
			{
				std::cout << "b1이 가장 크다" << std::endl;
			}
		}
	}


	// 7번
	int avg;
	std::cout << "첫번째 숫자를 입력하세요 : ";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요 : ";
	std::cin >> b;
	std::cout << "세번째 숫자를 입력하세요 : ";
	std::cin >> c;
	std::cout << "네번째 숫자를 입력하세요 : ";
	std::cin >> d;
	avg = (a + b + c + d) / 4;
	if (avg > a)
	{
		std::cout << a << "<" << avg << std::endl;
	}
	else if (avg < a)
	{
		std::cout << a << ">" << avg << std::endl;
	}
	else if (avg == a)
	{
		std::cout << a << "==" << avg << std::endl;
	}

	if (avg > b)
	{
		std::cout << b << "<" << avg << std::endl;
	}
	else if (avg < b)
	{
		std::cout << b << ">" << avg << std::endl;
	}
	else if (avg == b)
	{
		std::cout << b << "==" << avg << std::endl;
	}


	if (avg > c)
	{
		std::cout << c << "<" << avg << std::endl;
	}
	else if (avg < c)
	{
		std::cout << c << ">" << avg << std::endl;
	}
	else if (avg == c)
	{
		std::cout << c << "==" << avg << std::endl;
	}

	if (avg > d)
	{
		std::cout << d << "<" << avg << std::endl;
	}
	else if (avg < d)
	{
		std::cout << d << ">" << avg << std::endl;
	}
	else if (avg == d)
	{
		std::cout << d << "==" << avg << std::endl;
	}

	// 8번
	int sub = 0;
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;
	sub = num1 - num2;
	if (sub < 0)
	{
		sub *= -1;
	}
	if (sub > 5)
	{
		std::cout << "멀다" << std::endl;
	}
	else
	{
		std::cout << "가깝다" << std::endl;
	}

	// 9번
	std::cout << "num1을 입력하세요 : ";
	std::cin >> num1;
	std::cout << "num2을 입력하세요 : ";
	std::cin >> num2;
	if (num1 + num2 > 10)
	{
		std::cout << "합만세";
	}
	if (num1 * num2 > 10)
	{
		std::cout << "곱만세";
	}

	// 10번
	int n1, n2, n3, n4, n5, n6, n7;
	std::cout << "숫자 7개를 입력하세요 : ";
	std::cin >> n1;
	std::cin >> n2;
	std::cin >> n3;
	std::cin >> n4;
	std::cin >> n5;
	std::cin >> n6;
	std::cin >> n7;
	std::cout << n4 << " " << n5 << " " << n6 << " " << n7  << std::endl;

	// 11번
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "#";
	}

}