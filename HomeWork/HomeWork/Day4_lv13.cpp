#include <iostream>


using namespace std;

char g_charr[3][3] = { 'A', 'D', 'F', 'Q', 'W', 'E', 'Z', 'X', 'C' };
int g_iarr[2][6] = { 4,5,6,1,3,1,2,1,3,6,3,6 };
char g_charr2[3][3] = { 'D', 'A',  'S',
						'Q',  'W', 'V',
						'R', 'T', 'Y'};

// 1���Լ�
////////////////////////////////////////////
void ABC_1(int a, int b, int* sum, int* gop)
{
	*sum = a + b;
	*gop = a * b;
}
////////////////////////////////////////////

// 2���Լ�
////////////////////////////////////////////
void Find_2(char _chInput)
{
	for (size_t i = 0; i < sizeof(g_charr) / sizeof(g_charr[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_charr[0]); ++j)
		{
			if (_chInput == g_charr[i][j])
			{
				cout << i << "," << j << endl;
				return;
			}
		}
	}
}
////////////////////////////////////////////

// 3���Լ�
////////////////////////////////////////////
int stringLen_3(char* _chInput, int _iSize)
{
	int iCount = 0;
	for (size_t i = 0; i < _iSize; ++i)
	{
		if ('\0' == _chInput[i])
			return iCount;

		++iCount;
	}
	return 0;
}
////////////////////////////////////////////

// 4���Լ�
////////////////////////////////////////////
void KFC_4(int* _BigCount, int* _SmallCount)
{
	char chInput[10] = {};
	cin >> chInput;

	for (size_t i=0; i<sizeof(chInput); ++i)
	{
		if ('A' <= chInput[i] && 'Z' >= chInput[i])
		{
			++(*_BigCount);
		}
		else if ('a' <= chInput[i] && 'z' >= chInput[i])
		{
			++(* _SmallCount);
		}
	}
}
////////////////////////////////////////////

// 5���Լ�
////////////////////////////////////////////
void Input_5(int* a, int* b, int* c)
{
	cin >> *a >> *b >> *c;
}
void Process_5(int* a, int* b, int* c, int* _iCounta, int* _iCountb, int* _iCountc)
{
	for (size_t i = 0; i < sizeof(g_iarr) / sizeof(g_iarr[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_iarr[0]) / 4; ++j)
		{
			if (*a == g_iarr[i][j])
				++(*_iCounta);
			else if (*b == g_iarr[i][j])
				++(*_iCountb);
			else if (*c == g_iarr[i][j])
				++(*_iCountc);
		}
	}
}
void Output_5(int* a, int* b, int* c, int* _iCounta, int* _iCountb, int* _iCountc)
{
	cout << *a << "=" << *_iCounta << "��" << endl;
	cout << *b << "=" << *_iCountb << "��" << endl;
	cout << *c << "=" << *_iCountc << "��" << endl;
}
////////////////////////////////////////////

// 7���Լ�
////////////////////////////////////////////
void FindABC_7(char* _chInput1, char* _chInput2, int* _iCountA, int* _iCountB, int* _iCountC, int _iSize1, int _iSize2)
{
	

	for (size_t i = 0; i < _iSize1; ++i)
	{
		if ('A' == _chInput1[i])
			++(*_iCountA);
		else if ('B' == _chInput1[i])
			++(*_iCountB);
		else if ('C' == _chInput1[i])
			++(*_iCountC);
	}
	for (size_t i = 0; i < _iSize2; ++i)
	{
		if ('A' == _chInput2[i])
			++(*_iCountA);
		else if ('B' == _chInput2[i])
			++(*_iCountB);
		else if ('C' == _chInput2[i])
			++(*_iCountC);
	}
}
////////////////////////////////////////////

// 9���Լ�
////////////////////////////////////////////
char Find_9(int _x, int _y)
{
	return g_charr2[_x][_y];
}
////////////////////////////////////////////

