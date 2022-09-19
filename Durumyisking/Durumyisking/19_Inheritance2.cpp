#include <iostream>

using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	Polygon()
	{
		cout << "Poly������" << endl;
	}
	~Polygon()
	{
		cout << "Poly�Ҹ���" << endl;
	}

public:
	virtual int area()
	{
		return 0;
	};
};

class Rect : public Polygon
{
public:
	Rect()
	{
		cout << "Rect������" << endl;
	}
	~Rect()
	{
		cout << "Rect�Ҹ���" << endl;
	}

public:
	virtual int area()
	{
		return width * height;
	}
};

class Tri : public Polygon
{
public:
	Tri()
	{
		cout << "Tri������" << endl;
	}
	~Tri()
	{
		cout << "Tri�Ҹ���" << endl;
	}
public:
	virtual int area() override
	{
		return (width * height)/2;
	}
};

int main()
{
	Polygon* rect = new Rect();
	Tri* tri = new Tri();

	rect->area();
	tri->area();

	delete rect;
	delete tri;
	
	return 0;
}