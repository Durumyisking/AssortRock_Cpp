#include <iostream>
#include <list>
#include <queue>
using namespace std;

int arr[6][2] = { {1,6 }, {3,8}, {8,9},  {2,4},  {4,6},  {7,9} };
int via[6] = {};
int max2 = 0;
int cnt = 0;

void fun(int _lv, int _time)
{
	if (0 >= _time - (arr[_lv][1] - arr[_lv][0]))
	{
		if (cnt > max2)
			max2 = cnt;

		return;
	}

	for (size_t i = 0; i < 6; i++)
	{
		if (via[i] == 0)
		{
			++cnt;
			_time = _time - (arr[_lv][1] - arr[_lv][0]);
			via[i] = 1;
			fun(i, _time);
			_time = _time + (arr[_lv][1] - arr[_lv][0]);
			--cnt;
			via[i] = 0;

		}
	}
}

int main()
{
	fun(0, 9);
	cout << max2;


	return 0;
}