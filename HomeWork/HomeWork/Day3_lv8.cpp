#include <iostream>

using namespace std;

int g_input1;
int g_input2;
int g_arr[3][4] = {};
int g_arr2[2][3] = {};

char g_charr1[5] = { 'B','D','5','Q','A' };
char g_charr2[5] = { 'Q','E','R','E','F' };



char g_charinput;


// 3번함수
////////////////////////////////////////////
void input_3()
{
	cin >> g_input1;
	cin >> g_input2;
}
void output_3()
{
	for (int i = 5; i <= g_input1 + g_input2; ++i)
	{
		cout << i <<" ";
	}
	cout << endl;
}
////////////////////////////////////////////

// 6번함수
////////////////////////////////////////////
void input_6()
{
	int iInput = 0;
	cin >> iInput;
	for (size_t i = 0; i < sizeof(g_arr) / sizeof(g_arr[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_arr[0]) / 4; ++j)
		{
			g_arr[i][j] = iInput++;
		}
	}
}
void process_6()
{
	for (size_t i = 0; i < sizeof(g_arr) / sizeof(g_arr[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_arr[0]) / 4; ++j)
		{
			++g_arr[i][j];
		}
	}
}
void output_6()
{
	for (size_t i = 0; i < sizeof(g_arr) / sizeof(g_arr[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_arr[0]) / 4; ++j)
		{
			cout << g_arr[i][j] << " ";
		}
		cout << endl;
	}
}
////////////////////////////////////////////


// 7번함수
////////////////////////////////////////////
void input_7()
{
	cin >> g_charinput;
}
void output_7()
{
	if (65 <= g_charinput && 90 >= g_charinput)
	{
		for (size_t i = 0; i < sizeof(g_charr2); ++i)
		{
			cout << g_charr2[i];
		}
	}
	else if (97 <= g_charinput && 122 >= g_charinput)
	{
		for (size_t i = 0; i < sizeof(g_charr1); ++i)
		{
			cout << g_charr1[i];
		}
	}
	else if (48 <= g_charinput && 57 >= g_charinput)
	{
		for (char i = 72; i >= 65; --i)
		{
			cout << i;
		}
	}
	cout << endl;
}
////////////////////////////////////////////



// 9번함수
////////////////////////////////////////////
void input_9()
{
	for (size_t i = 0; i < sizeof(g_arr2) / sizeof(g_arr2[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_arr2[0]) / 4; ++j)
		{
			cin >> g_arr2[i][j];
		}
	}
}
void output_9(int _iSum)
{
	cout << _iSum << endl;
}
void process_9()
{
	int iSum = 0;
	for (size_t i = 0; i < sizeof(g_arr2) / sizeof(g_arr2[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_arr2[0]) / 4; ++j)
		{
			iSum += g_arr2[i][j];
		}
	}
	output_9(iSum);
}
////////////////////////////////////////////

// 11번함수
////////////////////////////////////////////
void starBox()
{
	for (int i = 1; i <= 20; ++i)
	{
		if (0 != i % 2)
		{
			cout << i;
		}
	}
	cout << endl;
}
void macDoll()
{
	for (char i = 'H'; i >= 'A'; --i)
	{
		cout << i;
	}
	cout << endl;
}

void copyBean()
{
	for (int i = -5; i <= 5; ++i)
	{
		cout << i;
	}
	cout << endl;
}

////////////////////////////////////////////

int main()
{

	// Level8

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int n = 0;
		int i = 1;
		cin >> n;
		while(true)
		{
			cout << i;
			if (i == n)
				break;
			++i;
		}
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int arr[6];
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
		}
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			if (7 == arr[i])
			{
				break;
			}
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		input_3();
		output_3();
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[6];
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
		}
		for (size_t i = (sizeof(arr) / 4) - 1; i > 0; --i)
		{
			cout << arr[i] << " ";

			if (7 == arr[i])
			{
				break;
			}
		}
		cout << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int arr[6] = { 3,4,1,6,7,5 };
		int i = 0;
		while (i < 6)
		{
			cout << arr[i++] << " ";
		}
		cout << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		input_6();
		process_6();
		output_6();
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		input_7();
		output_7();
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char ch[6] = {'#', '_', '#', '_', '#', '#'};
		for (size_t i = 0; i < sizeof(ch); ++i)
		{
			if ('#' == ch[i])
			{
				cout << "샵" << endl;
			}
			else if ('_' == ch[i])
			{
				cout << "무" << endl;
			}
		}
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		input_9();
		process_9();
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		int arr[3][4] =
			{ {4,3,1,1}
			,{3,1,2,1}
			,{0,0,1,2} };
		int iInput;
		int iCount = 0;
		cin >> iInput;

		
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i )
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				if (iInput == arr[i][j])
				{
					++iCount;
				}
			}
		}
		cout << iCount << "개 존재합니다" << endl;
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		if (3500 <= iInput && 5000 >= iInput)
		{
			starBox();
		}
		else if (2500 <= iInput && 3500 >= iInput)
		{
			macDoll();
		}
		else
		{
			copyBean();
		}


	}



	return 0;
}