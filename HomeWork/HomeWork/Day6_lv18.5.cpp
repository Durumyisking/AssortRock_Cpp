#include <iostream>


using namespace std;

// 6번함수
////////////////////////////////////////////
void isWin(int win[][3], int people, size_t _iSize)
{
	int iFlag = 0;
	for (int i = 0; i < _iSize / sizeof(win[0]); ++i)
	{
		for (int j = 0; j < sizeof(win[0])/4; ++j)
		{
			if (win[i][j] == people)
			{
				iFlag = 1;
				cout << people << "번 합격" << endl;
				break;
			}
		}
		if (1 == iFlag)
			break;
	}
	if (0 == iFlag)
		cout << people << "번 불합격" << endl;
}
////////////////////////////////////////////


int main()
{

	// Level18.5

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		char charr[2][4] = { "GKG", {} };
		cin >> charr[1];
		int Alp[26] = {};

		for (size_t i = 0; i < sizeof(charr)/sizeof(charr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(charr[0]); ++j)
			{
				if (97 <= charr[i][j] && 122 >= charr[i][j])
				{
					charr[i][j] -= 32;
				}
				++Alp[charr[i][j] - 65];
			}
		}
		int iFlag = 0;
		for (size_t i = 0; i < sizeof(Alp) / 4; ++i)
		{
			if (3 <= Alp[i])
			{
				iFlag = 1;
				cout << "있음" << endl;
			}
		}
		if (0 == iFlag)
			cout << "없음" << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int iArr[6] = {};
		for (int i = 0; i < 6; ++i)
		{
			cin >> iArr[i];
		}
		int iFlag = 0;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = i + 1; j < 6; ++j)
			{
				if (iArr[i] == iArr[j])
				{
					iFlag = 1;
					cout << "으악 도플갱어야~" << endl;
					break;
				}
			}
			if (1 == iFlag)
			{
				break;
			}

		}
		if (0 == iFlag)
		{
			cout << "도플갱어는 없어" << endl;
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		char charr[11] = {};
		cin >> charr;
		int Alp[26] = {};

		int iSize = 0;
		for (size_t i = 0; i < sizeof(charr); ++i)
		{
			if ('\0' == charr[i])
				break;

			++iSize;
		}

		for (size_t i = 0; i < iSize; ++i)
		{
			if (97 <= charr[i] && 122 >= charr[i])
			{
				charr[i] -= 32;
			}
			++Alp[charr[i] - 65];
		}
		int iMax = 0;
		int iMaxIdx = 0;
		for (size_t i = 0; i < sizeof(Alp) / 4; ++i)
		{
			if (iMax < Alp[i])
			{ 
				iMaxIdx = i;
				iMax = Alp[i];
			}
		}
		char result = iMaxIdx + 65;
		cout << result << endl;
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int up[5] = {};
		int down[5] = {};
		int iCount = 0;
		for (int i = 0; i < 5; ++i)
			cin >> up[i];	
		for (int i = 0; i < 5; ++i)
			cin >> down[i];
		
		for (int i = 0; i < 5; ++i)
		{
			if (1 == up[i] && 1 == down[i])
				++iCount;
		}
		cout << iCount <<endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		char arr[10] = { "ATKPTCABC" };
		char chInput1, chInput2;
		cin >> chInput1 >> chInput2;
		int idx1 = 0;
		int idx2 = 0;
		for (int i = 0; i < sizeof(arr); ++i)
		{
			if (chInput1 == arr[i])
			{
				idx1 = i;
			}
		}
		for (int i = sizeof(arr)-1; i >= 0; --i)
		{
			if (chInput2 == arr[i])
			{
				idx2 = i;
			}
		}
		if (idx2 > idx1)
			cout << idx2 - idx1 << endl;
		else
			cout << idx1 - idx2<< endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int win[2][3] = { {3,5,1},{4,2,6} };
		int people[4] = {};
		for (int i = 0; i < 4; ++i)
			cin >> people[i];
		
		for (int i = 0; i < 4; ++i)
		{
			isWin(win, people[i], sizeof(win));
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		char vect[10] = {"MINCODING"};
		int Bucket[512] = {};
		int n = 0;
		cin >> n;
		char* chArr = new char[n+1];
		for (int i = 0; i < n; ++i)
		{
			cin >> chArr[i];
		}	
		for (int i = 0; i < 10; ++i)
		{
			++Bucket[vect[i]];
		}
		cout << "출력결과 : ";
		for (int i = 0; i < 5; ++i)
		{
			if (1 == Bucket[chArr[i]])
			{
				cout << 'O';
			}
			else
			{
				cout << 'X';
			}
		}
		cout << endl;

	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char strInput[3][11] = {};
		int Bucket[512] = {};

		for (int i = 0; i < 3; ++i)
		{
			cin >> strInput[i];
		}

		int iFlag = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if ('\0' == strInput[i][j])
					continue;

				if (0 == Bucket[strInput[i][j]])
				{
					++Bucket[strInput[i][j]];
				}
				else
				{
					iFlag = 1;
					break;
				}				
			}
			if (1 == iFlag)
			{
				cout << "No" << endl;
				break;
			}
		}
		if (0 == iFlag)
			cout << "Perfect" << endl;
		
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;	
		char chArr[11] = {};
		int Bucket[6] = {};
		cin >> chArr;
		for (int i = 0; i < 10; ++i)
		{
			if (0 == Bucket[chArr[i] - 65])
				++Bucket[chArr[i] - 65];
		}
		for (int i = 0; i < 6; ++i)
		{
			if (1 == Bucket[i])
			{
				cout << (char)(i + 65);
			}
		}
		cout << endl;
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char chArr[11] = {};
		cin >> chArr;
		int Bucket[512] = {};
		for (int i = 0; i < 11; ++i)
		{
			if ('\0' == chArr[i])
				continue;

			++Bucket[chArr[i]];
		}
		for (int i = 0; i < 512; ++i)
		{
			if (0 < Bucket[i])
			{
				cout << (char)i << ":" << Bucket[i] << endl;
			}
		}
	}


	return 0;
}