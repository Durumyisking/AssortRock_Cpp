#include <iostream>


using namespace std;

// 7번함수
////////////////////////////////////////////
void Magic_7(int arr[][3], size_t _iSize)
{
	int iCount = 1;
	for (size_t i = 0; i < _iSize; ++i)
	{
		for (size_t j = i; j < _iSize; ++j)
		{
			arr[i][j] = iCount;
			++iCount;
		}
	}
}
void output_7(int arr[][3], size_t _iSize)
{
	for (size_t i = 0; i < _iSize; ++i)
	{
		for (size_t j = 0; j < _iSize; ++j)
		{
			if (0 == arr[i][j])
				cout << " ";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}
////////////////////////////////////////////


// 8번함수
////////////////////////////////////////////
void CountLine_8(char arr[][10], size_t _iSize)
{
	int arrCount[3] = {};

	for (size_t i = 0; i < _iSize; ++i)
	{
		for (size_t j = 0; j < sizeof(arr[0]); ++j)
		{
			if ('\0' == arr[i][j])
				break;
			++arrCount[i];
		}
	}

	for (size_t i = 0; i < _iSize; ++i)
	{
		cout << arrCount[i] << "=" << arr[i] << endl;
	}
	
}
////////////////////////////////////////////

int main()
{

	// Level14

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int a, b;
		int start = 0;
		cin >> a >> b;
		start = a;
		while (start <= b)
		{
			cout << start++ << " ";
		}
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int iInput = 0;
		int i = 0;


		cin >> iInput;
		while (i != 3)
		{
			int j = 0;
			while(j != 5)
			{
				cout << iInput;
				++j;
			}
			cout << endl;
			++i;
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		char chInput;
		char charr[3][3] = {};
		cin >> chInput;
		int i = 2;
		while (0 <= i)
		{
			int j = 0;
			while (j <= 2 - i)
			{
				// i = 2 j = 0		i = 1 j = 0,1	i = 0 j = 0,1,2
				charr[i][j] = chInput++;
				++j;
			}
			--i;
		}
		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[0]); ++j)
			{
				if ('\0' == charr[i][j])
					cout << " ";
				else
					cout << charr[i][j];
			}
			cout << endl;
		}
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[6] = {};
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
		}
		for (size_t i = 0; i < sizeof(arr) / 4 - 1; ++i)
		{
			for (size_t j = i + 1; j < sizeof(arr) / 4; ++j)
			{
				if (arr[i] < arr[j])
				{
					int iTemp = arr[i];
					arr[i] = arr[j];
					arr[j] = iTemp;
				}
			}
		}
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout<<  arr[i] << " ";
		}
		cout << endl;

	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		char strInput[255];
		int iSize = 0;
		cin >> strInput;
		for (size_t i = 0; i < sizeof(strInput); ++i)
		{
			if ('\0' == strInput[i])
				break;
			++iSize;
		}
		for (size_t i = 0; i < iSize - 1; ++i)
		{
			for (size_t j = i + 1; j < iSize; ++j)
			{
				if (strInput[i] > strInput[j])
				{
					char chTemp = strInput[i];
					strInput[i] = strInput[j];
					strInput[j] = chTemp;
				}
			}
		}
		for (size_t i = 0; i < iSize; ++i)
		{
			cout << strInput[i];
		}
		cout << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		char charr[3][9] = {
		{"BBQWORLD"},
		{ "KFCAPPLE" } ,
		{ "LOT" } };
		char chInput;
		int iCount = 0;
		cin >> chInput;

		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[0]); ++j)
			{
				if ('\0' == charr[i][j])
					continue;
				else if (chInput == charr[i][j])
					++iCount;
			}
		}
		cout << iCount << endl;

	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int arr[3][3] = { };
		Magic_7(arr, sizeof(arr) / sizeof(arr[0]));
		output_7(arr, sizeof(arr) / sizeof(arr[0]));
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char strarr[3][10] = {
			{},
			{},
			{}
		};

		for (int i = 0; i < 3; ++i)
		{
			cin >> strarr[i];
		}
		CountLine_8(strarr , sizeof(strarr) / sizeof(strarr[0]));

	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		char charr[4][5] = {};
		int iFlag = 0;
		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			cin >> charr[i];
		}
		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[0]); ++j)
			{
				if ('A' == charr[i][j])
				{
					iFlag |= 1;
				}
				else if ('B' == charr[i][j])
				{
					iFlag |= 2;
				}
			}
		}
		switch (iFlag)
		{
		case 1: case 2:
			cout << "중발견" << endl;
			break;
		case 3:
			cout << "대발견" << endl;
			break;
		default:
			cout << "미발견" << endl;
			break;
		}

	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char charr[2][6] = {};
		char chStorage[12] = {};
		int iCount[2] = {};

		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			cin >> charr[i];
		}
		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[0]); ++j)
			{
				if ('\0' == charr[i][j])
				{
					break;
				}
				++iCount[i];
			}
		}

		for (int j = 0; j < iCount[0]; ++j)
		{
			chStorage[j] = charr[0][j];
		}
		for (int j = 0; j < iCount[1]; ++j)
		{
			chStorage[j+iCount[0]] = charr[1][j];
		}
		
		cout << chStorage << endl;
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		char charr[2][6] = {"DATAW", "BBQK"};
		int iInput = 0;
		int iSize[2] = {};
		for (size_t i = 0; i < sizeof(charr)/ sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[i]); ++j)
			{
				if ('\0' == charr[i][j])
				{
					break;
				}
				++iSize[i];
			}
		}
		cin >> iInput;
		if (0 == iInput % 2)
		{
			for (size_t i = 0; i < iSize[1] - 1; ++i)
			{
				for (size_t j = i + 1; j < iSize[1]; ++j)
				{
					if (charr[1][i] > charr[1][j])
					{
						char chTemp = charr[1][i];
						charr[1][i] = charr[1][j];
						charr[1][j] = chTemp;
					}
				}
			}
		}
		else
		{
			for (size_t i = 0; i < iSize[0] - 1; ++i)
			{
				for (size_t j = i + 1; j < iSize[0]; ++j)
				{
					if (charr[0][i] > charr[0][j])
					{
						char chTemp = charr[0][i];
						charr[0][i] = charr[0][j];
						charr[0][j] = chTemp;
					}
				}
			}
		}
		for (size_t i = 0; i < sizeof(charr) / sizeof(charr[0]); ++i)
		{
			cout << charr[i];
			cout << endl;
		}

	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;
		char charr[3][6] = { "POTIO", "ABCDE", "YOURE" };
		int a, b;
		cin >> a >> b;
		while (a > b)
		{
			cout << "다시입력해(a <b)";
			cin >> a >> b;
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = a; j <= b; ++j)
			{
				cout << charr[i][j];
			}
		}
		cout << endl;
	}

	// 13번
	{
		cout << "///////////////13번///////////////" << endl;
		char ch_1, ch_2;
		cin >> ch_1 >> ch_2;
		char* pch_1 = &ch_1;
		char* pch_2 = &ch_2;
		char chTemp;
		chTemp = *pch_1;
		*pch_1 = *pch_2;
		*pch_2 = chTemp;
		cout << ch_1 << " " << ch_2 << endl;
	}

	// 14번
	{
		cout << "///////////////14번///////////////" << endl;
		char charr[2][8] = { };
		cin >> charr[0];
		cin >> charr[1];

		int iCount = 0;
		for (size_t i = 0; i < sizeof(charr[0]); ++i)
		{
			if (charr[0][i] != charr[1][i])
				++iCount;
		}
		cout << iCount <<endl;
	}


	return 0;
}