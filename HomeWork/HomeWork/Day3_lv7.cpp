#include <iostream>


using namespace std;

// 10번함수
////////////////////////////////////////////
void input_10(char _arr[][4], size_t _arrsize, char _chInput)
{
	for (size_t i = 0; i < _arrsize; ++i)
	{
		for (size_t j = 0; j < _arrsize / (sizeof(_arr[i]) / 4); ++j)
		{
			_arr[i][j] = _chInput;
		}
	}
}
void output_10(char _arr[][4], size_t _arrsize)
{
	for (size_t i = 0; i < _arrsize; ++i)
	{
		for (size_t j = 0; j < _arrsize / (sizeof(_arr[i]) / 4); ++j)
		{
			cout<< _arr[i][j];
		}
		cout << endl;
	}
}
////////////////////////////////////////////

// 11번함수
////////////////////////////////////////////
void input_11(int* _pInput)
{
	cin >> *_pInput;

}
void process_11(int _arr[][3], size_t _arrsize, int _pInput)
{
	for (size_t i = 0; i < _arrsize / 3; ++i)
	{
		for (size_t j = 0; j < _arrsize / (sizeof(_arr[i]) / 4); ++j)
		{
			_arr[i][j] = _pInput++;
		}
	}
}
void output_11(int _arr[][3], size_t _arrsize)
{
	int iCount = 0;
	for (size_t i = 0; i < _arrsize / 3; ++i)
	{
		for (size_t j = 0; j < _arrsize / (sizeof(_arr[i]) / 4); ++j)
		{
			cout << _arr[i][j]<<" ";
		}
		cout << endl;
	}
}
////////////////////////////////////////////

// 12번함수
////////////////////////////////////////////
void BBQ(int _iInput)
{
	if (0 < _iInput && 5 > _iInput)
	{
		cout << "초기값" << endl;
	}
	else if (6 < _iInput && 10 > _iInput)
	{
		cout << "중간값" << endl;
	}
	else
	{
		cout << "알수없는값" << endl;
	}
}
////////////////////////////////////////////


int main()
{

	// Level7

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int arr_1[5] = { 3,5,2,4,1 };
		int arr_2[3][2] = { {9,8}, {7,1}, {3,4} };
		int iInput;
		cin >> iInput;
		if (0 == iInput % 2)
		{
			for (size_t i = 0; i < sizeof(arr_2) / sizeof(arr_2[0]); ++i)
			{
				for (size_t j = 0; j < sizeof(arr_2[i]) / 4; ++j)
				{
					cout << arr_2[i][j];
				}
				cout << endl;
			}
		}
		else
		{
			for (size_t i = 0; i < sizeof(arr_1) / 4; ++i)
			{
				cout << arr_1[i];
			}
			cout << endl;
		}
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int iInput_1;
		int iInput_2;
		int Sub = 0;
		cin >> iInput_1;
		cin >> iInput_2;
		Sub = iInput_1 > iInput_2 ? iInput_1 - iInput_2 : iInput_2 - iInput_1;
		
		if (0 == Sub % 2)
		{
			cout << "짝사랑만" << endl;
		}
		else
		{
			cout << "고백한다" << endl;
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int arr[2][3] = { {3,1,1},{2,3,2} };
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j];
			}
		}
		cout << endl;

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[5] = {};
		unsigned int iCount = 0;
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
			if (3 <= arr[i] && 7 >= arr[i])
			{
				++iCount;
			}
		}
		cout << iCount << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int iScore = 0;
		cin >> iScore;

		if (iScore >= 80)
		{
			cout << "수" << endl;
		}
		else if(iScore >= 70)
		{
			cout << "우" << endl;
		}
		else if (iScore >= 60)
		{
			cout << "미" << endl;
		}
		else
		{
			cout << "재시도" << endl;
		}
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int iInput = 0;
		for (int i = 0; i < 4; ++i)
		{
			cin >> iInput;
			if (20 > iInput)
			{
				cout << "더 큰수를 입력하세요" << endl;
			}
			else if (20 < iInput)
			{
				cout << "더 작은수를 입력하세요" << endl;
			}
			else
			{
				cout << "정답입니다." << endl;
			}
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int arrInput[3] = {};
		int iMax = INT_MIN;
		int iMin = INT_MAX;
		for (size_t i = 0; i < sizeof(arrInput) / 4; ++i)
		{
			cin >> arrInput[i];
			if(iMax < arrInput[i])
			{ 
				iMax = arrInput[i];
			}
			else if (iMin > arrInput[i])
			{
				iMin = arrInput[i];
			}
		}
		cout << "MAX=" << iMax << endl;
		cout << "MIN=" << iMin << endl;

	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		int arr[3][3] = { {3,4,1},{2,1,4},{3,3,0} };
		int iCountOdd = 0;
		int iCountEven = 0;

		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[i]) / 4; ++j)
			{
				if (0 == arr[i][j] % 2)
				{
					++iCountEven;
				}
				else
				{
					++iCountOdd;
				}
			}
		}
		cout << "짝수:" << iCountEven << endl;
		cout << "홀수:" << iCountOdd << endl;
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		int arrScore[5] = {};
		for (size_t i = 0; i < sizeof(arrScore) / 4; ++i)
		{
			cin >> arrScore[i];
		}

		for (size_t i = 0; i < sizeof(arrScore) / 4; ++i)
		{
			cout << i+1 << "번사람은" << arrScore[i] << "점";
			if (70 <= arrScore[i])
			{
				cout << "PASS" << endl;
			}
			else if (50 <= arrScore[i])
			{
				cout << "RETEST"<< endl;
			}
			else if (50 > arrScore[i])
			{
				cout << "FAIL"<<endl;
			}
		}
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char ch = '\0';
		char charr[4][4] = {};
		cin >> ch;
		input_10(charr, sizeof(charr) / 4, ch);
		output_10(charr, sizeof(charr) / 4);
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		int iInput = 0;
		int iarr[3][3] = {};
		input_11(&iInput);
		process_11(iarr, sizeof(iarr) / 4, iInput);
		output_11(iarr, sizeof(iarr) / 4);

	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		
		switch (iInput)
		{
		case 3: case 5: case 7:
			for (int i = 1; i <= 10; ++i)
			{
				cout << i;
			}
			cout << endl;
			break;
		case 0: case 8:
			for (int i = 10; i >= 1; --i)
			{
				cout << i;
			}
			cout << endl;
			break;
		default:
			BBQ(iInput);
			break;
		}

	}


	return 0;
}