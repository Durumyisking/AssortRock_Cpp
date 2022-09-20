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
	virtual ~Polygon()
	{
		cout << "���� Poly�Ҹ���" << endl; // �����Լ� ����ϴ� ��ü�� �θ�ü�� �����߱⶧���� �Ҹ��ڸ� �ҷ����� ����
	}									  // ���� virtual�� ���� �θ� �Ҹ��ڸ� ȣ���ؾ��Ѵ�.

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

	rect->area(); // �θ������ͷ� ������ Rect�� area�� �� ã�ư�
	tri->area();

	delete rect; // �θ� vitual �Ҹ��ڸ� ������� ������ �ڽ��� �Ҹ��ڰ� ȣ��ȴ�.
	delete tri;
	
	return 0;
}