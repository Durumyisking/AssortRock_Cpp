#include <iostream>

int main()
{

	// Level 2

	// 1��
	std::cout << "1�ֵ����� � Ƚ���� �Է��Ͻÿ� : ";
	int iInput;
	std::cin >> iInput;
	std::cout << "��������!! Ī���մϴ�." << std::endl;

	// 2��
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> iInput;
	std::cout << iInput << " �Է��ϼ̱���" << std::endl;

	// 3��
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> iInput;
	std::cout << iInput << " "<< iInput << " " << iInput << std::endl;

	// 4��
	int a, b, c;
	std::cout << "a�� �Է��Ͻÿ� : ";
	std::cin >> a;
	std::cout << "b�� �Է��Ͻÿ� : ";
	std::cin >> b;
	std::cout << "c�� �Է��Ͻÿ� : ";
	std::cin >> c;
	std::cout << a << " " << a << " " << a << std::endl;
	std::cout << b << " " << b << " " << b << std::endl;
	std::cout << c << " " << c << " " << c << std::endl;

	// 5��
	int num1, num2;
	std::cout << "num1�� �Է��ϼ��� : ";
	std::cin >> num1;
	std::cout << "num2�� �Է��ϼ��� : ";
	std::cin >> num2;
	std::cout << "�� ������ ���� " << num1 - num2 << " �Դϴ�." << std::endl;

	// 6��
	std::cout << "num1�� �Է��ϼ��� : ";
	std::cin >> num1;
	std::cout << "num2�� �Է��ϼ��� : ";
	std::cin >> num2;
	std::cout << num1 << "+" << num2 << "=" << num1 + num2 << std::endl;
	std::cout << num1 << "*" << num2 << "=" << num1 * num2 << std::endl;
	std::cout << num1 << "/" << num2 << "=" << num1 / num2 << std::endl;

	// 7��
	std::cout << "a�� �Է��Ͻÿ� : ";
	std::cin >> a;
	std::cout << "b�� �Է��Ͻÿ� : ";
	std::cin >> b;
	if (a > b)
	{
		std::cout << "a�� b���� ũ��." << std::endl;
	}
	else
	{
		std::cout << "b�� a���� ũ�ų� ����." << std::endl;
	}

	// 8��
	std::cout << "num1�� �Է��ϼ��� : ";
	std::cin >> num1;
	std::cout << "num2�� �Է��ϼ��� : ";
	std::cin >> num2;

	if (num1 > num2)
	{
		std::cout << num1 << num1 << num1 << num1 << std::endl;
	}
	else if (num2 > num1)
	{
		std::cout << num2 << num2 << num2 << num2 << std::endl;
	}

	// 9��
	std::cout << "a�� �Է��Ͻÿ� : ";
	std::cin >> a;
	std::cout << a++ << " �Է���" << std::endl;
	std::cout << "a++�� �����ϸ�" << a << "�� �˴ϴ�." << std::endl;

	// 10��
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> iInput;
	if (iInput > 3)
	{
		iInput++;
		std::cout << iInput << std::endl;
	}
	else
	{
		iInput--;
		std::cout << iInput << std::endl;
	}

	// 11��
	int num;
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> num;

	if (num > 0)
	{
		std::cout << "###" << std::endl << "###" << std::endl << "###" << std::endl;
	}
	else if (num < 0)
	{
		std::cout << "$$$" << std::endl << "$$$" << std::endl;
	}
	
	// 12��
	std::cout << "ù��° ���ڸ� �Է��ϼ��� : ";
	std::cin >> a;
	std::cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
	std::cin >> b;
	std::cout << "����° ���ڸ� �Է��ϼ��� : ";
	std::cin >> c;

	if (a + b + c >= a * b * c)
	{
		std::cout << "����� ��" << std::endl;
	}
	else
	{
		std::cout << "�Ҽ��� ��" << std::endl;
	}

	return 0;
}