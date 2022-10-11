#include <iostream>
using namespace std;
//
//// 모든 경로 방문
//char value[6] = "TEQWA";
//int map[5][5] =
//{
//	0,1,0,0,0,
//	0,0,1,1,0,
//	0,0,0,0,0,
//	1,0,0,0,1,
//	0,0,0,0,0,
//}; 
//int visit[5];
//void run(int now)
//{
//	cout << value[now];
//
//	for (int i = 0; i < 5; i++)
//	{
//		if (map[now][i] == 1 && visit[i] == 0)
//		{
//			visit[i] == 1;
//			run(i);
//		}
//	}
//}
///// /////////////

// 모든 경로 출력
char value[7] = "ZADCEB";
int map[6][6] =
{
	0,1,1,1,0,0,
	1,0,0,1,0,1,
	1,0,0,1,0,0,
	1,1,1,0,1,1,
	0,0,0,1,0,1,
	0,1,0,1,1,0,
};
char path[10];
int visit[6];

void run(int _lv, int now)
{
	if (now == 5)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		if (map[now][i] == 1 && visit[i] == 0)
		{
			visit[i] == 1;
			path[_lv + 1] = value[i];
			run(_lv + 1, i);
			path[_lv + 1] = 0;
			visit[i] = 0;
		}
	}
}
/// /////////////


int main()
{
	visit[0] = 1;
	path[0] = value[0];
	run(0, 0);

	return 0;
}