#pragma once

typedef struct Vector2
{
	int ix;
	int iy;

	Vector2()
		:ix(0), iy(0)
	{
	}

	Vector2(int _ix, int _iy)
		:ix(_ix), iy(_iy)
	{
	}

public:
	Vector2 operator=(Vector2 _vOther)
	{
		this->ix = _vOther.ix;
		this->iy = _vOther.iy;
		return *this;
	}
}Pos;