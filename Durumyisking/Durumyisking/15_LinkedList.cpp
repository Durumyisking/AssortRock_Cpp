#include <iostream>

using namespace std;

// �ܹ����
struct NodeDirect
{
	int data;
	NodeDirect* next;
};

// ����� ��ũ�帮��Ʈ
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
	// ���ο� ��� ����
	Node* newNode = new Node();
	newNode->iData = _iData;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	// ��� ���� ������
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
		// ������ Node�� Next�� ���� ������ newNode ����
		pNode->pNext = newNode;
		// newNode�� prev�� ������ Node �����Ѵ�.
		newNode->pPrev = pNode;
	}

	++_pList->iCount;
}

void insertNode(LinkedList* _pList, int _iData, int _iTarget)
{
	// ����
	// list�� ��������� (Head == null)
	// �� ������ ��忡 ���ԵǾ�����


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

// ��� �Ѱ��� release
// ����Լ�
void release_Node(Node* _pNode)
{
	// ������ ���� nullptr�ϰ���
	if (nullptr == _pNode) // == nullptr == _pNode->pNext
	{
		return;
	}

	release_Node(_pNode->pNext);
	delete _pNode;
	_pNode = nullptr; // �޸� ������ ���� nullptr ������� �ȱ׷��� �����Ⱚ�� ���ƿ� (�Ǽ�����)
						// nullptr ������ ��������� 0000000 / �ȳ����� �����Ⱚ��
}

// �ݺ��� ���鼭 ��带 �ϳ��� release
// Head���� �����ع����� ������� ��ġ�� ��Ծ����
// �׷��� �տ������� ����ߴ�
// �ٽ� ������ head�� �������ٰ� �ƴ��ݽ�
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
	// �ܹ��� ��ũ�帮��Ʈ
	/*
	NodeDirect* head = nullptr;
	head = new NodeDirect();

	head->data = 1;
	head->next = nullptr; // ��尡 ����Ű�� ��尡 ���� ����.

	head->next = new NodeDirect(); // ���ο� ��带 �����ϰ� head�� next���� ����
 	head->next->data = 2; // ���ٿ��� ������ ����� data�� 2 ����

	head->next->next = new NodeDirect();
	head->next->next->data = 3;
	*/
	

	// ����� ��ũ�帮��Ʈ
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