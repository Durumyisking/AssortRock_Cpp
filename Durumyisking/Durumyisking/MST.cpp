#include <iostream>

using namespace std;

struct Node
{
	char v1, v2;
	int val;
};

Node node[8] = {
	{'A', 'B', 6},
	{'A', 'C', 4},
	{'A', 'D', 5},
	{'C', 'B', 1},
	{'C', 'D', 3},
	{'C', 'E', 7},
	{'E', 'B', 3},
	{'E', 'D', 1},

};
int n = 8;
int parent[200];
void sort()
{
	int x, y;
	for (x = 0; x < n; x++)
	{
		;
		for (y = x+1; y < n; y++)
		{
			if (node[x].val > node[y].val)
			{
				swap(node[x], node[y]);
			}
		}
	}
}
int getParent(int ch)
{
	if (parent[ch] == 0) return ch;
	int ret = getParent(parent[ch]);
	parent[ch] = ret; // 이걸로 최적화 가능
	return ret;
}

int unionOrg(int i1, int i2)
{
	int p1 = getParent(i1);
	int p2 = getParent(i2);

	if (p1 == p2) return 0;
	parent[p1] = p2;
	return 1;
}

int main()
{
	// MST 최소 신장트리

	// 최소비용 순으로 sort
	sort();

	int cnt = 0;
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (unionOrg(node[i].v1, node[i].v2 == 1))
		{
			sum += node[i].val;
			cnt++;
		}
	}
	if (cnt == 4) cout << sum;

	return 0;
}