#include <iostream>

using namespace std;

int map[3][3] = {
	0,0,0,
	1,0,1,
	0,0,0,
};
int via[3][3];

void dfs(int l, int nx, int ny)
{
	int t;
	int dx, dy;
	int direct[4][2] = { {0, 1}, {-1, 0},  {0, -1},  {1, 0} };
	if (ny == 2 && nx == 2)
	{
		cout << "²ý";
		return;
	}

	for (t = 0; t < 4; ++t)
	{
		dy = ny + direct[t][0];
		dx = nx + direct[t][1];

		if (dy >= 0 && dy < 3 && dx >= 0 && dx < 3)
		{
			if (map[dy][dx] == 0)
			{
				if (via[dy][dx] == 0)
				{
					via[dy][dx] = 1;
					dfs(l + 1, dy, dx);
					via[dy][dx] = 0;
				}
			}
		}
	}
}

int main()
{
	dfs(0, 0, 0);





	return 0;
}