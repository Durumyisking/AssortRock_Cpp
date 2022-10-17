#include <iostream>

using namespace std;

int heap[100];
int hn;

void push(int v)
{
	heap[++hn] = v;

	int now = hn;
	int parent;

	while (true)
	{
		parent = now / 2;
		if (1 == now) break;
		if (heap[parent] <= heap[now]) break;

		swap(heap[parent], heap[now]);
		now = parent;
	}
}

int main()
{
	push(3);
	push(5);
	push(2);
	push(4);
	push(1);
	push(6);
	return 0;
}