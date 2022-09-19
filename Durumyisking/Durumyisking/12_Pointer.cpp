#include <iostream>

// 전처리기
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


// 함수의 인자로 함수포인터변수를 사용하기도 함
int operation(int x, int y, int(*funcCall)(int, int))
{
	int g = 0;
	g = funcCall(x, y);

	return g;
}



int main()
{
	//포인터

	int a = 0;
	void* p = &a;

	char ch = 'A';
	void* pCh = &ch;

	// 여기서 p와 pCh의 크기는 둘 다 32bit 기준 4바이트로 같음

	// 배열의 포인터
	// 배열을 선언하면 메모리에 연속된 주소로 만들어짐
	int arr[10] = {};
	print(arr); // arr[0]번의 주소를 넘겨준것 (배열의 이름은 배열의 주소)
	// 내가 arr의 모든 값을 바꾸고싶으면 arr의 모든값(40바이트)을 넘겨주는게 아니라
	// 시작 주소(4바이트)만 넘겨줘서 함수에서 그 주소로 접근해 적은 비용으로 사용 가능

	// 포인터가 참조하는 값에 접근
	int num = 10;
	int* pnum = &num;
	*pnum;		// num 즉 10을가리킴
	*pnum = 5;	// 이 변수는 num의 주소를 가리키는 pnum으로 가리킨 값이기 때문에
				// 이 값 변경시 num의 값 자체가 변경됨


	int* pt =	nullptr; // 포인터의 null표현
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

#pragma region 전처리기

	// 전처리기 ifdef

#ifdef PI
	std::cout << "PI가 선언되어있어요 : " << PI << std::endl;
	//#elif
		// else ifdef

#else
	std::cout << "PI가 선언되어있지 않네요" << std::endl;
#define PI 3.141592
#endif


	// 전처리기 pragma region
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

// 2중포인터
	int num = 100;
	int* pNum = &num;
	int** ppNum = &pNum;

	**ppNum = 200; // num의 주소가 참조하는 값을 200으로 바꿈

	int arr2D[4][4] = {};

	// 배열 포인터 -> 배열의 시작점을 가지고 있는 포인터
	// 
	int(*parr2D)[4] = arr2D;

	// 포인터 배열 -> 포인터를 가지고 있는 배열
	// 여기서는 배열의 포인터를 넣어줌
	int* pArrs[4] =
	{
		arr2D[0]
		,arr2D[1]
		,&arr2D[2][0]
		,&arr2D[3][0]
	};


	// 함수 포인터 변수
	int (*minus) (int, int); // 반환값이 int 매개인자가 int, int인 함수를 받을 수 있는 pointer임

	minus = subtraction;

	void (*print)() = voidprint;

	// 매개인자로 함수포인터를 가진 함수 사용
	int sub, add;
	sub = operation(5, 5, subtraction);
	add = operation(5, 5, addition);


	return 0;
}