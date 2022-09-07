#include <iostream>


// 구조체
/*
	구조체는 사용자 정의 자료형
*/

struct Pos
{
	int x;
	int y;
};


struct Player
{
	char Class[256];
	int iHp;
	int iMp;
	Pos pos;
};


int main()
{
	//char ArrClass[10][256];
	//int ArrHp[10];
	//int ArrMp[10];
	// 구조체 사용하면 이렇게 쓸 필요가 없음

	Player warrior;
//	warrior.Class = "Warrior"; // 수정할수없는 Lvalue입니다. 오류
	warrior.iHp = 100;
	warrior.iMp = 50;
	warrior.pos.x = 5;
	warrior.pos.y = 5;

	Player mage = {}; // 이렇게 선언하면

	return 0;
}