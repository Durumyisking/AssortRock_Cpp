#include <iostream>


using namespace std;


char g_arr[2][3] = { 'F', 'E', 'W', 'D', 'C', 'A' };

// 8번함수
////////////////////////////////////////////
void BBQ(int _iInput1, int _iInput2)
{
	cout<< "합:" << _iInput1 + _iInput2 << endl;
	cout<< "차:" << _iInput1 - _iInput2 <<endl;
	cout<< "곱:" << _iInput1 * _iInput2 <<endl;
	cout<< "몫:" << _iInput1 / _iInput2 <<endl;
}
////////////////////////////////////////////

// 9번함수
////////////////////////////////////////////
void findCh(char _target)
{
	for (size_t i = 0; i < sizeof(g_arr) / sizeof(g_arr[0]); ++i)
	{
		for (size_t j = 0; i < sizeof(g_arr[0]); ++j)
		{
			if (_target == g_arr[i][j])
			{
				cout << "발견" << endl;
				return;
			}
		}
	}
	cout << "미발견" << endl;
	return;
}
////////////////////////////////////////////

// 10번함수
////////////////////////////////////////////
void checkChar(char _target)
{
	if (65 <= _target && 90 >= _target)
	{
		cout<< "대" << endl;
	}
	else if (97 <= _target && 122 >= _target)
	{
		cout << "소" << endl;
	}
}
////////////////////////////////////////////


struct Person
{
	int age;
	int height;
};
// 11번함수
////////////////////////////////////////////
void Input(Person* _person)
{
	cin >> _person->age;
	cin >> _person->height;
}
void Output(Person* _person1, Person* _person2)
{
	int age = (_person1->age + _person2->age) / 2;
	int height = (_person1->height + _person2->height) / 2;

	cout << age << " " << height  << endl;
}
////////////////////////////////////////////


int main()
{

	// Level9

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int arr[8]{ 4,3,6,1,3,1,5,3 };
		int iInput = 0;
		int iCount = 0;
		cin >> iInput;
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			if (iInput == arr[i])
			{
				++iCount;
			}
		}
		cout << "숫자" << iInput << "개수는" << iCount << "개" << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		char arr[3][5] = 
			{ {'A','B','C','D','E'}
			,{'E','A','B','A','B'}
			,{'A','C','D','E','R'} };
		char chInput = '\n';
		int iCount = 0;
		cin >> chInput;
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]); ++j)
			{
				if (chInput == arr[i][j])
				{
					++iCount;
				}
			}
			
		}
		if (3 <= iCount)
		{
			cout << "대발견" << endl;
		}
		else if (0 < iCount && 2 >= iCount)
		{
			cout << "발견" << endl;
		}
		else if (0 == iCount)
		{
			cout << "미발견" << endl;
		}

	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		char arr[6] = { 'A','F','G','A','B','C' };
		char chInput1;
		char chInput2;
		cin >> chInput1;
		cin >> chInput2;
		int iBit = 0;
		for (size_t i = 0; i < sizeof(arr); ++i)
		{
			if (chInput1 == arr[i])
			{
				iBit ^= 1;
			}
			if (chInput2 == arr[i])
			{
				iBit |= 2;
			}
		}
		switch (iBit)
		{
		case 3:
			cout << "와2개" << endl;
			break;
		case 1: case 2:
			cout << "오1개" << endl;
			break;
		case 0:
			cout << "우0개" << endl;
			break;
		}
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[6] = { 3,4,2,5,7,9 };

		int a;
		int b;
		int iTemp;

		while(true)
		{
			cin >> a;
			if (0 <= a && 5 >= a)
			{
				break;
			}
		}
		while (true)
		{
			cin >> b;
			if (0 <= b && 5 >= b)
			{
				break;
			}
		}
		iTemp = arr[a];
		arr[a] = arr[b];
		arr[b] = iTemp;
		
		for (size_t i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout << arr[i] << " ";
		}		
		cout << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		struct ABC
		{
			int x;
			int y;
		};
		ABC t = {};
		cin >> t.x;
		cin >> t.y;
		cout << t.x + t.y << endl;
	}

	// 6번
	{
		struct Pos
		{
			int x;
			int y;
		};

		cout << "///////////////6번///////////////" << endl;
		char ch[3][3] = {};
		char chInput = 'A';
		Pos P1 = {};
		Pos P2 = {};
		int iTemp;
		cin >> P1.x;
		cin >> P1.y;
		cin >> P2.x;
		cin >> P2.y;

		for (size_t i = 0; i < sizeof(ch) / sizeof(ch[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(ch) / sizeof(ch[0]); ++j)
			{
				ch[i][j] = chInput;
				++chInput;
			}
		}
		iTemp = ch[P1.x][P1.y];
		ch[P1.x][P1.y] = ch[P2.x][P2.y];
		ch[P2.x][P2.y] = iTemp;

		for (size_t i = 0; i < sizeof(ch) / sizeof(ch[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(ch) / sizeof(ch[0]); ++j)
			{
				cout << ch[i][j];
			}
			cout << endl;
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int arr[6][2] = {};
		int iCount = 0;
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cin >> arr[i][j];
			}
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			if (arr[i][0] < arr[i][1])
			{
				int iTemp = arr[i][0];
				arr[i][0] = arr[i][1];
				arr[i][1] = iTemp;
				++iCount;
			}
		}
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		{
			for (size_t j = 0; j < sizeof(arr[0]) / 4; ++j)
			{
				cout << arr[i][j]<<" ";
			}
			cout << endl;
		}
		cout << iCount << "명" << endl;
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		int iInput1;
		int iInput2;
		cin >> iInput1;
		cin >> iInput2;
		BBQ(iInput1, iInput2);
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		char ch;
		cin >> ch;
		findCh(ch);
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		char ch[5] = {};
		for (size_t i = 0; i < sizeof(ch); ++i)
		{
			cin >> ch[i];
		}
		for (size_t i = 0; i < sizeof(ch); ++i)
		{
			checkChar(ch[i]);
		}
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;

		Person a;
		Person b;

		Input(&a);
		Input(&b);
		Output(&a, &b);
	}


	return 0;
}