#include <iostream>


// ����ü
/*
	����ü�� ����� ���� �ڷ���
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
	// ����ü ����ϸ� �̷��� �� �ʿ䰡 ����

	Player warrior;
//	warrior.Class = "Warrior"; // �����Ҽ����� Lvalue�Դϴ�. ����
	warrior.iHp = 100;
	warrior.iMp = 50;
	warrior.pos.x = 5;
	warrior.pos.y = 5;

	Player mage = {}; // �̷��� �����ϸ�

	return 0;
}