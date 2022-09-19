#include <iostream>

using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	Polygon()
	{
		cout << "Poly持失切" << endl;
	}
	~Polygon()
	{
		cout << "Poly社瑚切" << endl;
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
		cout << "Rect持失切" << endl;
	}
	~Rect()
	{
		cout << "Rect社瑚切" << endl;
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
		cout << "Tri持失切" << endl;
	}
	~Tri()
	{
		cout << "Tri社瑚切" << endl;
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