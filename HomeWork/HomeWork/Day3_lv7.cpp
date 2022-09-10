#include <iostream>


using namespace std;

// 10���Լ�
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

// 11���Լ�
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

// 12���Լ�
////////////////////////////////////////////
void BBQ(int _iInput)
{
	if (0 < _iInput && 5 > _iInput)
	{
		cout << "�ʱⰪ" << endl;
	}
	else if (6 < _iInput && 10 > _iInput)
	{
		cout << "�߰���" << endl;
	}
	else
	{
		cout << "�˼����°�" << endl;
	}
}
////////////////////////////////////////////


int main()
{

	// Level7

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
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

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		int iInput_1;
		int iInput_2;
		int Sub = 0;
		cin >> iInput_1;
		cin >> iInput_2;
		Sub = iInput_1 > iInput_2 ? iInput_1 - iInput_2 : iInput_2 - iInput_1;
		
		if (0 == Sub % 2)
		{
			cout << "¦�����" << endl;
		}
		else
		{
			cout << "����Ѵ�" << endl;
		}
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
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

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
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

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int iScore = 0;
		cin >> iScore;

		if (iScore >= 80)
		{
			cout << "��" << endl;
		}
		else if(iScore >= 70)
		{
			cout << "��" << endl;
		}
		else if (iScore >= 60)
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "��õ�" << endl;
		}
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int iInput = 0;
		for (int i = 0; i < 4; ++i)
		{
			cin >> iInput;
			if (20 > iInput)
			{
				cout << "�� ū���� �Է��ϼ���" << endl;
			}
			else if (20 < iInput)
			{
				cout << "�� �������� �Է��ϼ���" << endl;
			}
			else
			{
				cout << "�����Դϴ�." << endl;
			}
		}
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
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

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
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
		cout << "¦��:" << iCountEven << endl;
		cout << "Ȧ��:" << iCountOdd << endl;
	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		int arrScore[5] = {};
		for (size_t i = 0; i < sizeof(arrScore) / 4; ++i)
		{
			cin >> arrScore[i];
		}

		for (size_t i = 0; i < sizeof(arrScore) / 4; ++i)
		{
			cout << i+1 << "�������" << arrScore[i] << "��";
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

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;
		char ch = '\0';
		char charr[4][4] = {};
		cin >> ch;
		input_10(charr, sizeof(charr) / 4, ch);
		output_10(charr, sizeof(charr) / 4);
	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;
		int iInput = 0;
		int iarr[3][3] = {};
		input_11(&iInput);
		process_11(iarr, sizeof(iarr) / 4, iInput);
		output_11(iarr, sizeof(iarr) / 4);

	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;
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