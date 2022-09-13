#include <iostream>


using namespace std;

// 3번함수
////////////////////////////////////////////
void getMaxPos(int* x, int* y, int _arr[][3], int _iArrSize)
{
	int iMax = _arr[0][0];
	int iMaxX, iMaxY;
	iMaxX = 0;
	iMaxY = 0;

	for (int i = 0; i < _iArrSize / sizeof(_arr[0]); ++i)
	{
		for (int j = 0; j < sizeof(_arr[0]) / 4; ++j)
		{
			if (iMax < _arr[i][j])
			{
				iMax = _arr[i][j];
				iMaxX = i;
				iMaxY = j;
			}
		}
	}
	*x = iMaxX;
	*y = iMaxY;

}
void getMinPos(int* x, int* y, int _arr[][3], int _iArrSize)
{
	int iMin = _arr[0][0];
	int iMinX, iMinY;
	iMinX = 0;
	iMinY = 0;

	for (int i = 0; i < _iArrSize / sizeof(_arr[0]); ++i)
	{
		for (int j = 0; j < sizeof(_arr[0]) / 4; ++j)
		{
			if (iMin > _arr[i][j])
			{
				iMin = _arr[i][j];
				iMinX = i;
				iMinY = j;
			}
		}
	}
	*x = iMinX;
	*y = iMinY;
}
////////////////////////////////////////////

// 6번함수
////////////////////////////////////////////
void getMaxPos_6(int* x, char* _arr)
{
	char chMax = 'A';
	for (int i = 0; i < 10; ++i)
	{
		if ('\0' == _arr[i])
			break;
		if (chMax < _arr[i])
		{
			chMax = _arr[i];
			*x = i;
		}
	}
}
void getMinPos_6(int* x, char* _arr)
{
	char chMin = 'Z';
	for (int i = 0; i < 10; ++i)
	{
		if ('\0' == _arr[i])
			break;
		if (chMin > _arr[i])
		{
			chMin = _arr[i];
			*x = i;
		}
	}
}
////////////////////////////////////////////


// 8번함수
////////////////////////////////////////////
void isExist_8(char* _pInput1, char* _pInput2, char _arr[][7], int _iSize)
{
	int iFlag = 0;
	for (int i = 0; i < _iSize / sizeof(_arr[0]); ++i)
	{
		for (int j = 0; j < sizeof(_arr[0]); ++j)
		{
			if (*_pInput1 == _arr[i][j])
			{
				iFlag |= 1;
				cout << *_pInput1 << ":존재" << endl;
			}
			if (*_pInput2 == _arr[i][j])
			{
				iFlag |= 2;
				cout << *_pInput2 << ":존재" << endl;
			}
		}
	}

	if (0 == (iFlag & 1))
	{
		cout << *_pInput1 << ":없음" << endl;
	}
	if (0 == (iFlag & 2))
	{
		cout << *_pInput2 << ":없음" << endl;
	}


}
////////////////////////////////////////////

int main()
{
	// Level16.5

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int a, b, c;
		cin >> a >> b >> c;

		for (int i = 0; i < c; ++i)
		{
			for (int j = a; j <= b; ++j)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		char charr[6][3] = {};
		char chInput = 'A';
		for (int i = sizeof(charr[0]) - 1; i >= 0 ; --i)
		{
			for (int j = sizeof(charr) / sizeof(charr[0]) - 1; j >= 0 ; --j)
			{
				charr[j][i] = chInput++;
			}
		}
		int idx1, idx2;
		cin >> idx1 >> idx2;
		cout << charr[idx1][idx2] << endl;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int arr[2][3] = {};
		int iMaxX, iMaxY, iMinX, iMinY;
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cin >> arr[i][j];
			}
		}
		getMaxPos(&iMaxX, &iMaxY, arr, sizeof(arr));
		getMinPos(&iMinX, &iMinY, arr, sizeof(arr));
		cout << "(" << iMaxX << "," << iMaxY << ")" << endl;
		cout << "(" << iMinX << "," << iMinY << ")" << endl;

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int iIdx0, iIdx1;
		cin >> iIdx0 >> iIdx1;
		int iArr[6] = {};
		iArr[0] = iIdx0;
		iArr[1] = iIdx1;

		for (int i = 2; i < 6; ++i)
		{
			iArr[i] = iArr[i - 1] * iArr[i - 2];
		}
		cout << iArr[5] << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		char charr[255] = {};
		cin >> charr;
		char a, b;
		cin >> a >> b;
		for (int i = 0; i < sizeof(charr); ++i)
		{
			if ('\0' == charr[i])
				break;

			if (a == charr[i])
				charr[i] = b;
		}
		cout << charr << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		char charr[10] = {};
		cin >> charr;
		int iMaxX, iMinX;
		getMaxPos_6(&iMaxX, charr);
		getMinPos_6(&iMinX, charr);
		cout << iMaxX << endl << iMinX << endl;
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int iArr[7][4] = {};
		int iCount = 1;
		for (int i = 0; i < sizeof(iArr) / sizeof(iArr[0]); ++i)
		{
			for (int j = 0; j < sizeof(iArr[0]) / 4; ++j)
			{
				iArr[i][j] = iCount++;
			}
		}
		int idxarr[3] = {};
		for (int i = 0; i < 3; ++i)
		{
			cin>> idxarr[i];
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				iArr[idxarr[i]][j] = 0;
			}
		}
		for (int i = 0; i < sizeof(iArr) / sizeof(iArr[0]); ++i)
		{
			for (int j = 0; j < sizeof(iArr[0])/ 4; ++j)
			{
				cout << iArr[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char charr[2][7] = { "A79TKQ" , "MINCOD" };
		char chInput[2];
		cin >> chInput[0] >> chInput[1];
		isExist_8(&chInput[0], &chInput[1], charr, sizeof(charr));
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		int iInput1, iInput2;
		char chInput;
		cin >> iInput1 >> iInput2 >> chInput;

		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < iInput1; ++i)
			{
				for (int j = 0; j < iInput2; ++j)
				{
					cout << chInput;
				}
				cout << endl;
			}
			cout << endl;
		}
	}


	return 0;
}