#include <iostream>
#include <cstring>

using namespace std;

string path;
char* cpath;
char cpath7[4];

// 1번함수
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

// 3번함수
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

// 5번함수
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

// 7번함수
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
		cout << *_count << "번째" << endl;
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

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
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

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
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

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int input = 0;
		cin >> input;
		cpath = new char[10]();

		BBQ_3(0, input);
		delete[] cpath;

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
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

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int input = 0;
		cin >> input;
		cpath = new char[10]();

		BBQ_5(0, input);
		delete[] cpath;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
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
		cout << "긴문장 : " << longidx << endl;
		cout << "짧은문장 : " << shortidx << endl;
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int count = 0;
		char input[4];
		cin >> input;
		BBQ_7(0, &count, input);
	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
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

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		string str[5] = { "Jason", "Dr.tom", "EXEXI", "GK12P", "POW" };
		string input;
		int flag = 0;
		cin >> input;
		for (size_t i = 0; i < 5; i++)
		{
			if (str[i] == input)
			{
				cout << "암호해제" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "암호틀림" << endl;
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;

	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;

	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;

	}


	return 0;
}