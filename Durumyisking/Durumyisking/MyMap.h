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
			: Key(NULL) // data타입 몰라서 intellisense 작동 안댐ㅋ
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
	//////////////데이터 삽입///////////////////////
	void insert(pair<Tk, Tv> _pair)
	{
		// 루트부터 순환 시작할것
		// m_pRoot에 대입하는건 처음에만 작동함
		m_pRoot = insert(m_pRoot, _pair);
	}

	// 인자의 node에 새로운 node를 붙일것이다.
	Node* insert(Node* _pNode, pair<Tk, Tv> _pair)
	{
		// 현재 노드의 위치가 비어있음
		if (nullptr == _pNode)
		{
			// 새로운 노드 생성
			_pNode = new Node();
			_pNode->key = _pair.first;
			_pNode->value = _pair.second;
			_pNode->L = nullptr;
			_pNode->R = nullptr;
			++_pNode->lv;
		}
		// 재귀(DFS)로 작동한다.
		else
		{
			// 왼쪽 삽입
			if (_pair.first < _pNode->key)
			{
				_pNode->L = insert(_pNode->L, _pair);
			}
			// 오른쪽삽입 (같아도 오른쪽 보낼거)
			else
			{
				_pNode->R = insert(_pNode->R, _pair);
			}
			_pNode = balance(_pNode);
		}
		return _pNode;
	}
/////////////////////////////////////////////////

///////////////////트리 회전//////////////////////

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

	// 둘 다 RR 한 번 LL 한 번 수행
	Node* lr(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->L;
		// rr회전
		_parent->L = rr(pTemp);
		// ll회전
		return ll(_parent);
	}
	Node* rl(Node* _parent)
	{
		Node* pTemp = nullptr;
		pTemp = _parent->R;
		// rr회전
		_parent->R = ll(pTemp);
		// ll회전
		return rr(_parent);
	}
	// 높이의 차이를 계산해서 트리 노드들을 회전시킨다.
	Node* balance(Node* _Temp)
	{
		int factor = diff(_Temp);
		if (factor > 1)
		{
			// 왼쪽의 길이가 더 길다

			// LL 회전
			if (diff(_Temp->L) > 0)
			{
				_Temp = ll(_Temp);
			}
			// LR 회전
			else
			{
				_Temp = lr(_Temp);
			}
		}
		else if (factor < -1)
		{
			// 오른쪽의 길이가 더 길다

			// RL 회전
			if (diff(_Temp->R) > 0)
			{
				_Temp = rl(_Temp);
			}
			// RR 회전
			else
			{
				_Temp = rr(_Temp);
			}

		}

		return nullptr;
	}
/////////////////////////////////////////
	
	// LV 차이를 가져옵니다
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

			// 첫 maxHeight = 0
			int maxHeight = max(left, right);

			h = maxHeight + 1;
		}
		// 말단 노드에 다달았을때 return하면서 h에 1씩 더해줌
		return h;
	}

	// 전체순회 함수
	void circulateMap()
	{
		preorder(m_pRoot);
	}

	// 전위순회
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

	// 노드를 탈출할때 순회
	// 중위 순회
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

	// 후위 순회
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

	// 탐색
	Tv find(Node* node, Tk first)
	{
		// 현재 노드의 위치가 비어있음
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
		// 현재 노드의 위치가 비어있음
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