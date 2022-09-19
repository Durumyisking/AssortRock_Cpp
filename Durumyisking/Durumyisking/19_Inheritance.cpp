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

class Monster : public GameObj // �� Ŭ���� ��ӹ����ž� ~ ��� ����
{
private:
	int spawnTime;

protected:
	int iCount;

	// Ŭ���� ���� �����ϰ� �� Ŭ���� ����
	friend class EventMonster;
};

class BossMonster : public Monster // ��ӹ����� �� ��� ����
{
public:
	int SkillCoolTime;

public:
	void SetCount()
	{
		iCount++; // ���⼭�� protected ���� ���� ����
	}
};

class Player : public GameObj
{
public:
	int level; // Monster�� �ٸ� ������� ����

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
		monster.spawnTime = 1; // friend class ó�� �Ͽ��� ������ private������ spawnTime�� ���� ����
	}
};

int main()
{
	Monster goblin, gnoll;
	goblin.Attack();
	Player player;
	player.iHp = 0; // ����� �Ȱ����� ������ ��� �޾ұ� ������ ��� �����ϴ�

	BossMonster vampire;
	vampire.iHp = 10; // ����� ��ӵ� ��� ����
	//	vampire.spawnTime = 10; ��� �Ұ���
	//	vampire.iCount++; protected�� ��� �Ұ���


	EventMonster eventmob;

	// ���߻���� ������
	GameObj* mons[10] = { (GameObj*) &goblin, &vampire, &gnoll, &eventmob};
	//					  ����ȯ ���� �Ǿ�����			        �갡 Gameobj������� Network������� ��

	
	return 0;
}