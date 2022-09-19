#include <iostream>

using namespace std;

struct Node
{
	int iData;
	Node* pNext;
	Node* pPrev;
};

typedef struct LinkedList
{
	Node* pBegin;
	int iCount;
}List;

void PushBack(List* _List, int _iData)
{
	Node* pNewNode = new Node;
	pNewNode->iData = _iData;
	pNewNode->pNext = nullptr;
	pNewNode->pPrev = nullptr;

	if (nullptr == _List->pBegin)
	{
		_List->pBegin = pNewNode;
	}
	else
	{
		Node* pNextNode = _List->pBegin;
		while (nullptr != pNextNode->pNext)
		{
			pNextNode = pNextNode->pNext;
		}
		pNextNode->pNext = pNewNode;
		pNewNode->pPrev = pNextNode;
	}
	++_List->iCount;
}

void PushFront(List* _List, int _iData)
{
	Node* pNewNode = new Node;
	pNewNode->iData = _iData;
	pNewNode->pNext = nullptr;
	pNewNode->pPrev = nullptr;
	
	if (nullptr == _List->pBegin)
	{
		_List->pBegin = pNewNode;
	}
	else
	{
		pNewNode->pNext = _List->pBegin;
		_List->pBegin->pPrev = pNewNode;
		_List->pBegin = pNewNode;
	}
	++_List->iCount;
}

void InputNode(LinkedList* _list, int _iData, int _iTarget)
{
	Node* pNewNode = new Node();
	pNewNode->iData = _iData;
	pNewNode->pNext = nullptr;
	pNewNode->pPrev = nullptr;
	
	if (nullptr == _list->pBegin)
	{
		_list->pBegin = pNewNode;
	}
	else
	{
		Node* pNode = _list->pBegin;
		while (nullptr != pNode)
		{
			if (_iTarget == pNode->iData)
			{
				Node* pNextNode = pNode->pNext;
				if (nullptr != pNode->pNext)
				{
					pNewNode->pNext = pNextNode;
					pNextNode->pPrev = pNewNode;
					pNode->pNext = pNewNode;
					pNewNode->pPrev = pNode;
				}
				else
				{
					pNode->pNext = pNewNode;
					pNewNode->pPrev = pNode;
				}
			}

			pNode = pNode->pNext;
		}
	}
	++_list->iCount;
}

void ReleaseNode(Node* _pNode)
{		
	if (nullptr == _pNode)
		return;

	ReleaseNode(_pNode->pNext);
	delete _pNode;
	_pNode = nullptr;
}

void ReleaseList(List* _pList)
{
	ReleaseNode(_pList->pBegin);
	_pList->iCount = 0;
	_pList->pBegin->pNext = nullptr;
	_pList->pBegin->pPrev = nullptr;
}

int main()
{
	List list = {};
	list.iCount = 0;
	list.pBegin = nullptr;

	for (int i = 0; i < 4; ++i)
		PushFront(&list, i);


	InputNode(&list, 10, 1);
	InputNode(&list, 10, 0);



	return 0;
}