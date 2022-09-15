#include <iostream>

using namespace std;

class Node
{
public:
	// ������ // ��ü�� �޸𸮿� �ö󰥶� ����
	//*1�� ������*/
	Node() 
		: iData(10) // ��� �̴ϼȶ�����
		, pNext(nullptr)
		, pPrev(nullptr)
	{
		// ��� �̴ϼȶ����� ���� ������ ���� �����մϴ�.
		iData = 20;
		pNext = new Node(5); // �����Ҵ�
	}

	//*2�� ������*/
	// ������ �����ε� // main�Լ����� Ŭ���� ������ �Ű������� �־��ָ� ����� �´�
	Node(int _iData)
		: iData(_iData)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}

	// ��������� -> ��� ����Ʈ�� ������
	Node(Node& _Nodedest)
		: iData(_Nodedest.iData)
		, pNext(nullptr) //, pNext(_Nodedest.pNext)
		, pPrev(nullptr) //, pPrev(_Nodedest.pPrev) // �����ʹ� ���� ���ϴ°� ������?
	{
		/*
		******** �߿� *********
		������ �����ؿ���
		������ ������ �״�� �����ؿ�
		=> ���纻�� �޸𸮸� �����ϸ�
		=> ������ �����͵� ���� ���������ٰ���
		�׷��� �����͸� �޾ƿö��� �ǵ��Ȱ� �ƴ϶�� nullptr��  �ʱ�ȭ ���Ѿ���
		*/
	}

	// Node() = default; // ������ default �����ڸ� ����ϰڴٴ� ����

	// �Ҹ��� // ��ü�� �޸𸮿��� �����ɶ� ���� (�ڵ���� Ż���Ҷ�)
	~Node()
	{
		iData = 0;
		// �����Ҵ����� pNext�� �޸𸮿��� ���������ش�
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
		// Ŭ���� ������ ����� �����Ҷ� �� �տ� this�� �پ�����
		// this : �ڱ��ڽ��� ����Ű�� ������
		this->iData = _iData;
	}

	void inputData_const (int _iData) const // �̷��� �Ű����� �ڿ� const�� ���̸�
	{
		// this->iData = _iData; // Node* const this => const Node* const this�� �ǹǷ� this�� ���� ����� �ȴ�.


		Node* const _this = nullptr; // ��� this�� �̷��� �������
		// _this = nullptr;  �Ұ���
	}
};

class LinkedList
{
	// �������
public:
	Node* pHead;
	int iSize;

private:
	// Ŭ���� �ܺο��� ���� �Ұ���
	int size;

public:
	// ����Լ�
	void inputData(int _iData)
	{
		pHead->iData = _iData;
	}
};

// �����Լ�
void g_inputData(Node* _pNode, int _iData)
{
	_pNode->iData = _iData;
}


int main()
{
	LinkedList list;

	// ����Լ� ��� class.function()
	// list. ���� ���� �������� ��ø� �߱⶧���� &list������ ���ڸ� �Ѱ��� �ʿ䰡 ����
	list.inputData(3);

	Node Node1; // Node1�� 1�� ������ ȣ��
	Node Node2 = new Node(5); // Node2�� 2�� ������ ȣ��

	cout << Node2.iData;

	Node* pNode1 = new Node(); // pNode1�� ������ ȣ��
	Node* pNode2 = new Node(5); // pNode2�� 2�������� ȣ��

	// ���������
	Node* pNodeCpy = new Node(*pNode2); // �� ��������ڸ� �������� �����;;
										// ����Ʈ ��������ڰ� �����Ѵ�
	Node* pNodeCpy2 = pNode2;			// �̰ŵ� ����Ʈ������ ���۷����� ������

	// �����Ҵ��� Ŭ������ delete�� �޸� �����Ҷ� �Ҹ��� ȣ���
	delete pNode2; // �̶� pNode2�� �Ҹ��� ȣ��
	delete pNode1; // �̶� pNode1�� �Ҹ��� ȣ��

	return 0; // Node 2�������� ȣ�� ���� Node�� 1�� ������ ȣ��
}