int main()
{

	// Level13

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		int a, b;
		int sum = 0;
		int gop = 0;
		cin >> a >> b;

		ABC_1(a, b, &sum, &gop);
		cout << sum << " " << gop << endl;
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		char chInput = 0;
		cin >> chInput;
		Find_2(chInput);
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		char strInput[255] = {};
		cin >> strInput;
		cout<< stringLen_3(strInput, sizeof(strInput))<<"����"<<endl;
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int iBigCount = 0;
		int iSmallCount = 0;
		KFC_4(&iBigCount, &iSmallCount);
		cout << "�빮��" << iBigCount << "��" << endl <<"�ҹ���" << iSmallCount << "��" << endl;
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int a, b, c;
		int iCounta = 0;
		int iCountb = 0;
		int iCountc = 0;

		Input_5(&a, &b, &c);
		Process_5(&a, &b, &c, &iCounta, &iCountb, &iCountc);
		Output_5(&a, &b, &c, &iCounta, &iCountb, &iCountc);
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		char charr [2][6] = { '4', '5',  '7',  '1',  '3',  '2',
							'D',  'F',  'Q',  'W',  'G',  'Z' };

		char iInput;
		cin >> iInput;

		for (size_t j = 0; j < sizeof(charr[0]); ++j)
		{
			if (iInput == charr[0][j])
			{
				cout << charr[1][j] << endl;
				break;
			}
		}
		
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		char strInput1[255] = {};
		char strInput2[255] = {};

		int iCountA = 0;
		int iCountB = 0;
		int iCountC = 0;

		int iSize1 = 0;
		int iSize2 = 0;

		cin >> strInput1 >> strInput2;

		for (size_t i = 0; i < sizeof(strInput1); ++i)
		{
			if ('\0' == strInput1[i])
				break;
			++iSize1;
		}
		for (size_t i = 0; i < sizeof(strInput2); ++i)
		{
			if ('\0' == strInput2[i])
				break;
			++iSize2;
		}


		FindABC_7(strInput1, strInput2, &iCountA, &iCountB, &iCountC, iSize1, iSize2);

		cout << "A:" << iCountA << endl;
		cout << "B:" << iCountB << endl;
		cout << "C:" << iCountC << endl;
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		struct PROFILE
		{
			char name[7];
			int age;
			int weight;
		};
		PROFILE int1, int2;

		cin >> int1.name >> int1.age >> int1.weight >> int2.name >> int2.age >> int2.weight;

		cout << int1.name << "&" << int2.name << endl;
		cout << "���" << (int1.age + int2.age) / 2 << "��" << endl;
		cout << "���" << (int1.weight + int2.weight) / 2 << "KG" << endl;
	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << Find_9(x1, y1) << " " << Find_9(x2, y2) << endl;
	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;
		int arrCountry[7] = { 4,2,5,1,6,7,3 };
		int idx1, idx2;
		int iLength = 0;
		char Country1, Country2;
		cin >> Country1 >> Country2;
		idx1 = Country1 - 'A';
		idx2 = Country2 - 'A';
		if (idx1 > idx2)
		{
			for (int i = idx2 + 1; i < idx1; ++i)
			{
				iLength += arrCountry[i];
			}
		}
		else
		{
			for (int i = idx1 + 1; i < idx2; ++i)
			{
				iLength += arrCountry[i];
			}
		}
		cout << iLength << endl;
	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;
		int arrA[5] = {};
		int arrB[5] = {};
		int arrC[5] = {};

		for (size_t i = 0; i < 3; ++i)
		{
			for (size_t j = 0; j < 5; ++j)
			{
				if (0 == i)
				{
					cin >> arrA[j];
				}
				else if (1 == i)
				{
					cin >> arrB[j];
				}
				else if (2 == i)
				{
					cin >> arrC[j];
				}
			}
		}
		for (size_t i = 0; i < 5; ++i)
		{
			cout << arrA[i] * arrB[i] + arrC[i] << " ";
		}
		cout << endl;
	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;
		int arr[4][4] = { 3,4,1,6,
						3,5,3,6,
						0,0,0,0,
						5,4,6,0 };
		for (size_t i = 0; i < 4; ++i)
		{
			cin >> arr[2][i];
		}
		int iMax = arr[0][0];
		int iMin = arr[0][0];
		int iMaxx = 0;
		int iMaxy = 0;
		int iMinx = 0;
		int iMiny = 0;
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				if (iMax < arr[i][j])
				{
					iMax = arr[i][j];
					iMaxx = i;
					iMaxy = j;
				}
				else if (iMin > arr[i][j])
				{
					iMin = arr[i][j];
					iMinx = i;
					iMiny = j;
				}
			}
		}
		cout << "MAX=" << iMax << "(" << iMaxx << "," << iMaxy << ")" << endl;
		cout << "MIN=" << iMin << "(" << iMinx << "," << iMiny << ")" << endl;
	}


	return 0;
}