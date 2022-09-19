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

// �Լ� ���ø�
// ���⼭ T�� �ڷ��� type
template <typename T>
T add(T a, T b)
{
	return a + b;
}

// ���ø� Ư��ȭ
template <>
float add(float a, float b)
{
	// �̷� add�Լ��� ��ȯ�� float ���� (float, float) ������ ����� ��
	// �Ⱦ��� ����Ӥ�
	return (int)(a + b);
}

	
int main()
{
	// �Լ� ����
	PrintNumber();

	SIZE d = -2; // unsigned int�� ���� ���Խ� -1 ��Ʈ�� ����϶��� ����

	int result = add(5, 3);

	
	// ���ø�
	char ch = static_cast<char>(65); // �츮�� ����ϴ� static_cast�� <>�ȿ� T�� ������

	// add<T>(�Ű�����)
	float	fSum = add<float>(3.0f, 0.14159f);
	int		iSum = add<int>(5, 5);


	return 0;

}