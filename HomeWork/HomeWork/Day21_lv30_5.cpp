#include <iostream>
#include <vector>
using namespace std;

char path[10] = { };
char name[10] = {};
vector<int> result;



// 2���Լ�
////////////////////////////////////////////
void BBQ_2(int _lv, int _input)
{
	if (_input == _lv)
	{
		cout << path << endl;
		return;
	}
	path[_lv] = 'o';
	BBQ_2(_lv + 1, _input);
	path[_lv + 1, _input] = 0;

	path[_lv] = 'x';
	BBQ_2(_lv + 1, _input);
	path[_lv + 1, _input] = 0;

}
////////////////////////////////////////////


// 5���Լ�
////////////////////////////////////////////
void BBQ_5(int _lv, int _cnt, int _size)
{
	if (_lv == _cnt)
	{
		cout << path << endl;
		return;
	}

	for (size_t i = 0; i < _size; i++)
	{
		path[_lv] = *(name + i);
		BBQ_5(_lv + 1, _cnt, _size);
		path[_lv] = 0;
	}
}
////////////////////////////////////////////


// 6���Լ�
////////////////////////////////////////////
void BBQ_6(int _lv, char* pwd, int* rst)
{	
	if (_lv == 4)
	{
		int k = 0;;
		for (size_t i = 0; i < 4; i++)
		{
			if (pwd[i] == path[i])
				++k;
		}
		if (4 == k)
		{
			result.push_back(*rst);
			*rst = 0;
			return;
		}
		++(*rst);
		return;	
	}

	for (size_t i = 0; i < 26; i++)
	{
		path[_lv] = (char)(i + 65);
		BBQ_6(_lv + 1, pwd, rst);
		path[_lv] = 0;

	}
}
////////////////////////////////////////////

int main()
{

	// Level

	//// 1�� ����
	//{
	//	cout << "///////////////1��///////////////" << endl;
	//	int arr[2][2] = {
	//		{12, 9},
	//		{3,  6}
	//	}; // 90 : 9 6 12 3
	//	// 90���� ���� ���� 4�� ��������
	//	int angle;
	//	cin >> angle;
	//	int rep = (angle / 90) % 4;
	//	for (size_t i = 0; i < rep; i++)
	//	{
	//		int result[2][2] = {};

	//		result[0][0] = arr[0][1];
	//		result[0][1] = arr[1][1];
	//		result[1][1] = arr[1][0];
	//		result[1][0] = arr[0][0];

	//		arr[0][0] = result[0][0];
	//		arr[0][1] = result[0][1];
	//		arr[1][1] = result[1][1];
	//		arr[1][0] = result[1][0];
	//	}
	//	for (size_t i = 0; i < 2; i++)
	//	{
	//		for (size_t j = 0; j < 2; j++)
	//		{
	//			cout << arr[i][j] << " ";
	//		}
	//	}
	//	cout << endl;
	//}

	//// 2��
	//{
	//	cout << "///////////////2��///////////////" << endl;
	//	int input = 0;
	//	cin >> input;
	//	BBQ_2(0, input);
	//}

	//// 3��
	//{
	//	cout << "///////////////3��///////////////" << endl;
	//	int arr[6] = { 1,5,4,2,-5,-7 };
	//	int input = 0;
	//	cin >> input;
	//	int result[6] = {};
	//	int idx = 0;
	//	result[0] = arr[0];
	//	for (size_t i = 1; i < 6; i++)
	//	{
	//		if (result[idx] < arr[i])
	//		{
	//			int temp = result[idx];
	//			result[idx] = arr[i];
	//			result[idx + 1] = temp;
	//			idx = i;
	//		}
	//		else
	//		{
	//			result[i] = arr[i];
	//		}
	//	}
	//	cout << result[input - 1] << endl;
	//}

	//// 4��
	//{
	//	cout << "///////////////4��///////////////" << endl;	
	//	string arr[3] = {};
	//	int bigsize = 0;
	//	int big = 0;
	//	vector<int> bigidx;
	//	for (size_t i = 0; i < 3; i++)
	//	{
	//		cin >> arr[i];
	//		if (arr[i].size() >= bigsize)
	//		{
	//			bigsize = arr[i].size();
	//			bigidx.push_back(i);
	//		}
	//	}
	//	for (size_t i = 0; i < bigidx.size() - 1; i++)
	//	{
	//		for (size_t j = i; j < bigidx.size(); j++)
	//		{
	//			int r = arr[bigidx[i]].compare(arr[bigidx[j]]);

	//			if (1 == r)
	//				big = bigidx[i];
	//			else if (-1 == r)
	//				big = bigidx[j];
	//		}
	//	}
	//	cout << arr[big] << endl;		
	//}

	//// 5��
	//{
	//	cout << "///////////////5��///////////////" << endl;
	//	cin >> name;
	//	int cnt = 0;
	//	cin >> cnt;
	//	int size = 0;
	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		if ('\0' == name[i])
	//			break;
	//		++size;
	//	}
	//	BBQ_5(0, cnt, size);
	//}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int iCount = 0;
		int rst = 0;
		int cnt;
		cin >> cnt;
		char** pwd = new char*[4];
		for (size_t i = 0; i < 4; i++)
		{
			pwd[i] = new char[cnt];
		}
		for (size_t i = 0; i < cnt; i++)
		{
			cin >> pwd[i];
			BBQ_6(0, pwd[i],  &rst);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;

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