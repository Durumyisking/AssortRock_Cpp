#pragma once


typedef struct _Node
{
	/*
��� �������
-������
-������� (������)
*/
	int idata;
	_Node* pNextNode;

}NODE, *NODE;

class CLinkedList
{

	/*
	����Ʈ �������
	-���
	-�����
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

