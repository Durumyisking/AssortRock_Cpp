#include <iostream>

using namespace std;

char path[10];


// 1���Լ�
////////////////////////////////////////////
struct Node_1
{
	char ch;
	int data;
};

////////////////////////////////////////////

// 2���Լ�
////////////////////////////////////////////
void BBQ_2(int _lv, int _dest, int _child)
{
	if (_lv == _dest)
	{
		for (size_t i = 0; i < 10; i++)
		{
			if ('\0' != path[i])
				cout << path[i];
		}
		cout << endl;
		return;
	}

	for (size_t i = 0; i < _child; i++)
	{
		path[_lv + 1] = i + 48;
		BBQ_2(_lv + 1, _dest, _child);
		path[_lv + 1] = '0';

	}
};

////////////////////////////////////////////


int main()
{

	// Level 28.5

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		int count;
		cin >> count;
		Node_1* node = new Node_1[count];
		for (size_t i = 0; i < count; i++)
		{
			cin >> node[i].ch >> node[i].data;
		}

		for (size_t i = 0; i < count - 1; i++)
		{
			for (size_t j = i + 1; j < count; j++)
			{
				if (node[i].ch > node[j].ch)
				{
					Node_1 temp = node[i];
					node[i] = node[j];
					node[j] = temp;
				}
				else if (node[i].ch == node[j].ch)
				{
					if (node[i].data > node[j].data)
					{
						Node_1 temp = node[i];
						node[i] = node[j];
						node[j] = temp;
					}
				}
			}
		}

		for (size_t i = 0; i < count; i++)
		{
			cout << node[i].ch << " " << node[i].data << endl;
		}
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		int depth;
		int branch;
		cin >> depth >> branch;
		BBQ_2(0, depth, branch);
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int arr[2][6];
		int sum = 0;
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 6; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (size_t j = 0; j < 6; j++)
		{
			if(arr[0][j] + arr[1][j] < 10)
				arr[1][j] = arr[0][j] + arr[1][j];
			else
			{
				if (0 != j)
				{
					arr[1][j] = (arr[0][j] + arr[1][j]) % 10;
					++arr[1][j - 1];
				}
				else
				{
					cout << "���� ����" << endl;
					break;
				}
			}
		}
		for (size_t i = 0; i < 6; i++)
		{
			cout << arr[1][i] << " ";
		}
		cout << endl;
		
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int arr[5];
		for (size_t i = 0; i < 5; i++)
		{
			cin >> arr[i];
			if (0 != i && arr[i] < arr[i - 1])
			{
				cout << "���� �ȵ�" << endl;
				break;
			}
			if (4 == i)
				cout << "������" << endl;
		}
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int input;
		int arr[5] ={};
		int sum = 0;
		cin >> input;
		while (!(input >= 10000 && input <= 89999))
			cin >> input;

		for (size_t i = 0; i < 5; i++)
		{
			int cal = pow(10, i);
			arr[i] = input / cal % 10;
			++arr[i];
		}

		for (int i = 0; i < 5; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int bucket[255] = {};
		char ch[10] ={};
		for (size_t i = 0; i < 10; i++)
		{
			cin >> ch[i];
			++bucket[ch[i]];
		}
		for (size_t i = 0; i < 255; i++)
		{
			if (bucket[i] > 1)
				cout << (char)i;
		}
		cout << endl;

	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		int arr[4][3] = {
			3,5,1,
			3,1,2,
			3,4,6,
			5,4,6,
		};
		int bucket[10] = {};
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				++bucket[arr[i][j]];
			}
		}

		for (size_t i = 0; i < 10; i++)
		{
			if(0 != bucket[i])
				cout << i << " : ";
			for (size_t j = 0; j < bucket[i]; j++)
			{
				cout << "*" << " ";
			}
			cout << endl;
		}
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;

	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;

	}

	// 10��
	{
		cout << "///////////////10��///////////////" << endl;

	}

	// 11��
	{
		cout << "///////////////11��///////////////" << endl;

	}

	// 12��
	{
		cout << "///////////////12��///////////////" << endl;

	}


	return 0;
}