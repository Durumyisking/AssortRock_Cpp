#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[9] = { 3,1,2,1,3,2,1,2,1 };
int evid[7] = { -1, 0, 0, 1, 2, 4, 4 };
int timestamp[7] = { 8, 3, 5, 6, 8, 9, 10 };
int big = 0;
int start = 0;
char str1[15];
char str2[15];
char* strsmall;
char* strbig;



// 1번함수
////////////////////////////////////////////
void BBQ_1(int floor)
{
	if (floor > 8)
	{
		cout << "도착 " ;
		return;
	}
	cout << arr[floor] << " ";
	BBQ_1(arr[floor] + floor); // 3 0    1 3    3 4     2 7
	cout << arr[floor] << " ";

}
////////////////////////////////////////////

// 2번함수
////////////////////////////////////////////
void BBQ_2(int _evid)
{
	if (0 == _evid)
	{
		cout << "0번index(출발)" << endl;
		return;
	}
	BBQ_2(evid[_evid]);
	cout << _evid << "번index(" << timestamp[_evid] << "시)" << endl;
}
////////////////////////////////////////////


// 7번함수
////////////////////////////////////////////
void BBQ_7(int _lv, int _idx, int _life)
{

	for (size_t i = 0; i < 5; i++)
	{
		if (i == _idx && _life != 0)
			cout << _life;
		else
			cout << "_";
	}
	cout << endl;
	if (0 == _life || _lv > 4)
	{
		return;
	}

	BBQ_7(_lv + 1, _idx + 1, _life - 1);

}
////////////////////////////////////////////



// 9번함수
////////////////////////////////////////////
void BBQ_9(int _idxs, int _idxb, int* _cnt, int _start)
{
	if (strsmall[_idxs] != strbig[_idxb])
	{
		if (*_cnt > big)
		{
			big = *_cnt;
			start = _start;
		}
		return;
	}
	++(* _cnt);
	BBQ_9(_idxs + 1, _idxb + 1 ,_cnt, _start);

}
////////////////////////////////////////////


int main()
{

	// Level

//	// 1번
//	{
//		cout << "///////////////1번///////////////" << endl;
//		int input = 0;
//		cin >> input;
//		BBQ_1(input - 1);
//	}
//
//	// 2번
//	{
//		cout << "///////////////2번///////////////" << endl;
//		int input = 0;
//		cin >> input;
//		BBQ_2(input);
//	}
//
//	// 3번
//	{
//		cout << "///////////////3번///////////////" << endl;
//		int arr[3][3] = {};
//
//		for (size_t i = 0; i < 3; i++)
//		{
//			for (size_t j = 0; j < 3; j++)
//			{
//				cin >> arr[i][j];
//			}
//		}
//		for (size_t i = 0; i < 3; i++)
//		{
//			int cnt = 0;
//			for (size_t j = 0; j < 3; j++)
//			{
//				if (arr[i][0] == arr[i][j])
//				{
//					++cnt;
//				}
//				if (3 == cnt)
//					cout << arr[i][0] << endl;;
//			}
//			if (3 != cnt)
//				cout << "x" << endl;
//		}
//	}
//
//	// 4번
//	{
//		cout << "///////////////4번///////////////" << endl;
//		int arr1[5] = {0,0,0,0,INT_MAX};
//		int arr2[5] = { 0,0,0,0,INT_MAX };
//		int result[8] = {};
//		for (size_t i = 0; i < 4; i++)
//			cin >> arr1[i];
//		for (size_t i = 0; i < 4; i++)
//			cin >> arr2[i];
//
//		int idx = 0;
//		int idx1 = 0;
//		int idx2 = 0;
//		for (size_t i = 0; i < 4; i++)
//		{
//			for (size_t j = 0; j < 2; j++)
//			{
//				if (arr1[idx1] > arr2[idx2])
//				{
//					result[idx++] = arr2[idx2++];
//				}
//				else
//				{
//					result[idx++] = arr1[idx1++];
//				}
//			}
//		}
//		for (size_t i = 0; i < 8; i++)
//		{
//			cout << result[i] << " ";
//		}
//		cout << endl;
//	}
//
//	// 5번
//	{
//		cout << "///////////////5번///////////////" << endl;
//		int arr[4][5] = {};
//		int LTx = 0;
//		int LTy = 0;
//		int RBx = 0;
//		int RBy = 0;
//		int iFlag = 0;
//		for (size_t i = 0; i < 4; i++)
//		{
//			for (size_t j = 0; j < 5; j++)
//			{
//				cin >> arr[i][j];
//			}
//		}
//		for (size_t i = 0; i < 4; i++)
//		{
//			for (size_t j = 0; j < 5; j++)
//			{
//				if (1 == arr[i][j])
//				{
//					if (0 == iFlag)
//					{
//						LTx = i;
//						LTy = j;
//						iFlag = 1;
//					}
//
//					RBx = i;
//					RBy = j;
//				}
//			}
//		}
//		cout << "(" << LTx << ", " << LTy << ")" << endl;
//		cout << "(" << RBx << ", " << RBy << ")" << endl;
//
//	}

	// 6번 질문
	{
		cout << "///////////////6번///////////////" << endl;
		int input[4];
		vector<queue<int>> Q;
		int arr2[3][4] = {
			3,2,5,3,
			7,6,1,6,
			4,9,2,7,
		};
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				Q[i].push(arr2[j][i]);
			}
		}
		for (size_t j = 0; j < 4; j++)
		{
			cin>>input[j];
		}
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < input[i]; j++)
			{
				Q[i]
			}
		}

	}

	//// 7번
	//{
	//	cout << "///////////////7번///////////////" << endl;
	//	int worm[5] = { };
	//	int idx, life;
	//	cin >> idx >> life;
	//	BBQ_7(0, idx, life);
	//}

	//// 8번 질문
	//{
	//}

	//// 9번
	//{
	//	cout << "///////////////9번///////////////" << endl;
	//	cin >> str1 >> str2;
	//	int str1cnt = 0;
	//	int str2cnt = 0;
	//	int cnt = 0;

	//	for (size_t i = 0; i < 15; i++)
	//	{
	//		if (str1[i] != '\0')
	//			str1cnt++;
	//		if (str2[i] != '\0')
	//			str2cnt++;
	//	}
	//	int smallsize = str1cnt < str2cnt ? str1cnt : str2cnt;
	//	int bigsize = str1cnt > str2cnt ? str1cnt : str2cnt;

	//	strsmall = str1cnt < str2cnt ? str1 : str2;
	//	strbig = str1cnt > str2cnt ? str1 : str2;

	//	for (size_t i = 0; i < smallsize; i++)
	//	{
	//		for (size_t j = 0; j < bigsize; j++)
	//		{
	//			BBQ_9(i, j, &cnt, i);
	//			cnt = 0;
	//		}
	//	}
	//	for (size_t i = start; i < start+big; i++)
	//	{
	//		cout << strsmall[i];
	//	}
	//	cout << endl;

	//}

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