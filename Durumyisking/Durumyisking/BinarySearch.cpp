#include <iostream>
#include <algorithm>
#include <vector>

#include <map> // 이 맵은 insert 할때 정렬이 되어서 삽입된다 (링크드리스트로 구현된 트리구조)
#include <unordered_map> // 얜 그냥 넣는대로 들어감 (내부가 배열로 되어있음 (정확히는 해시테이블))

using namespace std;
int vect[8] = { 1,1,2,5,7,9,15,20 };
int target = 7;

void run(int s, int e)
{
	int mid = (s + e) / 2;
	if(s>e)
	{
		cout<<"ss";
		return;
	}

	if (vect[mid] == target)
	{
		cout << "idx : " << mid;
		return;
	}
	if (vect[mid] < target)
	{
		run(mid + 1, e);
	}
	else
	{
		run(s, mid-1);
	}
}
int main()
{
	run(0, 7);

	return 0;
}