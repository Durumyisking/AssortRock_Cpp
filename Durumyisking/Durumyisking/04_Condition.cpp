#include <iostream>

int main()
{
    int x = 100;

    if (x == 50)
    {
        std::cout << "x�� 50�Դϴ�.";
    }
    else
    {
        std::cout << "x�� 50�� �ƴմϴ�.";
    }


    //1 ���� 2 ������ 3 �� 4 �Ʒ�

    int inputDirection = 0;
    inputDirection = 3;
    if (inputDirection == 1)
    {
        std::cout << "�������� 1ĭ�̵�" << std::endl;
    }
    else if (inputDirection == 2)
    {
        std::cout << "���������� 1ĭ�̵�" << std::endl;
    }
    else if (inputDirection == 3)
    {
        std::cout << "�������� 1ĭ�̵�" << std::endl;
    }
    else if (inputDirection == 4)
    {
        std::cout << "�Ʒ��� 1ĭ�̵�" << std::endl;
    }

    // ���� ���� ������� ������ �� �������� ������ �밢�� ������ ���� �����̰� �ϰ�ʹ� �ϸ�
    // ���� if������ �������

    if (inputDirection == 1)
    {
        std::cout << "�������� 1ĭ�̵�" << std::endl;
    }
    if (inputDirection == 2)
    {
        std::cout << "���������� 1ĭ�̵�" << std::endl;
    }
    if (inputDirection == 3)
    {
        std::cout << "�������� 1ĭ�̵�" << std::endl;
    }
    if (inputDirection == 4)
    {
        std::cout << "�Ʒ��� 1ĭ�̵�" << std::endl;
    }

    return 0;
}