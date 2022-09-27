#include <iostream>
#include <cstring>

using namespace std;
char name[4];
char path[5];
int Bucket[255]={};
int iCount = 0;
char bts[5] = { 'B', 'T', 'S', 'K', 'R'};
char boat[5] = { 'E', 'W', 'A', 'B', 'C' };
int card[5] = {};
char pathi[4] = {};
// 1번함수
////////////////////////////////////////////
void BBQ_1(int _level)
{
	if (_level == 3)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		
		if (0 != Bucket[*(name + i)])
			continue;

		path[_level] = *(name + i);
		++Bucket[*(name + i)];
		BBQ_1(_level + 1);
		--Bucket[*(name + i)];
	}
}
////////////////////////////////////////////

// 2번함수
////////////////////////////////////////////
void BBQ_2(int _level)
{
	if (_level == 4)
	{
		for (size_t i = 1; i < 4; i++)
		{
			if ((path[i-1] == 'B' && path[i] == 'T') || (path[i - 1] == 'T' && path[i] == 'B'))
			{
				return;
			}
		}
	
		++iCount;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		path[_level] = *(name + i);
		BBQ_2(_level + 1);
	}
}
////////////////////////////////////////////

// 3번함수
////////////////////////////////////////////
void BBQ_3(int _level, int _input)
{
	if (_level == _input)
	{
		for (size_t i = 0; i < 255; i++)
		{
			if (3 <= Bucket[i])
			{
				for (size_t i = 0; i < 255; i++)
					Bucket[i] = 0;
				return;
			}
		}
		++iCount;
		for (size_t i = 0; i < 255; i++)
			Bucket[i] = 0;

		return;
	}
	for (size_t i = 0; i < 3; i++)
	{
		path[_level] = 'A' + i;
		++Bucket['A' + 1];
		BBQ_3(_level + 1, _input);
	}
}
////////////////////////////////////////////

// 4번함수
////////////////////////////////////////////
void BBQ_4(int _level, int _input)
{
	if (_level == _input)
	{		
		for (size_t i = 0; i < _input; i++)
		{
			if ('S' == path[i])
				break;
			if (i == _input - 1)
				return;			
		}
		++iCount;
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (0 != Bucket[*(bts + i)])
			continue;

		path[_level] = *(bts + i);
		++Bucket[*(bts + i)];
		BBQ_4(_level + 1, _input);
		--Bucket[*(bts + i)];
	}
}
////////////////////////////////////////////

// 5번함수
////////////////////////////////////////////
void BBQ_5(int _level, char _input)
{
	if (_level == 4)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_input == path[i])
				return;
		}
		cout << path << endl;;
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (0 != Bucket[*(boat + i)])
			continue;

		path[_level] = *(boat + i);
		++Bucket[*(boat + i)];
		BBQ_5(_level + 1, _input);
		--Bucket[*(boat + i)];
	}
}
////////////////////////////////////////////

// 6번함수
////////////////////////////////////////////
void BBQ_6(int _level)
{
	if (_level == 4)
	{
		for (size_t i = 1; i < 4; i++)
		{
			if ((3 < path[i - 1] - path[i]) || (-3 > path[i - 1] - path[i]))
			{
				return;
			}
		}
		++iCount;
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		path[_level] = *(card + i);
		BBQ_6(_level + 1);
	}
}
////////////////////////////////////////////

int main()
{

	// Level

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		for (size_t i = 0; i < 4; i++)
		{
			cin >> name[i];
		}
		BBQ_1(0);
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		// 이전인덱스가 B면 Tpass T면 BPASS
		for (size_t i = 0; i < 4; i++)
		{
			cin >> name[i];
		}
		BBQ_2(0);
		cout << iCount << endl;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		iCount = 0;
		for (size_t i = 0; i < 255; i++)
		{
			Bucket[i] = 0;
		}
		int input;
		cin >> input;
		BBQ_3(0, input);
		cout << iCount<<endl;
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int input;
		iCount = 0;
		for (size_t i = 0; i < 255; i++)
		{
			Bucket[i] = 0;
		}
		cin >> input;
		BBQ_4(0, input);
		cout << iCount << endl;

	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		for (size_t i = 0; i < 255; i++)
		{
			Bucket[i] = 0;
		}
		for (size_t i = 0; i < 5; i++)
		{
			path[i] = '\0';
		}
		char input;
		cin >> input;
		BBQ_5(0, input);
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		for (size_t i = 0; i < 5; i++)
		{
			cin >> card[i];
		}
		iCount = 0;
		BBQ_6(0);
		cout << iCount << endl;
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;

	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;

	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;

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