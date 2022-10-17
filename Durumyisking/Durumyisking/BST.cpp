#include<iostream>

using namespace std;

int bst[100];

void insert(int _v, int _n = 1)
{
	if (bst[_n] == 0)
	{
		bst[_n] = _v;
		return;
	}
	if (bst[_n] >= _v)
	{
		insert(_v, _n * 2);
	}
	else
	{
		insert(_v, _n * 2 + 1);
	}
}

void search(int _v, int _n = 1)
{
	if (_n >= 100 || bst[_n] == 0)
	{
		cout << "미발견";
		return;
	}

	if (bst[_n] == _v)
	{
		cout << "발견";
		return;
	}

	if (bst[_n] >= _v)
		search(_v, _n * 2);
	else
		search(_v, _n * 2 + 1);
}

int main()
{

	insert(3);
	insert(5);
	insert(1);
	insert(2);
	insert(7);
	insert(4);

	search(4);

	return 0;
}