#include <iostream>


using namespace std;

int main()
{
	// reference
	// ����������
	int num = 200;
	int* pNum = &num; // �ʱ�ȭ�� �ݵ�� �ٸ� ���� �����ؾ���

	// �����Ѵٴ°���
	// �ּҿ��ٰ� �����̿��� �̸��� �� �ٿ��شٴ°�
	int& num2 = num; // ���⼭�� 200������ִ� ���� num�� num2��� �̸��� �߰��� �ٿ���
	num = 300;
	*(pNum) = 500;
	num2 = 800;



	return 0;
}