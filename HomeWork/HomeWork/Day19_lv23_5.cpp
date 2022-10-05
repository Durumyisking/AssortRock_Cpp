#include <iostream>
#include <vector>

using namespace std;

int bucket[255] = {};

void swap(int* _a, int* _b)
{
	int* temp = _a;
	_a = _b;
	_b = _a;
}

// 1번함수
////////////////////////////////////////////
int* bbq_1(int* _arr, char input)
{
	int arrResult[5] = {};
	if ('R' == input)
	{
		for (int i = 0; i < 4; i++)
		{
			arrResult[i + 1] = _arr[i];
		}
		arrResult[0] = _arr[4];
	}
	else if ('L' == input)
	{
		for (int i = 4; i > 0; i--)
		{
			arrResult[i - 1] = _arr[i];
		}
		arrResult[4] = _arr[0];
	}

	return arrResult;
}
////////////////////////////////////////////


// 5번함수
////////////////////////////////////////////
void bbq_5(vector<int> _vec, int _start, int _end)
{
	int lowidx = _start + 1;
	int highidx = _end - 1;
	int pivot = _vec[0];
	if (_end == _start || 1 == _end - _start)
	{
		return;
	}
	while (lowidx < highidx)
	{
		if (_vec[lowidx] > _vec[highidx])
		{
			//int temp = _vec[lowidx];
			//_vec[lowidx] = _vec[highidx];
			//_vec[highidx] = temp;
			swap(_vec[lowidx], _vec[highidx]);
		}
		++lowidx;
		--highidx;
	}
	swap(_vec[0], _vec[highidx]);

	bbq_5(_vec, 0, highidx);
	bbq_5(_vec, lowidx, _vec.size());

}
void DC(vector<int>& _vec)
{
	int lowidx = 1;
	int highidx = _vec.size() - 1;

	while (lowidx < highidx)
	{
		if (_vec[lowidx] > _vec[highidx])
		{
			swap(_vec[lowidx], _vec[highidx]);
		}
		++lowidx;
		--highidx;
	}
	if(highidx == lowidx)
		swap(_vec[0], _vec[highidx - 1]);
	else
		swap(_vec[0], _vec[highidx]);

}
////////////////////////////////////////////

int main()
{

	// Level

	// 1번
	{
		cout << "///////////////1번///////////////" << endl;
		int arr[5] = { 3,5,1,9,7 };
		char input;
		for (size_t i = 0; i < 4; i++)
		{
			cin >> input;
			int* temp = bbq_1(arr, input);
			for (size_t j = 0; j < 5; j++)
			{
				arr[j] = temp[j];
			}
		}
		for (size_t i = 0; i < 5; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// 2번
	{
		cout << "///////////////2번///////////////" << endl;
		char arr[4][3] = {};
		int pos[3][2] = {};
		for (size_t i = 0; i < 3; i++)
		{
			int x, y;
			cin >> x >> y;
			pos[i][0] = x;
			pos[i][1] = y;
			arr[y][x] = '#';
		}
		int iflag = 0;
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = i + 1; j < 3; j++)
			{
				if (pos[i][0] == pos[j][0] || pos[i][1] == pos[j][1])
				{
					iflag = 1;
					break;
				}
			}
			if (1 == iflag)
				break;
		}
		if (1 == iflag)
			cout << "위험" << endl;
		else if (0 == iflag)
			cout << "안전" << endl;
	}

	// 3번
	{
		cout << "///////////////3번///////////////" << endl;
		int arr[4][4] = {};
		for (int i = 0;  i < 3;  i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];

				if (i == j)
				{
					arr[3][3] += arr[i][j];
				}

				switch (j)
				{
				case 0:
					arr[3][0] += arr[i][j];
					break;
				case 1:
					arr[3][1] += arr[i][j];
					break;
				case 2:
					arr[3][2] += arr[i][j];
					break;
				default:
					break;
				}

				arr[i][3] += arr[i][j];
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 4번
	{
		cout << "///////////////4번///////////////" << endl;
		int arr[3][4] = { {3,5,4,1}, {1,1,2,3},  {6,7,1,2} };
		int input[4] = {};
		for (size_t i = 0; i < 4; i++)
		{
			cin >> input[i];
		}
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				for (size_t k = 0; k < 4; k++)
				{
					if (3 == k)
					{
						if (input[k] == arr[i][j])
						{
							arr[i][j] = input[0];
							break;
						}
					}
					else
					{
						if (input[k] == arr[i][j])
						{
							arr[i][j] = input[k + 1];
							break;
						}
					}
				}
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 5번
	{
		cout << "///////////////5번///////////////" << endl;
		int input = 0;
		vector<int> vec = {};
		for (int i = 0; i < 9; i++)
		{
			cin >> input;
			vec.push_back(input);
		}
		dc(vec);
//		bbq_5(vec, 0, vec.size());
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}

	// 6번
	{
		cout << "///////////////6번///////////////" << endl;
		char arrL[4][4];
		char arrR[4][5]{ "ABCD", "BBAB",  "CBAC",  "BAAA" };
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cin >> arrL[i][j];
				if (arrL[i][j] == arrR[i][j])
				{
					++bucket[arrL[i][j]];
				}
			}
		}
		int iMaxidx = 0;
		for (size_t i = 0; i < 255; i++)
		{
			if (bucket[i] > bucket[iMaxidx])
				iMaxidx = i;
		}
		cout << (char)iMaxidx << endl;
	}

	// 7번
	{
		cout << "///////////////7번///////////////" << endl;

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