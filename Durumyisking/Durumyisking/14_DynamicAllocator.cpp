#include <iostream>


using namespace std;

struct Person
{
	int height;
	int age;
	char* name;
};


int main()
{
	// dynamic allocator

	// 1. malloc

	// malloc(바이트 크기) 반환형 void* 
	// void*는 단순하게 주소값만 저장할때 사용
	// void* p = malloc(4);
	int* p = (int*)malloc(4);
	*p = 100;

	int size = sizeof(int);

	Person a;
	// memset(포인터, 데이터, 크기) -> 포인터에 접근해서 크기만큼 데이터를 초기화시켜주겠다
	a.name = (char*)malloc(sizeof(char) * 10);
	memset(a.name, 0, sizeof(char) * 10); // a.name0번지부터 10바이트만큼 0으로 초기화하겠다.
	// 근데 이거 상당히 귀찮은걸?

	// calloc(count, 메모리크기) -> 메모리크기*count만큼 0번지부터 초기화시켜줌
	a.name = (char*)calloc(10, sizeof(char));

	// 메모리 해제
//	free(a.name);
	// 메모리 재할당하려면 메모리 해제후 다시 할당해야함

	// realloc(포인터, 데이터크기) 메모리 해제후 바로 재할당 해줌
	realloc(a.name, sizeof(char) * 10);

	// memcpy(목적지 포인터, 복사할 포인터, 크기) -> 복사할 포인터를 목적지 포인터의 0번부터 크기만큼 메모리 복사
	char babo[5] = "babo";
	memcpy(a.name, babo, 5); // -> a.name 의 0번 인덱스를 babo의 0번인덱스부터 차례대로 채움


	free(a.name);

	free(p);


	// 2. new (c++)

	// new + 자료형 
	int* ptr = new int; // 이럼 끝ㅋ

	int iarrSize = 0;
	cin >> iarrSize;
	int* pArr = new int[iarrSize]; // 이럼 내가 입력한대로 배열 사이즈 할당

	// 메모리 해제
	delete ptr;
	delete[] pArr;




	// 바이트패딩 (면접에 자주 나와요!)
	Person person; // 얘는 왜 12바이트 !? int int char이면 9바이트잖아요 !

	person.age = 0;
	person.height = 0;
	person.name = '\0';
	// person.age person.height person.name에 데이터를 넣기위해 몇바이트를 넣어야할까 고민하면 연산을 3번해야함 4 4 1
	// 이 연산횟수를 줄이기 위해서 그냥 제일큰놈이 4바이트네? 하고 다 4바이트로 간주해서 넣어버림

	return 0;
}