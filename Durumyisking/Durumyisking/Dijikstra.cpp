#include <iostream>

using namespace std;

const int N = 666666;

int map[4][4] = {
	0, 50, N, 20,
	N, 0, 5, N,
	N, N, 0, N,
	N, 10, 25, N,
};

int result[4] = { 0, 50, N, 20 };
int via[4] = { 1,0,0,0 };

int findMin()
{
	int min = 21e8;
	int minidx;
	for (size_t i = 0; i < 4; i++)
	{
		if (via[i] == 0 && result[i] < min)
		{
			min = result[i];
			minidx = i;
		}
	}
	return minidx;
}

int main()
{
	int x, t;
	int min, minidx;

	for (size_t i = 0; i < 3; i++)
	{
		minidx = findMin();

		for (t = 0; t < 4; t++)
		{
			int a = result[minidx] + map[minidx][t];
			int b = result[t];

			if (a < b)
				result[t] = a;

		}
		via[minidx] = 1;
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}