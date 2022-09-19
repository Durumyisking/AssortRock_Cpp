#include <iostream>
#include <cstring>

using namespace std;

class Vector2
{
public:
	int ix;
	int iy;

// ������ �����ε�
public:
	// ��ȯ�� operator ������ (���� ���)
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

	// ���� ���� ������
	// ����
	Vector2 operator ++(int) // �Ű����ڷ� int ������ ����
	{
		Vector2 ret;
		ret.ix = ix;
		ret.ix = iy;

		++ix;
		++iy;

		return ret;
	}

	// ����
	Vector2& operator ++() // ���������� �ݵ�� ������ �޾ƾ���
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
	vecResult = vec1 + vec2; // operator�� �������� ������ ��� ����

	string str = "Hello";
	str += "World"; // �̰� �����غ���

	MyString mystr = { "Hello" };
	mystr += "World"; // �ߵ˴ϴ�.

	return 0;
}