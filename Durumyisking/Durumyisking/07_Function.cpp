#include <iostream>

using namespace std;

// unsigned int�� SIZE��� �̸����� ����ϰڴ�.
typedef unsigned int SIZE;

// Ŀ���� �Լ�
// ��ȯ�� �Լ���(��������)
void PrintNumber()
{
	// mainŬ������ �Լ� ����� ����� ����
	for (size_t i = 0; i < 10; ++i)
	{
		cout << i;
	}

	return; // void���� ��ȯ�� �ʿ���⶧���� �̳��� �����Ǿ�����
}

// �Լ� �����ε�
// ���� �Լ��� �̸��� ������ �Ű����ڰ� �޶� ���� ����
void PrintNumber(int num)
{
	cout << num;
}

// ���� �Լ��� �̸��� ������ ��ȯ�ڷ����� �޶� ���� ����
// _a, _b, result���־ 12����Ʈ ������
// ��� temp�� ������� ����ǰ� �� ���� main���� �Ѱ��ֱ⶧����
// 16����Ʈ�� ���ȴ�.
int add(int _a, int _b)
{
	int result = _a + _b;
	return result;
}

	
int main()
{
	// �Լ� ����
	PrintNumber();

	SIZE d = -2; // unsigned int�� ���� ���Խ� -1 ��Ʈ�� ����϶��� ����

	int result = add(5, 3);

	return 0;

}