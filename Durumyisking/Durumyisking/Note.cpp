#include <iostream>

using namespace std;

char path[10];
char arr[4]{ 'B', 'G', 'T', 'K' };
char arr2[4]{ 'A', 'T', 'K', 'P' };
char via[10];


void BBQ(int _Lv, int _Dest)
{
	if (_Lv == _Dest)
		return;

	BBQ(_Lv + 1, _Dest);
	BBQ(_Lv + 1, _Dest);

	int a = 0;
}

void BBQ2(int _Lv)
{
	if (_Lv == 3)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 2; i++)
	{
		path[_Lv] = 'A' + i;
		BBQ2(_Lv + 1);
		path[_Lv] = '\0';
	}
}


void BBQ3(int _Lv)
{
	if (_Lv == 2)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		path[_Lv] = *(arr + i);
		BBQ3(_Lv + 1);
		path[_Lv] = '\0';
	}
}

void BBQ4(int _Lv)
{
	if (_Lv == 3)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (0 == via[i])
		{
			via[i] = 1;
			path[_Lv] = 'A' + i;
			BBQ4(_Lv + 1);
			path[_Lv] = 0;
			via[i] = 0;
		}
	}
}


void BBQ5(int _Lv)
{
	if (3 == _Lv)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (0 == via[i])
		{
			path[_Lv] = *(arr2 + i);
			via[i] = 1;
			BBQ5(_Lv + 1);
			path[_Lv] = 0;
			via[i] = 0;
		}
	}
}


int main()
{
	int iInput;
//	cin >> iInput;
	BBQ5(0);


	return 0;
}