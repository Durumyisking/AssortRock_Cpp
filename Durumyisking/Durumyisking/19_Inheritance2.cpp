#include <iostream>

using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	Polygon()
	{
		cout << "Poly생성자" << endl;
	}
	~Polygon()
	{
		cout << "Poly소멸자" << endl;
	}
	virtual ~Polygon()
	{
		cout << "가상 Poly소멸자" << endl; // 가상함수 사용하는 객체는 부모객체로 선언했기때문에 소멸자를 불러오지 않음
	}									  // 따라서 virtual을 붙인 부모 소멸자를 호출해야한다.

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
		cout << "Rect생성자" << endl;
	}
	~Rect()
	{
		cout << "Rect소멸자" << endl;
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
		cout << "Tri생성자" << endl;
	}
	~Tri()
	{
		cout << "Tri소멸자" << endl;
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

	rect->area(); // 부모포인터로 있지만 Rect의 area로 잘 찾아감
	tri->area();

	delete rect; // 부모에 vitual 소멸자를 만들었기 때문에 자신의 소멸자가 호출된다.
	delete tri;
	
	return 0;
}