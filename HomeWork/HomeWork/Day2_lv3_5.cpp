#include <iostream>

using namespace std;


int main()
{
	// Level 3.5

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		for (int i = 3; i < 9; ++i)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
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

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
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
			cout << "�α��μ���" << endl;
		}
		else
		{
			cout << "�α��ν���" << endl;
		}
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		iInput += 2;
		for (int i = 0; i < 3; ++i)
		{
			cout << iInput++;
		}
		cout << endl;
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int iInput1;
		int iInput2;
		int iInput3;
		cin >> iInput1;
		cin >> iInput2;
		cin >> iInput3;

		if (iInput1 > iInput2 && iInput1  > iInput3)
		{
			cout << "MAX�߰�" << endl;
		}
		else
		{
			cout << "MAX�ƴ�" << endl;
		}
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int iInput1;
		int iInput2;
		int iResult;
		cin >> iInput1;
		cin >> iInput2;
		iResult = iInput1 * iInput2;
		if (30 < iResult && 50 > iResult)
		{
			cout << "�����ѻ�����" << endl;
		}
		else if (50 <= iResult)
		{
			cout << "ū ������" << endl;
		}
		else if(30 >= iResult)
		{
			cout << "���� ������" << endl;
		}
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
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
	

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
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

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		for (int i = 9; i > 5; --i)
		{
			cout << i << " " << i - 3 << endl;
		}
	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;
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

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;
		cout << "����" << endl;
		for (int i = 1; i <= 5; ++i)
		{
			cout << i;
		}
		cout << endl << "����" << endl;
	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;
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

	// 13��
	{
		cout << "///////////////13��///////////////" << endl;
		for (int i = 1; i <= 5; ++i)
		{
			cout << i << "��go!!" << endl;
		}
	}

	// 14��
	{
		cout << "///////////////14��///////////////" << endl;
		int iId = 0;
		int iPwd = 0;
		cin >> iId;
		cin >> iPwd;

		if (1111 == iId && 2222 == iPwd)
		{
			cout << "�α��μ���" << endl;
		}
		if (1111 != iId)
		{
			cout << "���̵� Ʋ�Ƚ��ϴ�" << endl;
		}
		if (2222 != iPwd)
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�" << endl;
		}
	}

	// 15��
	{
		cout << "///////////////15��///////////////" << endl;
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