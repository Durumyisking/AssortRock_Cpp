#include <iostream>

using namespace std;

// unsigned int�� SIZE��� �̸����� ����ϰڴ�.
typedef unsigned int SIZE;

// Ŀ���� �Լ�
void PrintNumber()
{
	// mainŬ������ �Լ� ����� ����� ����
	for (size_t i = 0; i < 10; ++i)
	{
		cout << i;
	}
}

int main()
{
	// �Լ� ����
	PrintNumber();

	SIZE d = -2; // unsigned int�� ���� ���Խ� -1 ��Ʈ�� ����϶��� ����

	return 0;

}