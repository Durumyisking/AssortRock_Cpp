#include <iostream>
#include "status.h"

class CPlayer
{
public:
	CPlayer(int _iLevel);

private:
	Status status;

public:
	inline void PrintHp();  // ���־��� �Լ��� ���⿡ inline�Լ��� �������ָ� ����
							// inline Ű���带 ���̸� ����ܰ迡�� �Լ��� ����Ѱ� �ȿ� �������ڵ� ��ü�� ��
							// �׷��� �׳� ����� Ŭ���������� �Ȱ�ġ�� �ٷ� �Լ��� ����ϴ°�

public:
	void PrintLevel();
	void SetLevel(int _iLevel);
};

