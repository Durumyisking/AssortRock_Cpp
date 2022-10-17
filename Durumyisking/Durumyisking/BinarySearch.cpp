#include <iostream>
#include <algorithm>
#include <vector>

#include <map> // �� ���� insert �Ҷ� ������ �Ǿ ���Եȴ� (��ũ�帮��Ʈ�� ������ Ʈ������)
#include <unordered_map> // �� �׳� �ִ´�� �� (���ΰ� �迭�� �Ǿ����� (��Ȯ���� �ؽ����̺�))

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