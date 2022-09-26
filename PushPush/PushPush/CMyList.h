#pragma once


template <typename T>
struct Node
{
	Node()
		: Data(NULL)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}
	Node(const T _Data)
		: Data(_Data)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}
	~Node()
	{

	}

	T Data;
	Node<T>* pNext;
	Node<T>* pPrev;
};




template <typename T>
class CMyList
{
public:
	CMyList()
		: m_pBegin(nullptr)
		, m_pEnd(nullptr)
		, m_iCount(0)
	{
		m_pBegin = new Node<T>();
		m_pEnd = new Node<T>();

		m_pBegin->pNext = m_pEnd;
		m_pBegin->pPrev = nullptr;

		m_pEnd->pNext = nullptr;
		m_pEnd->pPrev = m_pBegin;
	}
	CMyList(const CList& _Other)
		: m_pBegin(_Other.m_pBegin)
		, m_pEnd(_Other.m_pEnd)
		, m_iCount(_Otehr.m_iCount)
	{
	}
	~CMyList()
	{
		while (nullptr != m_pBegin)
		{
			Node<T>* ptr = nullptr;
			ptr = m_pBegin;
			m_pBegin = m_pBegin->pNext;

			delete ptr;
			ptr = nullptr;
		}

		m_iCount = 0;
	}
public:
	void Push_Back(T& _Data)
	{
		Node<T>* pNewNode = new Node<>();
		pNewNode->Data = _Data;

		if (m_iCount = 0)
		{
			m_pBegin->Data = _Data;
			++m_iCount;
			return;
		}

		Node<T>* NextNode = m_pBegin->pNext;
		while (m_pEnd != NextNode)
		{
			NextNode = NextNode.pNext;
		}
		NextNode.pNext = pNewNode;
		pNewNode->pNext = m_pEnd;
		pNewNode->pPrev = NextNode;
		m_pEnd->pPrev = pNewNode;

		++m_iCount;
	}


private:
	Node* m_pBegin;
	Node* m_pEnd;
	UINT  m_iCount;
};

