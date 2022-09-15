#include <iostream>
#include <cstring>


using namespace std;

// 1���Լ�
////////////////////////////////////////////
void bbq_1(int _iCount)
{
	// dfs??
	if (2 == _iCount)
		return;
	bbq_1(_iCount+1);
	bbq_1(_iCount+1);
	bbq_1(_iCount+1);
}
////////////////////////////////////////////

// 3���Լ�
////////////////////////////////////////////
void bbq_3(int _level, int _branch, int lvlstart, int branchstart)
{

	branchstart = 0;

	if (_level == lvlstart)
		return;
	for (int i = 0; i < _branch; ++i)
		bbq_3(_level, _branch, lvlstart + 1, ++branchstart);
	
}
////////////////////////////////////////////

// 4���Լ�
////////////////////////////////////////////
void bbq_4(int _lvl, int _iInput)
{
	cout << _lvl;

	if (_lvl == _iInput)
	{
		return;
	}
	bbq_4(_lvl+1, _iInput);
	bbq_4(_lvl+1, _iInput);
}
////////////////////////////////////////////

// 6���Լ�
////////////////////////////////////////////
void bbq_6(int _level, int _branch, int lvlstart, int branchstart, int* count)
{
	++(*count);
	branchstart = 0;

	if (_level == lvlstart)
		return;
	for (int i = 0; i < _branch; ++i)
		bbq_6(_level, _branch, lvlstart + 1, ++branchstart, count);

}
////////////////////////////////////////////

// 6���Լ�
////////////////////////////////////////////
void bbq_7(size_t _input)
{
	if ((1 != _input))
	{
		cout << _input << " ";
	}
	else 
	{
		cout << _input << " ";
		return;
	}
	bbq_7(_input - 1);
	cout << _input << " ";
}
////////////////////////////////////////////

int main()
{

	// Level21

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		bbq_1(0); // ����!
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		string id = "qlqlaqkq";
		string pwd = "tkaruqtkf";

		string idInput;
		string pwdInput;
		cin >> idInput;
		cin >> pwdInput;
		if (!(id.compare(idInput) || pwd.compare(pwdInput)))
		{
			cout << "LOGIN" << endl;
		}
		else
		{
			cout << "INVALID" << endl;
		}
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int level = 0;
		int branch = 0;
		cin >> level >> branch;
		bbq_3(level, branch,0,0);
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int n;
		cin >> n;
		bbq_4(0, n);
		cout << endl;
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		char arr[3][11] = {};
		size_t arrsize[3] = {};
		int iMax = 0;
		int iMaxidx = 0;

		for (int i = 0; i < 3; ++i)
		{
			cin >> arr[i];
			arrsize[i] = strlen(arr[i]);
			if (iMax < strlen(arr[i]))
			{
				iMax = strlen(arr[i]);
				iMaxidx = i;
			}
		}
		if (0 != iMaxidx)
		{
			char temp[11] = {};
			strcpy_s(temp, arr[iMaxidx]);
			strcpy_s(arr[iMaxidx], arr[0]);
			strcpy_s(arr[0], temp);
		}

		for (int i = 0; i < 3; ++i)
			cout << arr[i] << endl;
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int level = 0;
		int branch = 0;
		int iCount = 0;
		cin >> branch >> level;
		bbq_6(level, branch, 0, 0, &iCount);
		cout << iCount << endl;;
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		string str;
		cin >> str;
		bbq_7(str.size());
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		int count = 0;
		int x = 5;
		int y = 5;
		cin >> count;
		string* arr = new string[count];
		for (int i = 0; i < count; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < count; ++i)
		{
			if ("up" == arr[i])
			{
				--y;
			}
			if ("down" == arr[i])
			{
				++y;
			}
			if ("left" == arr[i])
			{
				--x;
			}
			if ("right" == arr[i])
			{
				++x;
			}
			if ("click" == arr[i])
			{
				cout << y << "," << x << endl;;
			}

		}

	}

	return 0;
}