#include <iostream>


using namespace std;

// DFS
////////////////////////////////////////////
int value_1[7] = { 5,1,35,1,10,70,20 };
int map_1[7][7] = {
	0,1,1,0,0,0,0,
	0,0,0,1,0,1,0,
	0,0,0,0,1,0,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,0,1,
	0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,
};
int visit_1[7] = { 1 };
int minValue_1 = 21e8;


void run_1(int now, int sum)
{
	if (6 == now)
	{
		if (minValue_1 > sum) minValue_1 = sum;
		return;
	}
	for (int i = 0; i < 7; ++i)
	{
		if (map_1[now][i] == 0) continue;
		if (visit_1[i] == 1) continue;

		visit_1[i] = 1;
		run_1(i, sum + value_1[i]);
		visit_1[i] = 0;
	}
}
////////////////////////////////////////////


// BFS
////////////////////////////////////////////
int value_2[7] = { 5,1,35,1,10,70,20 };
int map_2[7][7] = {
	0,1,1,0,0,0,0,
	0,0,0,1,0,1,0,
	0,0,0,0,1,0,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,0,1,
	0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,
};
struct QueueNode {
	int nodeNum;
	int sum;
	int used[7];
} queue[20] = {0, value_2[0], {1}};
int head = 0;
int tail = 0;
int minValue_2 = 21e8;
////////////////////////////////////////////

int main()
{
	// Level
	// 
	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		run_1(0, value_1[0]);
		cout << minValue_1;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;

		while (head != tail)
		{
			QueueNode now = queue[++head];
			if (now.nodeNum == 6 && minValue_1 > now.sum)
				minValue_2 = now.sum;
			for (int i = 0; i < 7; i++)
			{
				if (map_2[now.nodeNum][i] == 0)continue;
				if (now.used[i] == 1)continue;

				queue[tail] = now;
				queue[tail].nodeNum = i;
				queue[tail].sum += value_2[i];
				queue[tail].used[i] = 1;
				tail++;
			}
		}
		cout << minValue_2;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;

	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;

	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;

	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;

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