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
	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		run_1(0, value_1[0]);
		cout << minValue_1;
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;

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

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;

	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;

	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;

	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;

	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;

	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;

	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;

	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;

	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;

	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;

	}


	return 0;
}