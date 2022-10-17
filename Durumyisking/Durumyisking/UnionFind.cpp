#include <iostream>

using namespace std;

int name[200];
int n;
int group[200];
int gCnt;

void insert(char a, char b)
{
	// a나 b의 그룹이 없으면 name에 a와 b를 넣어줌
	if (group[a] == 0) name[n++] = a;
	if (group[b] == 0) name[n++] = b;

	// a그룹은 있고 b그룹은 없으면 b는 a의 그룹
	if (group[a] != 0 && group[b] == 0)
		group[b] = group[a];
	else if (group[b] != 0 && group[a] == 0)
		group[a] = group[b];
	// a b 둘 다 그룹이 없으면 a와 b를위한 새로운 그룹들 생성
	else if (group[b] == 0 && group[a] == 0)
	{
		gCnt++;
		group[a] = gCnt;
		group[b] = gCnt;
	}
	else
	{
		// 둘 다 그룹이 있으면 second 인자를 target에 저장
		int target = group[b];
		// 데이타의 개수만큼 돌면서
		for (size_t i = 0; i < n; i++)
		{
			// second 인자의 group의 값을 first 인자의 group으로 옮김
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
	parent[ch] = ret; // 이걸로 최적화 가능
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