#include <iostream>

// ��ó����
#define PI 3.141592

void print(int* arr)
{
	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}

int addition(int a, int b)
{
	return a + b;
}

int subtraction(int a, int b)
{
	return a - b;
}

void voidprint()
{

}


// �Լ��� ���ڷ� �Լ������ͺ����� ����ϱ⵵ ��
int operation(int x, int y, int(*funcCall)(int, int))
{
	int g = 0;
	g = funcCall(x, y);

	return g;
}



int main()
{
	//������

	int a = 0;
	void* p = &a;

	char ch = 'A';
	void* pCh = &ch;

	// ���⼭ p�� pCh�� ũ��� �� �� 32bit ���� 4����Ʈ�� ����

	// �迭�� ������
	// �迭�� �����ϸ� �޸𸮿� ���ӵ� �ּҷ� �������
	int arr[10] = {};
	print(arr); // arr[0]���� �ּҸ� �Ѱ��ذ� (�迭�� �̸��� �迭�� �ּ�)
	// ���� arr�� ��� ���� �ٲٰ������ arr�� ��簪(40����Ʈ)�� �Ѱ��ִ°� �ƴ϶�
	// ���� �ּ�(4����Ʈ)�� �Ѱ��༭ �Լ����� �� �ּҷ� ������ ���� ������� ��� ����

	// �����Ͱ� �����ϴ� ���� ����
	int num = 10;
	int* pnum = &num;
	*pnum;		// num �� 10������Ŵ
	*pnum = 5;	// �� ������ num�� �ּҸ� ����Ű�� pnum���� ����Ų ���̱� ������
				// �� �� ����� num�� �� ��ü�� �����


	int* pt =	nullptr; // �������� nullǥ��
	char ch =	'\0';
	int i	=	 0;

	char ch2 = NULL;


	int firstValue = 0;
	int secondValue = 0;
	int* p1 = nullptr;
	int* p2 = nullptr;

	p1 = &firstValue;
	p2 = &secondValue;

	*p1 = 10;
	*p2 = *p1;
	p1 = p2;
	*p1 = 20;

#pragma region ��ó����

	// ��ó���� ifdef

#ifdef PI
	std::cout << "PI�� ����Ǿ��־�� : " << PI << std::endl;
	//#elif
		// else ifdef

#else
	std::cout << "PI�� ����Ǿ����� �ʳ׿�" << std::endl;
#define PI 3.141592
#endif


	// ��ó���� pragma region
	/*
	#pragma region POINTER ARRAY
		int numbers[5];
		int* p = nullptr;

		p = numbers;
		p++;
		*p = 20;

		p = &numbers[2];
		*p = 30;

		p = numbers + 3;
		*p = 40;

	#pragma endregion
	*/
#pragma endregion

// 2��������
	int num = 100;
	int* pNum = &num;
	int** ppNum = &pNum;

	**ppNum = 200; // num�� �ּҰ� �����ϴ� ���� 200���� �ٲ�

	int arr2D[4][4] = {};

	// �迭 ������ -> �迭�� �������� ������ �ִ� ������
	// 
	int(*parr2D)[4] = arr2D;

	// ������ �迭 -> �����͸� ������ �ִ� �迭
	// ���⼭�� �迭�� �����͸� �־���
	int* pArrs[4] =
	{
		arr2D[0]
		,arr2D[1]
		,&arr2D[2][0]
		,&arr2D[3][0]
	};


	// �Լ� ������ ����
	int (*minus) (int, int); // ��ȯ���� int �Ű����ڰ� int, int�� �Լ��� ���� �� �ִ� pointer��

	minus = subtraction;

	void (*print)() = voidprint;

	// �Ű����ڷ� �Լ������͸� ���� �Լ� ���
	int sub, add;
	sub = operation(5, 5, subtraction);
	add = operation(5, 5, addition);


	return 0;
}