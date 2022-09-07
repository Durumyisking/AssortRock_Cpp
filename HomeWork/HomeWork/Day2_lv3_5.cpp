#include <iostream>

using namespace std;


int main()
{
	// Level 3.5

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		for (int i = 3; i < 9; ++i)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << iInput;
			}
			++iInput;
			cout << endl;
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int iInput1;
		int iInput2;
		int iInput3;
		int iInput4;
		cin >> iInput1;
		cin >> iInput2;
		cin >> iInput3;
		cin >> iInput4;

		if (1 == iInput1 && 2 == iInput2 && 3 == iInput3 && 4 == iInput4)
		{
			cout << "로그인성공" << endl;
		}
		else
		{
			cout << "로그인실패" << endl;
		}
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		iInput += 2;
		for (int i = 0; i < 3; ++i)
		{
			cout << iInput++;
		}
		cout << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int iInput1;
		int iInput2;
		int iInput3;
		cin >> iInput1;
		cin >> iInput2;
		cin >> iInput3;

		if (iInput1 > iInput2 && iInput1  > iInput3)
		{
			cout << "MAX발견" << endl;
		}
		else
		{
			cout << "MAX아님" << endl;
		}
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int iInput1;
		int iInput2;
		int iResult;
		cin >> iInput1;
		cin >> iInput2;
		iResult = iInput1 * iInput2;
		if (30 < iResult && 50 > iResult)
		{
			cout << "적당한사이즈" << endl;
		}
		else if (50 <= iResult)
		{
			cout << "큰 사이즈" << endl;
		}
		else if(30 >= iResult)
		{
			cout << "작은 사이즈" << endl;
		}
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int a;
		int x;
		cin >> a;
		cin >> x;

		for (int i = 0; i < x; ++i)
		{
			cout << --a << " ";
		}
		cout << endl;
	}
	

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;
		int a;
		int b;
		int c;
		cin >> a;
		cin >> b;
		cin >> c;

		for (int i = a; i <= b; ++i)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = a; i <= c; ++i)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;
		for (int i = 9; i > 5; --i)
		{
			cout << i << " " << i - 3 << endl;
		}
	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;
		int iInput = 0;
		int iOutput = 1;
		cin >> iInput;

		for (int i = 0; i < iInput; ++i)
		{
			cout << iOutput << " ";
			iOutput += 2;
		}
		cout << endl;
	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;
		cout << "시작" << endl;
		for (int i = 1; i <= 5; ++i)
		{
			cout << i;
		}
		cout << endl << "종료" << endl;
	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < iInput; ++j)
			{
				if (0 == i)
				{
					cout << "#";
				}
				else if (1 == i)
				{
					cout << "@";
				}
			}
			cout << endl;
		}
	}

	// 13번
	{
		cout << "///////////////13번///////////////" << endl;
		for (int i = 1; i <= 5; ++i)
		{
			cout << i << "번go!!" << endl;
		}
	}

	// 14번
	{
		cout << "///////////////14번///////////////" << endl;
		int iId = 0;
		int iPwd = 0;
		cin >> iId;
		cin >> iPwd;

		if (1111 == iId && 2222 == iPwd)
		{
			cout << "로그인성공" << endl;
		}
		if (1111 != iId)
		{
			cout << "아이디가 틀렸습니다" << endl;
		}
		if (2222 != iPwd)
		{
			cout << "비밀번호가 틀렸습니다" << endl;
		}
	}

	// 15번
	{
		cout << "///////////////15번///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		for (int i = iInput; i >= 0; --i)
		{
			cout << i;
		}
		cout << endl;
	}

	return 0;
}