#include <iostream>


using namespace std;

// 2���Լ�
////////////////////////////////////////////
void isSame_2(int* _pwd, int* _arr, int _iSize)
{
	for (int i = 0; i < _iSize; ++i)
	{
		if (_pwd[i] != _arr[i])
		{
			cout << "fail" << endl;
			return;
		}
	}
	cout << "pass" << endl;
}
////////////////////////////////////////////


int map[2][3] = { {3, 55, 42 }, {-5, -9, -10 } };
int pix[2][2] = {};

// 4���Լ�
////////////////////////////////////////////
int isPatten(int VAL)
{
	int flag = 0;
	for (size_t y = 0; y < 2; y++)
	{
		for (size_t x = 0; x < 3; y++)
		{
			if (map[y][x] == VAL)
			{
				flag = 1;
				return flag;
			}
		}
	}

	return flag ;
}
////////////////////////////////////////////


int main()
{

	/*
		1.	�� �� for���� ��� ����,
		2.	for���� ��Ȯ�� �� ���� �����ؼ� �� ���� ������,
		3.	� ���ǹ��� �ʿ�����?
		4.	������ ��� for���� �� ���� �� �� �ùķ��̼� �غ���	
	*/

	// Level17.5

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
	
		int vect[7] = { 3,5,4,2,6,6,5 }; // �� 10����
		int arrbit[7] = {};	// �� 2����
		for (int i = 0; i < 7; ++i)
		{
			cin >> arrbit[i];
		}
		for (int i = 0; i < 7; ++i)
		{
			// ���� ��ġ�� ��
			if (0 == arrbit[i])
			{
				vect[i] = 0;
			}
			else
			{
				vect[i] = 7;
			}
		}
		for (int i = 0; i < 7; ++i)
		{
			cout << vect[i];
		}
		cout << endl;
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		int pwd[4] = { 3,7,4,9 };
		int iinput[4] = {};
		for (int i = 0; i < 4; ++i)
			cin >> iinput[i];
		isSame_2(pwd, iinput, 4);
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int leveltable[4][2]{ {10, 20}, {30, 60}, {100, 150}, {200, 300} };
		int levelcount[4] = {};
		int arrfruit[6] = { };
		for (int i = 0; i < 6; ++i)
		{
			cin >> arrfruit[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (leveltable[i][0] <= arrfruit[j] && leveltable[i][1] >= arrfruit[j])
				{
					++levelcount[i];
				}
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			cout << "lev" << i << ":" << levelcount[i] << endl;
		}
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		// ���ڵ� ��
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				cin >> pix[i][j];

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				int ifind = 0;
				for (int i2 = 0; i2 < 2; ++i2)
				{
					for (int j2 = 0; j2 < 3; ++j2)
					{
						if (map[i2][j2] == pix[i][j])
						{
							cout << 'y' << " ";
							ifind = 1;
							break;
						}
					}
				}
				if (0 == ifind)
				{
					cout << 'n' << " ";
				}
			}
			cout << endl;
		}

		// ���ڵ�
		int flag = -1;
		for (size_t y = 0; y < 2; y++)
		{
			for (size_t x = 0; x < 2; y++)
			{
				if (isupper(pix[y][x]))
				{
				}
			}
		}
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int arr[6] = {};
		int arrbit[6] = { 1,0,1,0,1,0 };
		int minidx = 0;
		for (int i = 0; i < 6; ++i)
		{
			cin >> arr[i];
		}
		int imin = arr[0];

		for (int i = 0; i < 6; ++i)
		{
			if (0 == arrbit[i])
			{
				arr[i] = 0;
			}
			if (imin > arr[i] && 0 != arr[i])
			{
				imin = arr[i];
				minidx = i;
			}
		}
		cout << "arr[" << minidx << "]" << "=" << imin << endl;;
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int arr[3][3] = { {3,1,9},{7,2,1},{1,0,8} };
		int arrbit[3][3] = {};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{				
				cin >> arrbit[i][j];
			}
		}
		int iflag = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (0 == arrbit[i][j])
					continue;

				if (3 <= arr[i][j] && 5 >= arr[i][j])
				{
					iflag = 1;
					cout << "�߰�" << endl;
					break;
				}
			}
			if (1 == iflag)
				break;
		}
		if (0 == iflag)
			cout << "�̹߰�" << endl;
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		int arr[4] = { 3,5,4,2 };
		int arrbit[4] = {};
		int isum = 0;
		for (int i = 0; i < 4; ++i)
		{
			cin >> arrbit[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			if (1 == arrbit[i])
			{
				isum += arr[i];
			}
		}
		cout << isum << endl;
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		char arr[5][6] = { "ABCDE", "FGHIJ", "KLMNO", "PQRST", "UVWXY" };
		int y, x;
		y = 0;
		x = 0;

		char chInput;
		cin >> chInput;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (chInput == arr[i][j])
				{
					x = i - 2;
					y = j - 2;
				}
			}
		}
		cout << x << "," << y << endl;
	}

	return 0;
}