#include <iostream>

using namespace std;


int main()
{
	// Level4.5

	// 1��
	{
		cout << "///////////////1��///////////////" << endl;
		int arr[6] = { 3,2,6,7,1,8 };
		int iInput = 0;
		cin >> iInput;
		if (0 <= iInput && 5 >= iInput)
		{
			cout << arr[iInput] << endl;
		}
	}

	// 2��
	{
		cout << "///////////////2��///////////////" << endl;
		int iInput = 0;
		cin >> iInput;
		if (3 != iInput)
		{
			cout << "3�� �ƴϴ�" << endl;
		}
		if (5 != iInput)
		{
			cout << "5�� �ƴϴ�" << endl;
		}
		if (1 < iInput && 10 > iInput)
		{
			for (int i = 5; i > 0; --i)
			{
				cout << i << endl;;
			}
		}
	}

	// 3��
	{
		cout << "///////////////3��///////////////" << endl;
		int arr[5] = {};
		int iInput;
		cin >> iInput;
		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			arr[i] = iInput;
		}
		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// 4��
	{
		cout << "///////////////4��///////////////" << endl;
		int arr[5] = {1,7,3,2,6};
		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// 5��
	{
		cout << "///////////////5��///////////////" << endl;
		int arr[7] = {};
		int iSum = 0;
		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < 3; ++i)
		{
			iSum += arr[i];
		}
		cout << iSum << endl;
	}

	// 6��
	{
		cout << "///////////////6��///////////////" << endl;
		int arr[5] = { 3,9,12,15,55 };
		int arrInput[3] = {};
		int iSum = 0;
		for (int i = 0; i < sizeof(arrInput) / 4; ++i)
		{
			cin >> arrInput[i];
			iSum += arrInput[i];
		}
		if (10 < iSum)
		{
			int iLastIdx = (sizeof(arr) / 4) - 1;
			cout << arr[iLastIdx] << endl;
		}
		else
		{
			cout << arr[0] << endl;
		}
	}

	// 7��
	{
		cout << "///////////////7��///////////////" << endl;
		int arr[10] = { 5,7,1,8,-4,-73,4,2,20,84 };
		int iInput = 0;
		cin >> iInput;
		for (int i = iInput; i >= 0; --i)
		{
			cout << arr[i] << endl;
		}
	}

	// 8��
	{
		cout << "///////////////8��///////////////" << endl;
		int arr[6] = {};
		int iInput = 0;
		cin >> iInput;
		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			arr[i] = iInput++;
			cout << arr[i] << endl;
		}
	}

	// 9��
	{
		cout << "///////////////9��///////////////" << endl;
		int arr[4] = {};
		int a;
		int b;
		cin >> a;
		cin >> b;
		arr[0] = a;
		arr[2] = b;

		for (int i = 0; i < sizeof(arr) / 4; ++i)
		{
			cout << arr[i];
		}
		cout << endl;
	}


	return 0;
}