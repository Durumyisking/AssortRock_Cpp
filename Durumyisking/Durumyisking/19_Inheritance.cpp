#include <iostream>

using namespace std;

class GameObj
{
public:
	int iHp;
	int iMp;

	void Attack()
	{
	}
};

class Monster : public GameObj // 이 클래스 상속받을거야 ~ 라고 선언
{
private:
	int spawnTime;

protected:
	int iCount;

	// 클래스 접근 가능하게 할 클래스 지정
	friend class EventMonster;
};

class BossMonster : public Monster // 상속받은거 또 상속 가능
{
public:
	int SkillCoolTime;

public:
	void SetCount()
	{
		iCount++; // 여기서는 protected 변수 접근 가능
	}
};

class Player : public GameObj
{
public:
	int level; // Monster와 다른 멤버들을 선언

};

class NetWork
{
public:
	int ip;
	int port;
};

class EventMonster : public GameObj, NetWork
{

public:
	void SetSpawnTime(Monster monster)
	{
		monster.spawnTime = 1; // friend class 처리 하였기 때문에 private변수인 spawnTime에 접근 가능
	}
};

int main()
{
	Monster goblin, gnoll;
	goblin.Attack();
	Player player;
	player.iHp = 0; // 멤버로 안가지고 있지만 상속 받았기 때문에 사용 가능하다

	BossMonster vampire;
	vampire.iHp = 10; // 상속의 상속도 사용 가능
	//	vampire.spawnTime = 10; 사용 불가능
	//	vampire.iCount++; protected도 사용 불가능


	EventMonster eventmob;

	// 다중상속의 문제점
	GameObj* mons[10] = { (GameObj*) &goblin, &vampire, &gnoll, &eventmob};
	//					  형변환 생략 되어있음			        얘가 Gameobj상속인지 Network상속인지 모름

	
	return 0;
}