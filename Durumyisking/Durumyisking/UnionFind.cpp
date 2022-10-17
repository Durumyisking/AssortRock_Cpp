#include <iostream>

using namespace std;

int name[200];
int n;
int group[200];
int gCnt;

void insert(char a, char b)
{
	// a�� b�� �׷��� ������ name�� a�� b�� �־���
	if (group[a] == 0) name[n++] = a;
	if (group[b] == 0) name[n++] = b;

	// a�׷��� �ְ� b�׷��� ������ b�� a�� �׷�
	if (group[a] != 0 && group[b] == 0)
		group[b] = group[a];
	else if (group[b] != 0 && group[a] == 0)
		group[a] = group[b];
	// a b �� �� �׷��� ������ a�� b������ ���ο� �׷�� ����
	else if (group[b] == 0 && group[a] == 0)
	{
		gCnt++;
		group[a] = gCnt;
		group[b] = gCnt;
	}
	else
	{
		// �� �� �׷��� ������ second ���ڸ� target�� ����
		int target = group[b];
		// ����Ÿ�� ������ŭ ���鼭
		for (size_t i = 0; i < n; i++)
		{
			// second ������ group�� ���� first ������ group���� �ű�
			if (group[name[i]] == target)
				group[name[i]] = group[a];
		}
	}

}

char parent[200];
char getParent(char ch)
{
	if (parent[ch] == 0) return ch;
	int ret = getParent(parent[ch]);
	parent[ch] = ret; // �̰ɷ� ����ȭ ����
	return ret;
}

void insert_R(char ch1, char ch2)
{
	int a = getParent(ch1);
	int b = getParent(ch2);
	if (a != b) parent[b] = a;
}

int main()
{
	insert_R('A', 'G');
	insert_R('H', 'C');
	insert_R('A', 'H');
	insert_R('F', 'D');
	insert_R('A', 'F');

	return 0;
}