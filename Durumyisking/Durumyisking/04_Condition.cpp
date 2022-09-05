#include <iostream>

int main()
{
    int x = 100;

    if (x == 50)
    {
        std::cout << "x는 50입니다.";
    }
    else
    {
        std::cout << "x는 50이 아닙니다.";
    }


    //1 왼쪽 2 오른쪽 3 위 4 아래

    int inputDirection = 0;
    inputDirection = 3;
    if (inputDirection == 1)
    {
        std::cout << "왼쪽으로 1칸이동" << std::endl;
    }
    else if (inputDirection == 2)
    {
        std::cout << "오른쪽으로 1칸이동" << std::endl;
    }
    else if (inputDirection == 3)
    {
        std::cout << "위로으로 1칸이동" << std::endl;
    }
    else if (inputDirection == 4)
    {
        std::cout << "아래로 1칸이동" << std::endl;
    }

    // 만약 내가 만들려는 게임이 위 오른쪽을 누르면 대각선 오른쪽 위로 움직이게 하고싶다 하면
    // 전부 if문으로 해줘야함

    if (inputDirection == 1)
    {
        std::cout << "왼쪽으로 1칸이동" << std::endl;
    }
    if (inputDirection == 2)
    {
        std::cout << "오른쪽으로 1칸이동" << std::endl;
    }
    if (inputDirection == 3)
    {
        std::cout << "위로으로 1칸이동" << std::endl;
    }
    if (inputDirection == 4)
    {
        std::cout << "아래로 1칸이동" << std::endl;
    }

    return 0;
}