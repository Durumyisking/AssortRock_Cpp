 #include <iostream>


using namespace std;

// 2���Լ�
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

// 4���Լ�
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

// 5���Լ�
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

// 9���Լ�
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

// 10���Լ�
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

// 11���Լ�
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

// 12���Լ�
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

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
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

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		cout << getChar() << endl;
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
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

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
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

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
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

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
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

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
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

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
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

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		unsigned int iInput = 0;
		INPUT(&iInput);
		CountDown(&iInput);
	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;
		cout << YesOrNo() << endl;
	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;
		cout << scoring() << endl;
	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;
		cout << aToz() <<endl;
	}


	return 0;
}