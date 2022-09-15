#include <iostream>

using namespace std;

// 단방향용
struct NodeDirect
{
	int data;
	NodeDirect* next;
};

// 양방향 링크드리스트
struct Node
{
	int iData;
	Node* pPrev;
	Node* pNext;
};

struct LinkedList
{
	Node* pHead;
	// Node* pTail;
	int iCount;
};


void PushBack(LinkedList* _pList, int _iData)
{
	// 새로운 노드 생성
	Node* newNode = new Node();
	newNode->iData = _iData;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	// 노드 최초 생성시
	if (nullptr == _pList->pHead)
	{
		_pList->pHead = newNode;
	}
	else
	{
		Node* pNode = _pList->pHead;
		while (nullptr != pNode->pNext)
		{
			pNode = pNode->pNext;
		}
		// 마지막 Node의 Next에 새로 생성된 newNode 연결
		pNode->pNext = newNode;
		// newNode의 prev에 마지막 Node 연결한다.
		newNode->pPrev = pNode;
	}

	++_pList->iCount;
}

void insertNode(LinkedList* _pList, int _iData, int _iTarget)
{
	// 숙제
	// list가 비어있을때 (Head == null)
	// 맨 마지막 노드에 삽입되었을때


	Node* newNode = new Node();
	newNode->iData = _iData;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	Node* pNode = _pList->pHead;
		while (nullptr != pNode)
		{
			if (_iTarget == pNode->iData)
			{
				newNode->pNext = pNode->pNext;
				pNode->pNext->pPrev = newNode;
				pNode->pNext = newNode;
				newNode->pPrev = pNode;				
				break;
			}
			pNode = pNode->pNext;
		}
		++_pList->iCount;
}

// 노드 한개를 release
// 재귀함수
void release_Node(Node* _pNode)
{
	// 마지막 노드는 nullptr일것임
	if (nullptr == _pNode) // == nullptr == _pNode->pNext
	{
		return;
	}

	release_Node(_pNode->pNext);
	delete _pNode;
	_pNode = nullptr; // 메모리 해제후 꼭꼭 nullptr 해줘야함 안그러면 쓰레기값이 남아요 (실수방지)
						// nullptr 넣으면 출력했을때 0000000 / 안넣으면 쓰레기값이
}

// 반복문 돌면서 노드를 하나씩 release
// Head부터 해제해버리면 다음노드 위치를 까먹어버림
// 그래서 앞에서부터 해줘야댐
// 다시 일일히 head로 지정해줄거 아니잖슴
void release_list_reculsive(LinkedList* _pList)
{
	release_Node(_pList->pHead);

	_pList->pHead->pNext = nullptr;
	_pList->pHead->pPrev = nullptr;
}


void release_list(LinkedList* _pList)
{
	Node* pNode = _pList->pHead;
	while (nullptr != pNode)
	{
		Node* pNextNode = pNode->pNext; 
		delete pNode;
		pNode = nullptr;

		pNode = pNextNode;
	}
}

int main()
{
	// 단방향 링크드리스트
	/*
	NodeDirect* head = nullptr;
	head = new NodeDirect();

	head->data = 1;
	head->next = nullptr; // 헤드가 가리키는 노드가 아직 없다.

	head->next = new NodeDirect(); // 새로운 노드를 생성하고 head의 next노드로 지정
 	head->next->data = 2; // 윗줄에서 생성한 노드의 data에 2 삽입

	head->next->next = new NodeDirect();
	head->next->next->data = 3;
	*/
	

	// 양방향 링크드리스트
	LinkedList list;
	list.pHead = nullptr;
	list.iCount = 0;

	for (int i = 0; i < 5; ++i)
	{
		//PushBack(&list, i);
		PushBack(&list, i);
	}
	insertNode(&list, 100, 3);

	release_list(&list);

	return 0;
}