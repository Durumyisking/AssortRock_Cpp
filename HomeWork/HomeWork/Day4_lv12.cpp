#include <iostream>


using namespace std;


char g_arr[8] = { 'M', 'I',  'N',  'Q',  'U',  'E',  'S',  'T' };

// 6���Լ�
////////////////////////////////////////////
int Length(char _ch)
{
	for (int i = 0; i < sizeof(g_arr); ++i)
	{
		if (_ch == g_arr[i])
		{
			return i;
		}
	}
}
////////////////////////////////////////////


int main()
{


	// Level12

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		char ch[255];
		cin >> ch;
		for (size_t k = 0; k < 5; ++k)
		{
			for (size_t i = 0; i < sizeof(ch); ++i)
			{
				if ('\0' == ch[i])
				{
					break;
				}
				cout << ch[i];
			}
			cout << endl;
		}
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		char ch1[255];
		char ch2[255];
		int ch1size = 0;
		int ch2size = 0;
		cin >> ch1 >> ch2;
		for (size_t i = 0; i < sizeof(ch1); ++i)
		{
			if ('\0' == ch1[i])
				break;
			++ch1size;
		}
		for (size_t i = 0; i < sizeof(ch2); ++i)
		{
			if ('\0' == ch2[i])
				break;
			++ch2size;
		}
		cout << ch1size << " " << ch2size << endl;
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout << iInput;
			}
			iInput--;
			cout << endl;
		}
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < iInput; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				cout << j;
			}
			cout << endl;
		}
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int iInput = 0;
		int arr[3][4] ={};
		int iIdx = 2;
		cin >> iInput;
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = iIdx; j < sizeof(arr[0])/4; j++)
			{
				arr[i][j] = iInput++;
			}
			--iIdx;

		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0])/4; ++j)
			{
				if (0 == arr[i][j])
					cout << " ";
				else
					cout << arr[i][j] ;
			}
			cout << endl;
		}
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		for (int i = 0; i < 3; ++i)
		{
			char chInput;
			cin >> chInput;
			cout << chInput << "=" << Length(chInput) << endl;
		}
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		char chInput[11] = {};
		int iArrSize = 0;
		cin >> chInput;
		for (size_t i = 0; i < sizeof(chInput); ++i)
		{
			if ('\0' == chInput[i])
			{
				break;
			}
			++iArrSize;
		}

		for (int k = 0; k < 3; ++k)
		{
			char chSearch;
			int iCount = 0;
			cin >> chSearch;
			for (int i = 0; i < iArrSize; ++i)
			{
				if (chSearch == chInput[i])
					++iCount;
			}
			cout << chSearch << "=" << iCount << endl;

		}
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		char strarr[9] = { 'D', 'A',  'T',  'A',  'P',  'O',  'W',  'E',  'R' };
		int a;
		int b;
		cin >> a >> b;
		while (a > b)
		{
			cout << "1�� �Է°��� 2���Է°����� Ŀ���մϴ� �ٽ� �Է��ϼ���" << endl;
			cin >> a >> b;
		}
		char strarr2[9] = {};
		int istr2idx = 0;
		for (int i = a; i <= b; ++i)
		{
			strarr2[istr2idx] = strarr[i];
			++istr2idx;
		}
		for (int i = 0; i < sizeof(strarr2); ++i)
		{
			if ('\0' == strarr2[i])
				break;

			cout << strarr2[i];
		}
		cout << endl;
	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		int arr[3][3] = {};
		char chInput;
		cin >> chInput;

		int iInput = 6;

		if ('0' <= chInput && '9' >= chInput)
		{
			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			{
				for (size_t j = i; j < sizeof(arr[0]) / 4; ++j)
				{
					arr[i][j] = iInput--;
				}
			}
		}
		if ('A' <= chInput && 'Z' >= chInput)
		{
			for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			{
				for (size_t j = 0; j <= i; ++j)
				{
					arr[i][j] = iInput--;
				}
			}
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				if (0 == arr[i][j])
					cout << " ";
				else
					cout << arr[i][j];
			}
			cout << endl;
		}


	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;
		int iInput;
		char chInput;
		cin >> iInput;
		cin >> chInput;
		char arr[5][5] = {};

		for (int i = 4; i >= 0; --i)
		{
			arr[iInput-1][i] = chInput++;
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]); ++j)
			{
				if ('\0' == arr[i][j])
					cout << '0';
				else
					cout << arr[i][j];
			}
			cout << endl;
		}
	}



	return 0;
}