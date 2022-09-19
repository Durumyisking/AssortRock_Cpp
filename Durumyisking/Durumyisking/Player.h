#include <iostream>
#include "status.h"

class CPlayer
{
public:
	CPlayer(int _iLevel);

private:
	Status status;

public:
	inline void PrintHp();  // 자주쓰는 함수를 여기에 inline함수로 선언해주면 좋음
							// inline 키워드를 붙이면 빌드단계에서 함수를 사용한곳 안에 구현부코드 자체가 들어감
							// 그래서 그냥 헤더나 클래스같은거 안거치고 바로 함수를 사용하는것

public:
	void PrintLevel();
	void SetLevel(int _iLevel);
};

