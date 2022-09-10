 #include <iostream>


using namespace std;

// 2번함수
////////////////////////////////////////////
char getChar()
{
	char chInput1;
	char chInput2;
	cin >> chInput1;
	cin >> chInput2;

	return 	chInput1 > chInput2 ? chInput1 : chInput2;
}
////////////////////////////////////////////

// 4번함수
////////////////////////////////////////////
void printData(int value)
{
	cout << value << endl;
}
void even(int value)
{
	value *= 2;
	printData(value);
}
void odd(int value)
{
	value -= 10;
	printData(value);
}
////////////////////////////////////////////

// 5번함수
////////////////////////////////////////////
int GOP()
{
	int iInput1;
	int iInput2;
	int iResult = 0;
	cin >> iInput1;
	cin >> iInput2;

	iResult = iInput1 * iInput2;
	return iResult;
}
int SUM()
{
	int iInput1;
	int iInput2;
	int iResult = 0;
	cin >> iInput1;
	cin >> iInput2;

	iResult = iInput1 + iInput2;
	return iResult;
}
////////////////////////////////////////////

// 9번함수
////////////////////////////////////////////
void INPUT(unsigned int* _pInput)
{
	cin >> *_pInput;
}
void CountDown(unsigned int* _pInput)
{
	while (*_pInput >= 1)
	{
		cout << (*_pInput)-- << " ";
	}
	cout << endl;
}
////////////////////////////////////////////

// 10번함수
////////////////////////////////////////////
int YesOrNo()
{
	int input;
	cin >> input;
	if (0 == input % 3)
	{
		return 7;
	}
	else if (1 == input % 3)
	{
		return 35;
	}
	else
	{
		return 50;
	}
}
////////////////////////////////////////////

// 11번함수
////////////////////////////////////////////
char scoring()
{
	int iInput = 0;
	cin >> iInput;
	if (90 < iInput)
	{
		return 'A';
	}
	else if (80 < iInput)
	{
		return 'B';
	}
	else if (70 < iInput)
	{
		return 'C';
	}
	else
	{
		return 'D';
	}

}
////////////////////////////////////////////

// 12번함수
////////////////////////////////////////////
char aToz()
{
	char chInput;
	cin >> chInput;
	if (0 > (chInput - 78))
	{
		return 'A';
	}
	else
	{
		return 'Z';
	}
}
////////////////////////////////////////////

int main()
{

	// Level10

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int iInput = 0;
		int iArrInput = 1;
		int arr[4][4] = {};
		cin >> iInput;
		if (0 == iInput % 2)
		{
			for (int i = 0; i < 4; ++i)
			{
				arr[i][i] = iArrInput++;
			}
		}
		else
		{
			int iJIdx = sizeof(arr) / sizeof(arr[0]) - 1;
			for (int i = 0; i < 4; ++i)
			{
				arr[i][iJIdx-i] = iArrInput++;
			}
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		cout << getChar() << endl;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int arr[3][3] = {};
		int iInput = 0;
		cin >> iInput;
		if (1 == iInput % 5)
		{
			int iArrInput = 9;
			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			{
				for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
				{
					arr[j][i] = iArrInput--;
				}
			}
		}
		else if (2 == iInput % 5)
		{
			int iArrInput = 9;
			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			{
				for (int j = sizeof(arr[0]) / 4 - 1; j >= 0; --j)
				{
					arr[i][j] = iArrInput--;
				}
			}
		}
		else
		{
			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			{
				for (size_t j = 0; j < sizeof(arr[0])/4; ++j)
				{
					arr[j][i] = i + j + 10;
				}
			}
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int a;
		int b;
		cin >> a;
		cin >> b;
		if (0 == (a / b) % 2)
		{
			even(a / b);
		}
		else
		{
			odd(a / b);
		}
		printData(a + b);
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int a = GOP();
		int b = SUM();

		if (a > b)
		{
			cout << "GOP>SUM" << endl;
		}
		else if (a < b)
		{
			cout << "GOP<SUM" << endl;
		}
		else
		{
			cout << "GOP==SUM" << endl;
		}		
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int arr[4][4] = {};
		int iarrInput = 1;
		for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; --i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				arr[j][i] = iarrInput++;
			}
		}
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j] <<" ";
			}
			cout << endl;
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int arr[3][4] = {};
		int iarrInput = 1;
		for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; --i)
		{
			for (int j = sizeof(arr[0]) / 4 - 1; j >= 0; --j)
			{
				arr[i][j] = iarrInput++;
			}
		}
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			arr[i][iInput] = 0;
		}
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		int arr[4][4] = {};
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				
				if (0 == arr[i][j])
				{
					cout << "!";
				}
				else if (0 == arr[i][j] % 2)
				{
					cout << "#";
				}
				else if (1 == arr[i][j] % 2)
				{
					cout << "@";
				}
			}
			cout << endl;
		}
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		unsigned int iInput = 0;
		INPUT(&iInput);
		CountDown(&iInput);
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		cout << YesOrNo() << endl;
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		cout << scoring() << endl;
	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;
		cout << aToz() <<endl;
	}


	return 0;
}