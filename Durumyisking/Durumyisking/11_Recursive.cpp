#include <iostream>

void recursion(int _iLevel)
{
	if (5 == _iLevel)
	{
		return;
	}
	// 자기 자신을 호출
	recursion(_iLevel + 1);
	std::cout << _iLevel;

}

void MyRecursion(int _iLevel)
{
	if (3 == _iLevel)
	{
		return;
	}
	MyRecursion(_iLevel + 1);
	std::cout << _iLevel;
}

void dfs(int _iLevel)
{
	if (2 == _iLevel)
	{
		return;
	}
	dfs(_iLevel + 1);
	dfs(_iLevel + 1);
}



int main()
{

	//recursion(0);
	//MyRecursion(-1);
	dfs(0);


	return 0;
}