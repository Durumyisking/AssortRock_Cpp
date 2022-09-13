#include <iostream>


using namespace std;

// 1번함수
////////////////////////////////////////////


////////////////////////////////////////////


int main()
{

	// Level15

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int vect[7] = {3,5,1,1,2,3,2};
		int arr[4] = {};
		int arrCount[4] = {};
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
		}

		for (size_t i = 0; i < sizeof(vect) / 4; ++i)
		{
			if (arr[0] == vect[i])
			{
				++arrCount[0];
			}
			if (arr[1] == vect[i])
			{
				++arrCount[1];
			}
			if (arr[2] == vect[i])
			{
				++arrCount[2];
			}
			if (arr[3] == vect[i])
			{
				++arrCount[3];
			}
		}
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout << arr[i] << "=" << arrCount[i] << "개" << endl;
		}
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int arr[6] = { 10,50,40,20,30,40 };
		int arrInput[6] = {};
		int arrCount[6] = {};
		for (size_t i = 0; i < sizeof(arrInput) / 4; ++i)
		{
			cin >> arrInput[i];
		}
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			for (size_t j = 0; j < sizeof(arrInput) / 4; ++j)
			{
				if (arr[i] > arrInput[j])
				{
					++arrCount[j];
				}
			}
		}
		for (size_t i = 0; i < sizeof(arrCount) / 4; ++i)
		{
			cout << arrInput[i] << "=" << arrCount[i] << "개" << endl;
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		char charr[2][6] = {};
		int arrCount[2] = {};
		cin >> charr[0] >> charr[1];
		for (int i = 0; i < 6; ++i)
		{
			if ('\0' != charr[0][i])
			{
				++arrCount[0];
			}
			if ('\0' != charr[1][i])
			{
				++arrCount[1];
			}
		}
		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < arrCount[k] - 1; ++i)
			{
				for (int j = i + 1; j < arrCount[k]; ++j)
				{
					if (charr[k][i] > charr[k][j])
					{
						char chTemp = charr[k][i];
						charr[k][i] = charr[k][j];
						charr[k][j] = chTemp;
					}
				}
			}
		}
		char strResult[255] = {};
		
		for (int i = 0; i < arrCount[0]; ++i)
		{
			strResult[i] = charr[0][i];
		}
		for (int i = 0; i < arrCount[1]; ++i)
		{
			strResult[i+arrCount[0]] = charr[1][i];
		}
		cout << strResult << endl;
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		char strInput[2][6];
		int arrSize[2] ={};
		cin >> strInput[0] >> strInput[1];
		
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if ('\0' == strInput[i][j])
					break;
				++arrSize[i];
			}
		}
		if (arrSize[0] == arrSize[1])
		{
			for (int i = 0; i < arrSize[0]; ++i)
			{
				if (strInput[0][i] != strInput[1][i])
				{
					cout << "다릅니다" << endl;
					break;
				}
				if (i == arrSize[0] - 1)
					cout << "같습니다" << endl;
			}
		}
		else
		{
			cout << "다릅니다" << endl;
		}
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		int arr[4] = {};

		for (int i = 0; i < 4; ++i)
		{
			switch (i)
			{
			case 0:
				arr[0] = iInput / 1000;
				break;
			case 1:
				arr[1] = iInput % 1000 / 100;
				break;
			case 2:
				arr[2] = iInput % 100 / 10;
				break;
			case 3:
				arr[3] = iInput % 10;
				break;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int arrScore[6] = {};
		for (int i = 0; i < 6; ++i)
		{
			cin >> arrScore[i];
		}
		for (int i = 0; i < 5; ++i)
		{
			if (3 <= arrScore[i] - arrScore[i + 1] || -3 >= arrScore[i] - arrScore[i + 1])
			{
				cout << "재배치필요" << endl;
				break;
			}
			if (4 == i)
			{
				cout << "완벽한배치" << endl;
			}
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		char chInput[2][11] = {};
		int iSize[2] = {};
		cin >> chInput[0];
		cin >> chInput[1];
		for (int j = 0; j < 2; ++j)
		{
			for (int i = 0; i < 10; ++i)
			{
				if ('\0' == chInput[j][i])
				{
					break;
				}
				++iSize[j];
			}
		}
		if (iSize[0] != iSize[1])
		{
			cout << "거울문장이 아님" << endl;
		}
		else
		{
			for (int i = 0; i < iSize[0]; ++i)
			{
				if (chInput[0][i] != chInput[1][iSize[0] - (i+1)])
				{
					cout << "거울문장이 아님" << endl;
					break;
				}
				if (i == iSize[0] - 1)
				{
					cout << "거울문장" << endl;
				}
			}
		}
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char chInput[4][7] = {};
		for (int i = 0; i < 4; ++i)
		{
			cin >> chInput[i];
		}
		int arrSize[4] = {};

		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < 7; ++i)
			{
				if ('\0' == chInput[j][i])
				{
					break;
				}
				++arrSize[j];
			}
		}
		for (int i = 0; i < sizeof(arrSize) / 4 - 1; ++i)
		{
			for (int j = i; j < sizeof(arrSize) / 4; ++j)
			{
				if (arrSize[i] > arrSize[j])
				{
					int iTemp = arrSize[i];
					arrSize[i] = arrSize[j];
					arrSize[j] = iTemp;
				}
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			cout << arrSize[i] << " ";
		}
		cout << endl;
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		char chInput[11] = {};
		int iSize = 0;
		cin >> chInput;	
		for (int i = 0; i < 11; ++i)
		{
			if ('\0' == chInput[i])
			{
				break;
			}
			++iSize;
		}
		for (int i = 0; i < iSize; ++i)
		{
			if (1 == i % 2)
			{
				if (!('a' <= chInput[i] && 'z' >= chInput[i]))
				{
					cout << "일반문장" << endl;
					break;
				}
			}
			else
			{
				if (!('A' <= chInput[i] && 'Z' >= chInput[i]))
				{
					cout << "일반문장" << endl;
					break;
				}
			}
			if (iSize - 1 == i)
			{
				cout << "개구리문장" << endl;
			}
		}
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char arrName[8] = { "ABCZETQ" };
		char BlackList[6] = {};
		cin >> BlackList;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (BlackList[i] == arrName[j])
				{
					cout << BlackList[i] << "=마을사람" << endl;
					break;
				}
				if (6 == j)
				{
					cout << BlackList[i] << "=외부사람" << endl;
				}
			}
		}
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		char charr[5][11] = {};
		char arrSize[5] = {};
		for (int i = 0; i < 5; ++i)
		{
			cin >> charr[i];
		}
		int iMaxSizeIdx = 0;
		for (int j = 1; j < 5; ++j)
		{
			for (int i = 0; i < 10; ++i)
			{
				if ('\0' == charr[j][i])
				{
					if (arrSize[iMaxSizeIdx] < arrSize[j])
					{
						iMaxSizeIdx = j;
					}
					break;
				}
				++arrSize[j];
			}
		}
		cout << charr[iMaxSizeIdx] << endl;

	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;

	}


	return 0;
}