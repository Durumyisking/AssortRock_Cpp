#include <iostream>
#include <cstring>

using namespace std;

class Vector2
{
public:
	int ix;
	int iy;

// 연산자 오버로딩
public:
	// 반환형 operator 연산자 (연산 상대)
	Vector2 operator + (Vector2 _vOther)
	{
		Vector2 ret;
		ret.ix = ix + _vOther.ix;
		ret.iy = iy + _vOther.iy;

		return ret;
	}

	bool operator == (Vector2 _vOther)
	{
		return (ix == _vOther.ix && iy == _vOther.iy);
	}

	// 전위 후위 나누기
	// 후위
	Vector2 operator ++(int) // 매개인자로 int 넣으면 후위
	{
		Vector2 ret;
		ret.ix = ix;
		ret.ix = iy;

		++ix;
		++iy;

		return ret;
	}

	// 전위
	Vector2& operator ++() // 전위연산은 반드시 참조로 받아야함
	{
		ix += 1;
		iy += 1;

		return *this;
	}
};

class MyString
{
public:
	char str[256];

	void InputString(const char* input)
	{
		strcpy(str, input);
	}

public:
	void operator += (const char* _chOther)
	{
		strcat_s(str, _chOther);
	}

};


int main()
{

	Vector2 vec1 = { 5, 5 };
	Vector2 vec2 = { 15, 15 };
	Vector2 vecResult = {};
	vecResult = vec1 + vec2; // operator를 만들어줬기 때문에 사용 가능

	string str = "Hello";
	str += "World"; // 이거 구현해보자

	MyString mystr = { "Hello" };
	mystr += "World"; // 잘됩니다.

	return 0;
}