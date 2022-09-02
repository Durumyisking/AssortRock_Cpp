#pragma once


typedef struct _Node
{
	/*
노드 구성요소
-데이터
-다음노드 (포인터)
*/
	int idata;
	_Node* pNextNode;

}NODE, *NODE;

class CLinkedList
{

	/*
	리스트 구성요소
	-노드
	-끝노드
	-size
	
	pushback

	*/

private:
	NODE* Begin;
	NODE* End;
	int iSize;



public:
	CLinkedList();
	~CLinkedList();

public:
	void PushBack(NODE* pNode, int _idata);

};

