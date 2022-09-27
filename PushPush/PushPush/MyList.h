#pragma once


template <typename T>
struct tNode
{
	tNode()
		: Data(NULL)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}
	tNode(const T _Data)
		: Data(_Data)
		, pNext(nullptr)
		, pPrev(nullptr)
	{
	}
	~tNode()
	{

	}

	T Data;
	tNode<T>* pNext;
	tNode<T>* pPrev;
};




template <typename T>
class CMyList
{
public:
	// inner class
	class iterator
	{
	public:
		iterator()
			:m_pNode(nullptr)
		{
		}
		iterator(tNode<T>* _pNode)
			:m_pNode(_pNode)
		{
		}
		iterator(const iterator& _other)
			:m_pNode(_other.m_pNode)
		{
		}
		~iterator()
		{

		}

	public:
		tNode<T>* GetNode() { return m_pNode; }
		void SetNode(tNode<T>* _pNode) { m_pNode = m_pNode; }
		bool operator!= (iterator other)
		{
			return !(m_pNode == other.m_pNode);
		}

		bool operator== (iterator other)
		{
			return m_pNode == other.m_pNode;
		}
		iterator& operator++()
		{
			if (nullptr != m_pNode && nullptr != m_pNode->pNext)
			{
				m_pNode = m_pNode->pNext;
			}
			return *this;
		}
		iterator& operator++(int)
		{
			iterator iter(*this);
			if (nullptr != m_pNode && nullptr != m_pNode->pNext)
			{
				m_pNode = m_pNode->pNext;
			}
			return iter;
		}
		iterator& operator--() 
		{
			if(nullptr != m_pNode->pPrev)
				m_pNode = m_pNode->pPrev;
			return *this;
		}
		iterator& operator--(int) 
		{
			iterator temp = *this;
			if (nullptr != m_pNode->pPrev)
				m_pNode = m_pNode->pPrev;
			return temp;
		}
		iterator& operator=(iterator other)
		{
			m_pNode = other.m_pNode;
			return *this;
		}
		T& operator * ()
		{
			if (nullptr != m_pNode)
				return m_pNode->Data;
		}

	private:
		// 현재 가리키고있는 노드
		tNode<T>* m_pNode;
	};


public:
	CMyList()
		: m_pBegin(nullptr)
		, m_pEnd(nullptr)
		, m_iCount(0)
	{
		m_pBegin = new tNode<T>();
		m_pEnd = new tNode<T>();

		m_pBegin->pNext = m_pEnd;
		m_pBegin->pPrev = nullptr;

		m_pEnd->pNext = nullptr;
		m_pEnd->pPrev = m_pBegin;
	}
	CMyList(const CMyList& _Other)
		: m_pBegin(_Other.m_pBegin)
		, m_pEnd(_Other.m_pEnd)
		, m_iCount(_Other.m_iCount)
	{
	}
	~CMyList()
	{
		while (nullptr != m_pBegin)
		{
			tNode<T>* ptr = nullptr;
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
		tNode<T>* pNewNode = new tNode<T>(_Data);
		if (0 == m_iCount)
		{
			m_pBegin->Data = _Data;
		}
		else
		{
			tNode<T>* NextNode = m_pBegin;
			while (m_pEnd != NextNode->pNext)
			{
				NextNode = NextNode->pNext;
			}
			pNewNode->pPrev = NextNode;
			pNewNode->pNext = m_pEnd;

			m_pEnd->pPrev = pNewNode;
			NextNode->pNext = pNewNode;
		}
		++m_iCount;
	}
	void Push_Front(T& _Data)
	{
		tNode<T>* pNewNode = new tNode<T>(_Data);
		if (empty())
		{
			m_pBegin->Data = _Data;
		}
		else
		{
			pNewNode->pNext = m_pBegin;
			m_pBegin->pPrev = pNewNode;
			m_pBegin = pNewNode;
		}
		++m_iCount;

	}

	void Pop_Back()
	{
		tNode<T>* to_delete = m_pEnd->pPrev;
		if (m_pBegin != to_delete)
		{
			m_pEnd->pPrev = to_delete->pPrev;
			to_delete->pPrev->pNext = m_pEnd;

			delete to_delete;
			to_delete = nullptr;
		}
		else
		{
			m_pBegin->Data = NULL;
		}
		
		--m_iCount;

	}
	void Pop_Front()
	{
		tNode<T>* pNode = m_pBegin->pNext;

		if (m_pEnd == pNode)
		{
			m_pBegin->Data = 0;
		}
		else
		{
			delete m_pBegin;
			m_pBegin = nullptr;

			m_pBegin = pNode;
		}
		--m_iCount;

	}

	size_t size() { return m_iCount; }
	bool empty() { 
		return !m_iCount; 
	}
	void clear()
	{
		while (!empty())
		{
			Pop_Back();
		}
	}

	iterator begin() const { return iterator(m_pBegin); }
	iterator end() const { return iterator(m_pEnd); }
	iterator& erase (iterator& _iter) 
	{
		if (end() != _iter)
		{
			++_iter;
			Pop_Front();
		}

		return _iter;
	} // 숙제

private:
	tNode<T>* m_pBegin;
	tNode<T>* m_pEnd;
	size_t  m_iCount;
};

