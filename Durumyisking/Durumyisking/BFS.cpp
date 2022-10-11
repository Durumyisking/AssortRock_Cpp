#include <iostream>
using namespace std;

//
//// BFS ��ã��
//int map[5][6] =
//{
//	-1,-1,-1,-1,-1,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1,-1,-1,-1,-1,-1,
//}; // npc�� ���� ��ġ�� -1�� �־� ��뵵 �����Ұ� �ٸ� ���ڸ� �ְ� ������ �߰����ѵ� �ȴ�.
//   // �������ϸ� �� ���� ���ڸ� �ٽ� 0���� �ٲ������ ����..����
//struct Node { int y, x; };
//Node queue[20];
//
//int head;
//int tail = 1;
//
//int dirY[4] = { -1, 0, 1, 0 };
//int dirX[4] = { 0, 1, 0, -1 };
///////////////////////////////////

// BFS ��� ��� Ž��
char value[6] = "BQWER";
int map[5][5] = {
	0,1,0,1,0,
	0,0,1,0,1,
	0,0,0,0,1,
	0,0,0,0,1,
	0,0,0,0,0,
};

int cnt;
struct Node {
	int num;
	int used[5];
} queue[8];

int head;
int tail;


int main()
{
	//// BFS ��ã��
	//queue[0] = { 3,1 };
	//map[3][1] = 1;

	//while (head != tail)
	//{
	//	Node now = queue[head];

	//	for (int i = 0; i < 4; i++)
	//	{
	//		int dy = now.y + dirY[i]; // �̵�
	//		int dx = now.x + dirX[i]; // �¿� ���� ��� Ž���Ұ�

	//		//if (dy < 0 || dx < 0 || dy >= 3 || dx >= 4) continue; 
	//		// �̵��� ��ġ�� ���� �Ѿ�ų� ���� ��ġ�� ���� �� ���϶� ���ڴ� �̵� ����
	//		// �ٵ� �� �������

	//		// �� ����� �� ���̾���
	//		// �� ��ü ũ�⺸�� ���Ʒ��翷���� ��ĭ�� ũ�� ������ -1���� ������ ä������
	//		// Ž���Ҷ� �� ���̸� �̵� �Ұ�
	//		if (map[dy][dx] == -1)
	//			continue;
	//		if (map[dy][dx] > 0) continue; // �ش� map�� ��ȴ����̸� continue

	//		map[dy][dx] = map[now.y][now.x] + 1; // Ž�������ϱ� ������ġ�� Ž������ + 1�� �־��ش�
	//		queue[tail++] = { dy, dx }; // ������ �鸥�� ��ǥ ����
	//	} // 
	//	head++; // ���� ���� Ž���ߴ� ��ġ�� �̵�
	//	
	//}
	///////////////////////////////

	// BFS ��� ��� Ž��
	queue[0] = { 0, {1,0,0,0,0,} };
	tail = 1;

	while (head != tail)
	{
		Node now = queue[head++];
		if (value[now.num] == 'R') cnt++;

		for (int i = 0; i < 5; i++)
		{
			if (map[now.num][i] == 1 && now.used[i] == 0)
			{
				queue[tail] = now;
				queue[tail].num = i;
				queue[tail].used[i] = 1;
				tail++;
			}
		}
	}

	cout << cnt;
	return 0;
}