#include <iostream>

using namespace std;

char path[10];
int path_[10];

// 4번함수
////////////////////////////////////////////
void DFS_4(int now, int size, int**arr)
{
	cout << now << " ";

	if (size == now)
		return;
	
	for (size_t i = 0; i < size; i++)
	{
		if (1 == arr[now][i])
		{
			DFS_4(i, size, arr);
		}
	}
}
////////////////////////////////////////////

// 5번함수
////////////////////////////////////////////
void DFS_5(int now, int* arr)
{
	if (0 == arr[now])
		return;

	cout << arr[now] << " ";

	if (6 < now * 2)
		return;


	DFS_5(now * 2, arr);
	DFS_5(now * 2 + 1, arr);

}
////////////////////////////////////////////

// 6번함수
////////////////////////////////////////////
void DFS_6(int _lv, int now, int size, int** arr)
{
	int cnt = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (0 == arr[now][i])
			++cnt;
	}

	if (size == cnt)
	{
		cout << path << endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (0 != arr[now][i])
		{
			path[_lv + 1] = i + 48;
			DFS_6(_lv + 1 ,i, size, arr);
			path[_lv + 1] = '0';

		}
	}

}
////////////////////////////////////////////


// 7번함수
////////////////////////////////////////////
void DFS_7(int lv, int now, int* arr)
{
	path_[lv] = arr[now];

	if (0 == arr[now] % 2)
	{
		for (size_t i = 0; i <= lv; i++)
		{
			cout << path_[i] << " ";
		}
		cout << endl;
		return;
	}

	if (6 < now * 2)
		return;


	DFS_7(lv+1,now * 2, arr);
	path_[lv + 1] = 0;

	DFS_7(lv+1,now * 2 + 1, arr);
	path_[lv + 1] = 0;
}
////////////////////////////////////////////

int main()
{

	// Level

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int size = 0;
		cin >> size;
		int** map = new int*[size];
		int boss = 0;
		int under[6] = {};
		for (size_t i = 0; i < size; i++)
		{
			map[i] = new int[size];
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				cin >> map[i][j];
			}
		}
		int idx = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (1 == map[0][i])
			{
				under[idx++] = i;
			}
			if (1 == map[i][0])
			{
				boss = i;
			}
		}
		cout << "boss : " << boss << endl;;
		cout << "under : ";
		for (size_t i = 0; i < idx; i++)
		{
			cout << under[i] << " ";
		}
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		int map[8][8] =
		{
			0,1,1,0,0,0,0,1,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,0,1,0,
			0,0,0,0,0,1,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
		};
		char input;
		cin >> input;
		for (size_t i = 0; i < 8; i++)
		{
			if (1 == map[i][input - 65])
			{
				for (size_t j = 0; j < 8; j++)
				{
					if (input - 65 != j && 1 == map[i][j])
					{
						cout << (char)(j + 65) << " ";
					}
				}
			}
		}
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		char map[8] = {' ', 'A', 'D', 'F', 'Z', 'C', 'G', 'Q' };
		char input1, input2;
		int idx1, idx2;
		cin >> input1 >> input2;
		for (size_t i = 1; i < 8; i++)
		{
			if (input1 == map[i])
				idx1 = i;
			if (input2 == map[i])
				idx2 = i;
		}
		if (idx1 > idx2)
		{
			int temp = idx1;
			idx1 = idx2;
			idx2 = temp;
		}
		if (map[idx1 * 2] == map[idx2] || map[idx1 * 2 + 1] == map[idx2])
		{
			cout << "부모자식관계" << endl;
		}
		else
			cout << "아님" << endl;
		
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int size = 0;
		cin >> size;
		int** map = new int* [size];
		for (size_t i = 0; i < size; i++)
		{
			map[i] = new int[size];
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				cin >> map[i][j];
			}
		}
		DFS_4(0, size, map);
		cout << endl;
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int arr[8] = { 0,3,4,2,4,1,0,3 };
		int idx, val;
		cin >> idx >> val;
		arr[idx] = val;
		DFS_5(1, arr);
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		int size = 0;
		cin >> size;
		int** map = new int* [size];
		for (size_t i = 0; i < size; i++)
		{
			map[i] = new int[size];
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				cin >> map[i][j];
			}
		}
		path[0] = 48;
		DFS_6(0,0, size, map);
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;
		int map[8] = {};
		for (size_t i = 0; i < 8; i++)
		{
			cin >> map[i];
		}
		DFS_7(0, 1, map);

	}

	// 8번
	{
		cout << "///////////////8번///////////////" << endl;

	}

	// 9번
	{
		cout << "///////////////9번///////////////" << endl;

	}

	// 10번
	{
		cout << "///////////////10번///////////////" << endl;

	}

	// 11번
	{
		cout << "///////////////11번///////////////" << endl;

	}

	// 12번
	{
		cout << "///////////////12번///////////////" << endl;

	}


	return 0;
}