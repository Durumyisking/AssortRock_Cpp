#include<iostream>

using namespace std;

// 전역변수
int g_iNum = 0;
char g_chArr[3] = { 'A', 'B', 'C' };
int g_iArr[4] = {};



// 4번 함수
/////////////////////////////////
void KFC_4()
{
	cout << "KFC입니다" << endl;
}
void MC_4()
{
	cout << "MC입니다" << endl;
}
/////////////////////////////////


// 5번 함수
/////////////////////////////////
void LOT_5()
{
	for (int i = 0; i < 5; ++i)
	{
		cout << i+1;
	}
	cout << endl;
}
/////////////////////////////////


// 6번 함수
/////////////////////////////////
void KFC_6()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "#";
	}
	cout << endl;
}
void MC_6()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "@";
	}
	cout << endl;
}
/////////////////////////////////

// 8번 함수
/////////////////////////////////
void KFC_8()
{
	cin >> g_iNum;
}
void BBQ_8()
{
	if (g_iNum > 5)
	{
		cout << "만세" << endl;
	}
	else
	{
		cout << "다시" << endl;
	}
}
/////////////////////////////////

// 9번 함수
/////////////////////////////////
void KFC_9()
{
	for (size_t i = 0; i < 3; ++i)
	{
		cout << g_chArr[i];
	}
	cout << endl;
}
/////////////////////////////////

// 10번 함수
/////////////////////////////////
void Input_10()
{
	for (size_t i = 0; i < sizeof(g_iArr)/4; ++i)
	{
		cin >> g_iArr[i];
	}
}
void Output_10()
{
	for (size_t i = sizeof(g_iArr) / 4; i > 0; --i)
	{
		cout << g_iArr[i-1];
	}
}
/////////////////////////////////

// 11번 함수
/////////////////////////////////
void PrintAll_11(int _arr[], size_t _iSize)
{
	for (size_t i = 0; i < _iSize; ++i)
	{
		cout << _arr[i] << endl;
	}
}
/////////////////////////////////

// 12번 함수
/////////////////////////////////
void QTR_12()
{
	cout << "QTR100%" << endl;
}
void BBQ_12()
{
	cout << "BBQ100%" << endl;
}
/////////////////////////////////

int main()
{
	// Level5

	// 1번
	cout << "///////////////1번///////////////" << endl;
	char chinput;
	cin >> chinput;
	for (int i = 0; i < 3; ++i)
	{
		cout << chinput;
	}
	cout << endl;

	// 2번
	cout << "///////////////2번///////////////" << endl;
	int iarr[4];
	int sum = 0;
	for (size_t i = 0; i < 4; ++i)
	{
		cin >> iarr[i];
		sum += iarr[i];
	}
	cout << sum << endl;

	// 3번
	cout << "///////////////3번///////////////" << endl;
	int input;
	char charr[3] = { 'm', 'i', 'n' };
	cin >> input;
	cout << charr[input] << endl;;

	// 4번
	cout << "///////////////4번///////////////" << endl;
	cin >> input;
	if (1 == input)
	{
		KFC_4();
	}
	else if (2 == input)
	{
		MC_4();
	}
	
	// 5번
	cout << "///////////////5번///////////////" << endl;
	cin >> input;
	for (int i = 0; i < input; ++i)
	{
		LOT_5();
	}

	// 6번
	cout << "///////////////6번///////////////" << endl;
	KFC_6();
	MC_6();

	// 7번
	cout << "///////////////7번///////////////" << endl;
	int arr[6];
	for (size_t i = 0; i < 6; ++i)
	{
		if (i < 4)
		{
			cin >> arr[i];
		}
		else
		{
			arr[i] = arr[i-1] + 1;
		}
	}

	for (size_t i = 0; i < 6; ++i)
	{
		cout << arr[i];
	}
	cout << endl;

	// 8번
	cout << "///////////////8번///////////////" << endl;
	KFC_8();
	BBQ_8();

	// 9번
	cout << "///////////////9번///////////////" << endl;
	cin >> input;
	for (int i = 0; i < input; ++i)
	{
		KFC_9();
	}
	
	// 10번
	cout << "///////////////10번///////////////" << endl;
	Input_10();
	Output_10();

	// 11번
	cout << "///////////////11번///////////////" << endl;
	int arr_11[6] = {};
	cin >> input;
	for (size_t i = 0; i < sizeof(arr_11) / 4; ++i)
	{
		arr_11[i] = input++;
	}

	PrintAll_11(arr_11, sizeof(arr_11)/sizeof(int));
	
	// 12번
	cout << "///////////////12번///////////////" << endl;
	int arr_12[3] = {};
	int iSum = 0;
	for (size_t i = 0; i < sizeof(arr_12) / 4; ++i)
	{
		cin >> arr_12[i];
		iSum += arr_12[i];
	}
	if (iSum >= 10)
	{
		QTR_12();
	}
	else
	{
		BBQ_12();
	}

	// 13번
	cout << "///////////////13번///////////////" << endl;
	int arr_13[11] = { 3,4,1,5,8,1,7,7,3,6,9 };
	int iInput_13;
	cin >> iInput_13;
	for (size_t i = 0; i < sizeof(arr_13) / 4; i+=iInput_13)
	{
		cout << arr_13[i] << " ";
	}



	return 0;
}