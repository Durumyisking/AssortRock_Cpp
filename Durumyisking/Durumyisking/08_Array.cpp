#include <iostream>

// �迭

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;


	std::cout << a << b << c << d<<std::endl;

	int arr[4] = { 1,2,3,4 };
	// �ε��� : �����ϰ���� ��ġ arr[�ε���]
	arr[0] = 7;
	arr[3] = 100;
	// arr[4] = 500; �迭 ũ����� �ε����� ����

	// �迭�� �ݺ������� ���� ����� �����ϴ�.
	for (int i = 0; i < 4; ++i)
	{
		std::cout << arr[i] << std::endl;
	}


	return 0;
}