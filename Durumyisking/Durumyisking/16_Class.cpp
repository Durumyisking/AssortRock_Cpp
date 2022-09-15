#include <iostream>

using namespace std;

class Node
{
public:
	// 생성자 // 객체가 메모리에 올라갈때 실행
	//*1번 생성자*/
	Node() 
		: iData(10) // 멤버 이니셜라이저
		, pNext(nullptr)
		, pPrev(nullptr)
	{
		// 멤버 이니셜라이저 먼저 실행후 여기 실행합니다.
		iData = 20;
		pNext = new Node(5); // 동적할당
	}

	//*2번 생성자*/
	// 생성자 오버로딩 // main함수에서 클래스 생성시 매개변수를 넣어주면 여기로 온다
	Node(int _iData)
		: iData(_iData)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}

	// 복사생성자 -> 사실 디폴트로 존재함
	Node(Node& _Nodedest)
		: iData(_Nodedest.iData)
		, pNext(nullptr) //, pNext(_Nodedest.pNext)
		, pPrev(nullptr) //, pPrev(_Nodedest.pPrev) // 포인터는 복사 안하는게 좋겠죠?
	{
		/*
		******** 중요 *********
		포인터 복사해오면
		원본의 포인터 그대로 복사해옴
		=> 복사본의 메모리를 해제하면
		=> 원본의 포인터도 같이 해제시켜줄거임
		그래서 포인터를 받아올때는 의도된게 아니라면 nullptr로  초기화 시켜야함
		*/
	}

	// Node() = default; // 무조건 default 생성자를 사용하겠다는 선언

	// 소멸자 // 객체가 메모리에서 해제될때 실행 (코드블럭을 탈출할때)
	~Node()
	{
		iData = 0;
		// 동적할당해준 pNext를 메모리에서 해제시켜준다
		delete pNext;
		pNext = nullptr;
		pPrev = nullptr;
	}

public:
	int iData;
	Node* pNext;
	Node* pPrev;

public:
	void inputData(int _iData)
	{
		// 클래스 내에서 멤버에 접근할때 다 앞에 this가 붙어있음
		// this : 자기자신을 가리키는 포인터
		this->iData = _iData;
	}

	void inputData_const (int _iData) const // 이렇게 매개인자 뒤에 const를 붙이면
	{
		// this->iData = _iData; // Node* const this => const Node* const this가 되므로 this의 값도 상수가 된다.


		Node* const _this = nullptr; // 사실 this는 이렇게 생긴놈임
		// _this = nullptr;  불가능
	}
};

class LinkedList
{
	// 멤버변수
public:
	Node* pHead;
	int iSize;

private:
	// 클래스 외부에서 접근 불가능
	int size;

public:
	// 멤버함수
	void inputData(int _iData)
	{
		pHead->iData = _iData;
	}
};

// 전역함수
void g_inputData(Node* _pNode, int _iData)
{
	_pNode->iData = _iData;
}


int main()
{
	LinkedList list;

	// 멤버함수 사용 class.function()
	// list. 으로 내가 누구인지 명시를 했기때문에 &list등으로 인자를 넘겨줄 필요가 없음
	list.inputData(3);

	Node Node1; // Node1의 1번 생성자 호출
	Node Node2 = new Node(5); // Node2의 2번 생성자 호출

	cout << Node2.iData;

	Node* pNode1 = new Node(); // pNode1의 생성자 호출
	Node* pNode2 = new Node(5); // pNode2의 2번생성자 호출

	// 복사생성자
	Node* pNodeCpy = new Node(*pNode2); // 전 복사생성자를 만든적이 없어요;;
										// 디폴트 복사생성자가 존재한다
	Node* pNodeCpy2 = pNode2;			// 이거도 디폴트생성자 오퍼레이터 쓴거임

	// 동적할당한 클래스는 delete로 메모리 해제할때 소멸자 호출됨
	delete pNode2; // 이때 pNode2의 소멸자 호출
	delete pNode1; // 이때 pNode1의 소멸자 호출

	return 0; // Node 2번생성자 호출 이후 Node의 1번 생성자 호출
}