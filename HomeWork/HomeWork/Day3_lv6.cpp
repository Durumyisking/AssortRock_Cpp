#include <iostream>


using namespace std;

// 전역변수
char flag;
char a;
char b;
char c;


// 1번함수
////////////////////////////////////////////
void ABC(char* _one, char* _two)
{
	cin >> *_one;
	cin >> *_two;

}
void OUTPUT(char* _one, char* _two)
{
	cout << *_one <<" "<< *_two;
}
////////////////////////////////////////////

// 12번함수
////////////////////////////////////////////
void Input()
{
	cin >> a;
	cin >> b;
	cin >> c;

}
void Process()
{
	if ('A' == a && 'B' == b && 'C' == c)
	{
		flag = 1;
	}
}
void Output()
{
	if (1 == flag)
	{
		cout << "ABC를찾았다" << endl;
	}
	else
	{
		cout << "못찾았다" << endl;
	}
}
////////////////////////////////////////////


int main()
{

	// Level6

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		char one;
		char two;
		ABC(&one, &two);
		OUTPUT(&one, &two);
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		char ch_1;
		char ch_2;
		char ch_3;
		cin >> ch_1;
		cin >> ch_2;
		cin >> ch_3;
		int ascii1 = ch_1;
		int ascii2 = ch_2;
		int ascii3 = ch_3;
		cout << ascii1 << endl << ascii2 << endl << ascii3 << endl;

	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int iInput;
		cin >> iInput;
		for (int i = 0; i < iInput; ++i)
		{
			for (int j = 1; j <= 5; ++j)
			{
				cout << j << " ";
			}
			cout << endl;
		}

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		char wc[6] = { '$', '@' , 'D' , 'A' , '9' , '#' };
		int arrAscii[6] = {wc[0], wc[1], wc[2],  wc[3],  wc[4],  wc[5]};
		for (size_t i = 0; i < sizeof(wc); ++i)
		{
			cout << wc[i] << ":" << arrAscii[i] << endl;
		}

	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		char wc[4] = {'B', 'T', 'K', 'A'};
		int iInput;
		cin >> iInput;
		for (int i = 0; i < iInput; ++i)
		{
			for (int j = 0; j < sizeof(wc); ++j)
			{
				cout << wc[j] << " ";
			}
			cout << endl;
		}
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		char ch;
		cin >> ch;
		if (65 <= ch && 90 >= ch)
		{
			cout << "대문자입니다." << endl;
		}
		else if (97 <= ch && 122 >= ch)
		{
			cout << "소문자입니다." << endl;
		}

	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;

		for (int i = 0; i < iInput; ++i)
		{
			for (int j = 0; j < iInput; ++j)
			{
				cout << "#";
			}
			cout << endl;
		}

	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char input;
		cin >> input;
		int result = input - '0';
		if (0 < result && 9 > result)
		{
			cout << result + 5 << endl;
		}
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		char ch;
		cin >> ch;
		if ('a' <= ch)
		{
			ch -= 32;
		}
		for (char i = 'A'; i <= ch; ++i)
		{
			cout << i;
		}
		cout << endl;
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char ch;
		cin >> ch;
		while ('a' > ch || 'z' < ch)
		{
			cin >> ch;
		}
		ch -= 32;
		cout << ch<< endl;
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		char ch1;
		char ch2;
		cin >> ch1;
		cin >> ch2;

		for (int i = 0; i < 4; ++i)
		{
			for (char j = ch1; j <= ch2; ++j)
			{
				cout << j <<" ";
			}
			cout << endl;
		}
	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;
		Input();
		Process();
		Output();
	}


	// 13번
	{
		cout << "///////////////13번///////////////" << endl;
		int a;
		int b;
		int c;
		cin >> a;
		cin >> b;
		while (b <= a)
		{
			cout << "b다시입력" << endl;
		}
		cin >> c;

		for (int i = 0; i < c; ++i)
		{
			for (int j = a; j <= b; ++j)
			{
				cout << j << " ";
			}
			cout << endl;
		}

	}


	return 0;
}