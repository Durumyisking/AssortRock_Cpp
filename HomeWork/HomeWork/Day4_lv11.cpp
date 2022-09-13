#include <iostream>


using namespace std;

int g_vect[2][5] = { {3,2,6,2,4 }, {1, 4, 2, 6, 5} };


// 1번함수
////////////////////////////////////////////
int input_1()
{
	int iInput = 0;
	cin >> iInput;
	return iInput;
}
void cals_1(int a, int b, int c)
{
	cout << a + b + c<<endl;
}
////////////////////////////////////////////

// 2번함수
////////////////////////////////////////////
int sum_2(int a, int b)
{
	return a + b;
}
int comp_2(int a, int b)
{
	return a - b;
}
void print_2(int t1, int t2)
{
	cout << "합:" << t1 << endl << "차:" << t2 << endl;
}
////////////////////////////////////////////

// 10번함수
////////////////////////////////////////////
int KFC_10(int _target)
{
	for (size_t i = 0; i < sizeof(g_vect) / sizeof(g_vect[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(g_vect[0]) / 4; ++j)
		{

			if (_target == g_vect[i][j])
			{
				return 1;
			}
		}
		return 0;
	}
}
////////////////////////////////////////////

int main()
{

	// Level11

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int a = input_1();
		int b = input_1();
		int c = input_1();
		cals_1(a, b, c);
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int iinput1;
		int iinput2;
		cin >> iinput1;
		cin >> iinput2;
		print_2(sum_2(iinput1, iinput2) , comp_2(iinput1, iinput2));
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int a;
		char gd;
		cin >> a;
		cin >> gd;
		int* p = &a;
		char* t = &gd;

		cout << *p << " " << *t <<endl;
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		char a, b, c;
		cin >> a >>b >>c;
		char* pa, *pb, *pc;
		pa = &a;
		pb = &b;
		pc = &c;
		++(*pa);
		++(*pb);
		++(*pc);

		cout << a << " " << b << " " << c << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int a, b;
		int* p, * t;
		cin >> a >> b;
		p = &a;
		t = &b;
		int itemp;
		itemp = *p;
		*p = *t;
		*t = itemp;
		cout << *p << " " << *t << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int arr[7] = { 3,4,1,3,2,7,3 };
		int iinput = 0;
		cin >> iinput;
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			if (iinput == arr[i])
			{
				cout << "발견" << endl;
				break;
			}
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int arr[7] = { 4,1,5,2,3,2,2 };
		int imax, imin;
		imax = arr[0];
		imin = arr[0];
		for (size_t i = 1; i < sizeof(arr) / 4; ++i)
		{
			if (imax < arr[i])
			{
				imax = arr[i];
			}
			else if (imin > arr[i])
			{
				imin = arr[i];
			}
		}
		cout << "max=" << imax << endl << "min=" << imin << endl;
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		char arr[13] = { 's','t','r','u','c','t','p','o','i','n','t','e','r' };
		char chinput;
		cin >> chinput;
		for (size_t i = 0; i < sizeof(arr); ++i)
		{
			if (chinput == arr[i])
			{
				cout << "발견" << endl;
				break;
			}
			if (i == sizeof(arr) - 1 )
			{
				cout << "미발견" << endl;
			}
		}
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		char arr[8] = {};
		char big[8] = {};
		char small[8] = {};
		for (size_t i = 0; i < sizeof(arr); ++i)
		{
			cin >> arr[i];
		}
		int bigidx = 0;
		int smallidx = 0;
		for (size_t i = 0; i < sizeof(arr); ++i)
		{
			if (65 <= arr[i] && 90 >= arr[i])
			{
				big[bigidx++] = arr[i];				
			}
			else if (97 <= arr[i] && 122 >= arr[i])
			{
				small[smallidx++] = arr[i];
			}
		}
		cout << "big=";
		for (size_t i = 0; i < bigidx; ++i)
		{
			cout << big[i] << "";
		}
		cout << endl;
		cout << "small=";
		for (size_t i = 0; i < smallidx; ++i)
		{
			cout << small[i] << " ";
		}
		cout << endl;
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		int iTarget = 0;
		cin >> iTarget;
		if (1 == KFC_10(iTarget))
		{
			cout << "값이 존재합니다" << endl;
		}
		else if (0 == KFC_10(iTarget))
		{
			cout << "값이 없습니다" << endl;
		}

	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		int arr[4][4] = { {1,3,6,2},{4,2,4,5},{6,3,7,3},{1,5,4,6} };
		int select[16];
		int selectidx = 0;
		int iInput = 0;
		cin >> iInput;

		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				if (iInput < arr[i][j])
				{
					select[selectidx++] = arr[i][j];
				}
			}
		}
		for (size_t i = 0; i < selectidx; ++i)
		{
			cout << select[i] << " ";
		}
		cout << endl;

	}




	return 0;
}