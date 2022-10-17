#pragma once
#include <iostream>
using namespace std;

template <typename Tk, typename Tv>
class MyMap
{
public:
	struct Node
	{
		Tk Key;
		Tv value;
		Node* L;
		Node* R;

		int lv;

		Node()
			: Key(NULL) // dataŸ�� ���� intellisense �۵� �ȴ碌
			, value(NULL)
			, L(nullptr)
			, R(nullptr)
		{
		}

	};

public:
	MyMap()
		: m_pRoot(nullptr)
	{

	}
	~MyMap()
	{

	}

public:
	//////////////������ ����///////////////////////
	void insert(pair<Tk, Tv> _pair)
	{
		// ��Ʈ���� ��ȯ �����Ұ�
		// m_pRoot�� �����ϴ°� ó������ �۵���
		m_pRoot = insert(m_pRoot, _pair);
	}

	// ������ node�� ���ο� node�� ���ϰ��̴�.
	Node* insert(Node* _pNode, pair<Tk, Tv> _pair)
	{
		// ���� ����� ��ġ�� �������
		if (nullptr == _pNode)
		{
			// ���ο� ��� ����
			_pNode = new Node();
			_pNode->key = _pair.first;
			_pNode->value = _pair.second;
			_pNode->L = nullptr;
			_pNode->R = nullptr;
			++_pNode->lv;
		}
		// ���(DFS)�� �۵��Ѵ�.
		else
		{
			// ���� ����
			if (_pair.first < _pNode->key)
			{
				_pNode->L = insert(_pNode->L, _pair);
			}
			// �����ʻ��� (���Ƶ� ������ ������)
			else
			{
				_pNode->R = insert(_pNode->R, _pair);
			}
			_pNode = balance(_pNode);
		}
		return _pNode;
	}
/////////////////////////////////////////////////

///////////////////Ʈ�� ȸ��//////////////////////

	Node* ll(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->L;

		pTemp->L = pTemp->R;
		pTemp->R = _parent;

		return pTemp;
	}
	Node* rr(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->R;

		pTemp->R = pTemp->L;
		pTemp->L = _parent;

		return pTemp;
	}

	// �� �� RR �� �� LL �� �� ����
	Node* lr(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->L;
		// rrȸ��
		_parent->L = rr(pTemp);
		// llȸ��
		return ll(_parent);
	}
	Node* rl(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->R;
		// rrȸ��
		_parent->R = ll(pTemp);
		// llȸ��
		return rr(_parent);
	}
	// ������ ���̸� ����ؼ� Ʈ�� ������ ȸ����Ų��.
	Node* balance(Node* _Temp)
	{
		int factor = diff(_Temp);
		if (factor > 1)
		{
			// ������ ���̰� �� ���

			// LL ȸ��
			if (diff(_Temp->L) > 0)
			{
				_Temp = ll(_Temp);
			}
			// LR ȸ��
			else
			{
				_Temp = lr(_Temp);
			}
		}
		else if (factor < -1)
		{
			// �������� ���̰� �� ���

			// RL ȸ��
			if (diff(_Temp->R) > 0)
			{
				_Temp = rl(_Temp);
			}
			// RR ȸ��
			else
			{
				_Temp = rr(_Temp);
			}

		}

		return nullptr;
	}
/////////////////////////////////////////
	
	// LV ���̸� �����ɴϴ�
	int diff(Node* _Temp)
	{
		int left = height(_Temp->L);
		int right = height(_Temp->R);

		int factor = left - right;
		return factor;
	}

	int height(Node* _Temp)
	{
		int h = 0;
		if (nullptr != _Temp)
		{
			int left = height(_Temp->L);
			int right = height(_Temp->R);

			// ù maxHeight = 0
			int maxHeight = max(left, right);

			h = maxHeight + 1;
		}
		// ���� ��忡 �ٴ޾����� return�ϸ鼭 h�� 1�� ������
		return h;
	}

	// ��ü��ȸ �Լ�
	void circulateMap()
	{
		preorder(m_pRoot);
	}

	// ������ȸ
	void preorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		cout << node->value << "  ";

		preorder(node->L);
		preorder(node->R);
	}

	// ��带 Ż���Ҷ� ��ȸ
	// ���� ��ȸ
	void inorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inorder(node->L);
		cout << node->value << "  ";
		inorder(node->R);
	}

	// ���� ��ȸ
	void postorder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		postorder(node->L);
		postorder(node->R);
		cout << node->value << "  ";
	}

	// Ž��
	Tv find(Node* node, Tk first)
	{
		// ���� ����� ��ġ�� �������
		if (nullptr == first)
		{
			return node->value;
		}
		else if (first < node->key)
		{
			return find(node->L, first);
		}
		else
		{
			return find(node->R, first);
		}
	}
	void deleteNode(Node* node, Tk first)
	{
		// ���� ����� ��ġ�� �������
		if (node->R->key == first)
		{
			delete node->R;
			node->R = nullptr;
		}
		else if (first < node->key)
		{
		}
		else
		{
		}
	}


private:
	Node*		m_pRoot;

};