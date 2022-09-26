#include <iostream>
#include <cstring>

using namespace std;

string path;
char* cpath;
char cpath7[4];

// 1���Լ�
////////////////////////////////////////////
void BBQ_1(int _iLevel, int _iBranch)
{
	

	for (int i = 1; i <= 3; ++i)
	{
		switch (_iBranch)
		{
		case 1:
			path += 'A';
			break;
		case 2:
			path += 'B';
			break;
		case 3:
			path += 'C';
			break;
		default:
			break;
		}
		if (2 == _iLevel)
		{
			return;
		}
		BBQ_1(_iLevel + 1, i);
	}
}
////////////////////////////////////////////

// 3���Լ�
////////////////////////////////////////////
void BBQ_3(int _iLevel, int _iDest)
{

	if (_iDest == _iLevel)
	{
		cout << cpath <<endl;
		return;
	}
	
	cpath[_iLevel] = 'B';
	BBQ_3(_iLevel + 1, _iDest);
	cpath[_iLevel] = 0;

	cpath[_iLevel] = 'G';
	BBQ_3(_iLevel + 1, _iDest);
	cpath[_iLevel] = 0;

	cpath[_iLevel] = 'T';
	BBQ_3(_iLevel + 1, _iDest);
	cpath[_iLevel] = 0;

	cpath[_iLevel] = 'K';
	BBQ_3(_iLevel + 1, _iDest);
	cpath[_iLevel] = 0;

		
}
////////////////////////////////////////////

/////////////////////////////////////////

// 5���Լ�
////////////////////////////////////////////
void BBQ_5(int _iLevel,  int student)
{

	if (4 == _iLevel)
	{
		cout << cpath << endl;
		return;
	}
	for (size_t i = 0; i < student; i++)
	{
		cpath[_iLevel] = '1' + i;
		BBQ_5(_iLevel + 1, student);
		cpath[_iLevel] = 0;

	}
}
////////////////////////////////////////////

// 7���Լ�
////////////////////////////////////////////
void BBQ_7(int _iLevel, int* _count, char* input)
{
	int a = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (cpath7[i] == input[i])
		{
			++a;
		}
	}

	if (3 == a)
	{
		++(*_count);
		cout << *_count << "��°" << endl;
		return;
	}
	else if  (3 == _iLevel)
	{
		++(*_count);
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		cpath7[_iLevel] = 'A' + i;
		BBQ_7(_iLevel + 1, _count, input);
	}
}
////////////////////////////////////////////

int main()
{

	// Level

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		BBQ_1(0, 0);
		int endll = 0;
		for (size_t i = 0; i < path.length(); i++)
		{
			cout << path[i];
			++endll;
			if (2 == endll)
			{
				cout << endl;
				endll = 0;
			}
		}
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		string str[3];
		for (size_t i = 0; i < 3; i++)
		{
			cin >> str[i];
		}
		int count = 0;
		
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = i+1; j < 3; ++j)
			{
				if (str[i] == str[j])
					++count;
			}
		}
		switch (count)
		{
		case 0:
			cout << "BAD" << endl;
			break;
		case 1:
			cout << "GOOD" << endl;
			break;
		case 3:
			cout << "WOW" << endl;
			break;
		default:
			break;
		}

	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int input = 0;
		cin >> input;
		cpath = new char[10]();

		BBQ_3(0, input);
		delete[] cpath;

	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		string input;
		int floor = 0;
		for (size_t i = 0; i < 5; i++)
		{
			cin >> input;
			if ("up" == input)
			{
				++floor;
			}
			else if ("down" == input)
			{
				--floor;
			}
		}

		if (floor >= 0)
			cout << floor << endl;
		else
		{
			floor *= -1;
			cout << "B" << floor << endl;
		}
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int input = 0;
		cin >> input;
		cpath = new char[10]();

		BBQ_5(0, input);
		delete[] cpath;
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		string str[4] = {};
		int longidx, shortidx;
		longidx = 0;
		shortidx = 0;
		for (size_t i = 0; i < 4; i++)
		{
			cin >> str[i];
		}
		for (int i = 1; i < 4; ++i)
		{
			if (str[i].length() > str[longidx].length())
			{
				longidx = i;
			}
			else if (str[i].length() < str[shortidx].length())
			{
				shortidx = i;
			}
		}
		cout << "�乮�� : " << longidx << endl;
		cout << "ª������ : " << shortidx << endl;
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		int count = 0;
		char input[4];
		cin >> input;
		BBQ_7(0, &count, input);
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		int arr[3][2][2] = { { {2, 4}, {1, 5} }, { {2, 3}, {3, 6} }, { {7, 3}, {1, 5} } };
		int input = 0;
		cin >> input;
		int iMax = arr[input][0][0];
		int iMin = arr[input][0][0];

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; j++)
			{
				if (arr[input][i][j] > iMax)
				{
					iMax = arr[input][i][j];
				}
				if (arr[input][i][j] < iMin)
				{
					iMin = arr[input][i][j];
				}
			}
		}
		cout << "MAX : " << iMax << endl;
		cout << "MIN : " << iMin << endl;
	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		string str[5] = { "Jason", "Dr.tom", "EXEXI", "GK12P", "POW" };
		string input;
		int flag = 0;
		cin >> input;
		for (size_t i = 0; i < 5; i++)
		{
			if (str[i] == input)
			{
				cout << "��ȣ����" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "��ȣƲ��" << endl;
	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;

	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;

	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;

	}


	return 0;
}