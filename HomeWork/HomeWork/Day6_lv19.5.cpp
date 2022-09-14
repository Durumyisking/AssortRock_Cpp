#include <iostream>


using namespace std;

// 1번함수
////////////////////////////////////////////
void BBQ_1(int* _iMax, int* _iMin)
{
	int arr[5] = {};
	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
	}
	*_iMax = arr[0];
	*_iMin = arr[0];
	for (int i = 1; i < 5; ++i)
	{
		if (*_iMax < arr[i])
			*_iMax = arr[i];
		if (*_iMin > arr[i])
			*_iMin = arr[i];
	}
}
////////////////////////////////////////////

// 2번함수
////////////////////////////////////////////
bool BBQ_2(int arr[][4], int _x, int _y)
{
	int iCount = 0;
	for (int i = _x; i < 2 + _x; ++i)
	{
		for (int j = _y; j < 2 + _y; ++j)
		{
			if (1 == arr[i][j])
			{
				++iCount;
			}
			if (1 < iCount)
			{
				return false;
			}
		}
	}
	return true;
}
////////////////////////////////////////////

// 3번함수
////////////////////////////////////////////
void BBQ_3(int _arr[][4], char _dir, int _idx)
{
	if ('G' == _dir)
	{
		for (int i = 0; i < 4; ++i)
			_arr[_idx][i] = 1;
	}
	else if ('S' == _dir)
	{
		for (int i = 0; i < 4; ++i)
			_arr[i][_idx] = 1;
	}
}
////////////////////////////////////////////

// 6번함수
////////////////////////////////////////////
void BBQ_6(char _pattern[][3], char _arr[][5], int* _pCount, int x, int y)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if(_arr[x+i][y+j] == _pattern[i][j])
				++(*_pCount);
		}
	}	
}
////////////////////////////////////////////

// 7번함수
////////////////////////////////////////////
int BBQ_7(int _bit[][2], int _arr[][3], int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if(1 == _bit[i][j])
				sum += _arr[x + i][y + j];
		}
	}
	return sum;
}
////////////////////////////////////////////

int main()
{

	// Level

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int max = 0;
		int min = 0;
		BBQ_1(&max, &min);
		cout << "max:" << max << endl;
		cout << "min:" << min <<endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int arr[5][4] = {};
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> arr[i][j];
			}
		}
		// 00 01 02 10 11 12 20 21 22

		int iCount = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (BBQ_2(arr, i, j))
				{
					++iCount;
				}
			}
		}
		if(12 == iCount)
			cout << "안정된 상태" << endl;
		else
			cout << "불안정한 상태" << endl;

	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int pwd[4] = {};
		for (int i = 0; i < 4; ++i)
			cin >> pwd[i];

		int arr[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
		int result[4][4] = {};
		// i*4 + j + 1
		int iCount = 1;
		for (int i = 0; i < 4; ++i)
		{
			result[(pwd[i] - 1)/4][(pwd[i] - 1)%4] = iCount++;
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout << result[i][j];
			}
			cout << endl;
		}
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[4][4] = {};
		char dir;
		int idx;

		for (int i = 0; i < 3; ++i)
		{
			cin >> dir >> idx;
			BBQ_3(arr, dir, idx);
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		struct sketchbook
		{
			char image[3][3];
		};
		sketchbook a = {};
		int Bucket[512] = {};

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> a.image[i][j];
				++Bucket[(char)a.image[i][j]];
			}
		}
		for (int i = 0; i < 512; ++i)
		{
			if (Bucket[i] > 0)
			{
				cout << (char)i;
			}
		}
		cout << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		char map[3][5] = { "ABGK", "TTAB", "ACCD" };
		char pattern[2][3] = { };
		int iResult = 0;
		int iCount;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				cin >> pattern[i][j];
			}
		}
		// 00 01 10 11 [0] ab [1] cd
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				iCount = 0;

				BBQ_6(pattern, map, &iCount, i ,j);
				if (4 == iCount)
					++iResult;
			}
		}
		cout << "발견(" << iResult << "개)" << endl;
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int map[3][3] = { {3,5,1},{3,8,1},{1,1,5} };
		int bitarray[2][2] = {};
		int Sumarray[2][2] = {};
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				cin >> bitarray[i][j];

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				Sumarray[i][j] = BBQ_7(bitarray, map, i, j);
			}
		}
		int iMax = Sumarray[0][0];
		int maxi = 0;
		int maxj = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				if (iMax < Sumarray[i][j])
				{
					iMax = Sumarray[i][j];
					maxi = i;
					maxj = j;
				}
		cout << "(" << maxi << "," << maxj << ")" << endl;

	}



	return 0;
}