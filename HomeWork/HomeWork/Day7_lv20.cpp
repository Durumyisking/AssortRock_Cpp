#include <iostream>
#include <string>

using namespace std;

// 1���Լ�
////////////////////////////////////////////
void bbq_1(int _iCount)
{
	// ����
	// ����üũ
	// return return return...
	++_iCount; // 1����

	if (4 == _iCount) // �Ű����ڰ� 3�̸� return
		return;

	bbq_1(_iCount);
}
////////////////////////////////////////////

// 2���Լ�
////////////////////////////////////////////
void bbq_2(int _iInput)
{
	int iTemp = _iInput;

	if (0 == iTemp)
	{
		cout << iTemp << " ";
		return;
	}


	cout << iTemp << " ";

	--_iInput;
	bbq_2(_iInput);

	cout << iTemp << " ";
}
////////////////////////////////////////////

// 3���Լ�
////////////////////////////////////////////
void bbq_3(int* _iArr, int _iIdx)
{
	int iTemp = _iIdx;

	if (5 == iTemp)
	{
		cout << _iArr[iTemp] << " ";
		return;
	}


	cout << _iArr[iTemp] << " ";

	++_iIdx;
	bbq_3(_iArr, _iIdx);

	cout << _iArr[iTemp] << " ";
}
////////////////////////////////////////////


// 4���Լ�
////////////////////////////////////////////
void bbq_4(int _iInput, int _iCount)
{	
	if (4 == _iCount)
		return;
	bbq_4(_iInput + 2, _iCount + 1);

	cout << _iInput << " ";
}
////////////////////////////////////////////

// 5���Լ�
////////////////////////////////////////////
void bbq_5(char* _arr, int _iCount)
{
	cout << _arr[_iCount];
	if (5 == _iCount)
	{
		cout << endl;
		return;
	}
	bbq_5(_arr, _iCount + 1);
	cout << _arr[_iCount];
}
////////////////////////////////////////////


// 6���Լ�
////////////////////////////////////////////
void bbq_6(int _a, int _b)
{
	if(_b != _a)
		cout << _a << " ";
	else
	{
		cout << _b << " ";
		return;
	}
	bbq_6(_a + 1, _b);
	cout << _a << " ";
}
////////////////////////////////////////////

// 7���Լ�
////////////////////////////////////////////
void bbq_7(int* _arr, int _idx)
{
	if (0 == _idx)
	{
		cout << _arr[_idx] << " ";
		return;
	}
	cout << _arr[_idx]<<" ";
	bbq_7(_arr, _idx-1);
	cout << _arr[_idx]<<" ";
}
////////////////////////////////////////////

// 8���Լ�
////////////////////////////////////////////
void bbq_8(int _input)
{
	if (0 == _input)
	{
		return;
	}
	bbq_8(_input/2);
	cout << _input << " ";
}
////////////////////////////////////////////
int main()
{	
	// Level20

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		bbq_1(0); // ����!
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		int n = 0;
		cin >> n;
		bbq_2(n);
		cout << endl;
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int iArr[6] = {};
		for (int i = 0; i < 6; ++i)
		{
			cin >> iArr[i];
		}
		bbq_3(iArr, 0);
	  cout<< endl;
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int n = 0;
		cin >> n;
		bbq_4(n, 0);
		cout << endl;
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		char input[6] = {};
		cin >> input;
		bbq_5(input, 0);
		cout << endl;	
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int a, b;
		cin >> a >> b;
		bbq_6(a, b);
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		int arr[8] = {3,7,4,1,9,4,6,2};
		int n;
		cin >> n;
		bbq_7(arr, n);
		cout << endl;
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		int n;
		cin >> n;
		bbq_8(n);
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