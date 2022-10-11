#include <iostream>
using namespace std;

//
//// BFS 길찾기
//int map[5][6] =
//{
//	-1,-1,-1,-1,-1,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1, 0, 0, 0, 0,-1,
//	-1,-1,-1,-1,-1,-1,
//}; // npc나 몬스터 위치에 -1을 넣어 사용도 가능할것 다른 숫자를 넣고 조건을 추가시켜도 된다.
//   // 공격을하면 그 몬스터 숫자를 다시 0으로 바꿔버리면 ㅇㅇ..ㅇㅇ
//struct Node { int y, x; };
//Node queue[20];
//
//int head;
//int tail = 1;
//
//int dirY[4] = { -1, 0, 1, 0 };
//int dirX[4] = { 0, 1, 0, -1 };
///////////////////////////////////

// BFS 모든 경로 탐색
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
	//// BFS 길찾기
	//queue[0] = { 3,1 };
	//map[3][1] = 1;

	//while (head != tail)
	//{
	//	Node now = queue[head];

	//	for (int i = 0; i < 4; i++)
	//	{
	//		int dy = now.y + dirY[i]; // 이동
	//		int dx = now.x + dirX[i]; // 좌우 상하 모두 탐색할것

	//		//if (dy < 0 || dx < 0 || dy >= 3 || dx >= 4) continue; 
	//		// 이동할 위치가 벽을 넘어가거나 현재 위치가 맵의 벽 옆일때 벽뒤는 이동 무시
	//		// 근데 이 방법보다

	//		// 이 방법을 더 많이쓴다
	//		// 맵 전체 크기보다 위아래양옆으로 한칸씩 크게 만든후 -1같은 값으로 채워놓고
	//		// 탐색할때 그 값이면 이동 불가
	//		if (map[dy][dx] == -1)
	//			continue;
	//		if (map[dy][dx] > 0) continue; // 해당 map을 들렸던곳이면 continue

	//		map[dy][dx] = map[now.y][now.x] + 1; // 탐색했으니까 현재위치의 탐색순서 + 1을 넣어준다
	//		queue[tail++] = { dy, dx }; // 마지막 들른곳 좌표 저장
	//	} // 
	//	head++; // 제일 먼저 탐색했던 위치로 이동
	//	
	//}
	///////////////////////////////

	// BFS 모든 경로 탐색
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