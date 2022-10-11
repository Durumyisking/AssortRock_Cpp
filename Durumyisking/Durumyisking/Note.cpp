#include <iostream>
#include <list>
#include <queue>
using namespace std;

char path[10];
char arr[4]{ 'B', 'G', 'T', 'K' };
char arr2[4]{ 'A', 'T', 'K', 'P' };
char via[10];


char value[6] = "TBECD";
int map[5][5] = {
	0,1,1,0,0,
	0,0,0,1,1,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
};

char chmap[7] = " TBECD";


void BBQ(int _Lv, int _Dest)
{
	if (_Lv == _Dest)
		return;

	BBQ(_Lv + 1, _Dest);
	BBQ(_Lv + 1, _Dest);

	int a = 0;
}

void BBQ2(int _Lv)
{
	if (_Lv == 3)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 2; i++)
	{
		path[_Lv] = 'A' + i;
		BBQ2(_Lv + 1);
		path[_Lv] = '\0';
	}
}


void BBQ3(int _Lv)
{
	if (_Lv == 2)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		path[_Lv] = *(arr + i);
		BBQ3(_Lv + 1);
		path[_Lv] = '\0';
	}
}

void BBQ4(int _Lv)
{
	if (_Lv == 3)
	{
		cout << path << endl;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (0 == via[i])
		{
			via[i] = 1;
			path[_Lv] = 'A' + i;
			BBQ4(_Lv + 1);
			path[_Lv] = 0;
			via[i] = 0;
		}
	}
}


void BBQ5(int _Lv)
{
	if (3 == _Lv)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (0 == via[i])
		{
			path[_Lv] = *(arr2 + i);
			via[i] = 1;
			BBQ5(_Lv + 1);
			path[_Lv] = 0;
			via[i] = 0;
		}
	}
}

void run(int now)
{
	for (int i = 0; i < 5; ++i)
	{
		if (map[now][i] == 1)
			run(i);
	}
}

// tbecd
void runch(int now)
{
	if (now >= 7 || chmap[now] == ' ') return;

	cout << chmap[now];

	runch(now * 2); // Leftnode ¸ÕÀú
	runch(now * 2 + 1); // RightNode
}

struct Node
{
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

void Recur(int _lv, Node* pNode)
{

	if (pNode->left != nullptr)
	{
		Recur(_lv + 1, pNode->left);
	}
	if (pNode->right != nullptr)
	{
		Recur(_lv + 1, pNode->right);
	}
	
}
char volume[6] = "TEQWA";
int visited[5];
int graaph[5][5] = {

	0,1,0,0,0,
	0,0,1,1,0,
	0,0,0,0,0,
	1,0,0,0,1,
	0,0,0,0,0,
};
void graphgogo(int now)
{
	for (int i = 0; i < 5; i++)
	{
		if (graaph[now][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			graphgogo(i);
		}
	}
}


struct Node2
{
	int num;
	int level;
};

Node2 queue2[7] = { {0,0} };
int head = 0;
int tail = 1;
char value2[7] = "EAURQY";
int map2[6][6] = {
	0,1,1,0,0,0,
	0,0,0,1,1,0,
	0,0,0,0,0,1,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0, };


int main()
{
	int iInput;
//	cin >> iInput;
//	BBQ5(0);
	//visited[0] = 1;
	//graphgogo(0);


	//list <Node*> list;
	//Node* root = new Node();

	//root->left = new Node();
	//root->right = new Node();
	//
	//root->left->left = new Node();
	//root->left->left->right = new Node();

	queue<Node2> myqueue;
	myqueue.push(Node2{ 0, 0 });

	while (!myqueue.empty())
	{
		Node2 now = myqueue.front();
		cout << value2[now.num];

		for (int i = 0; i < 6; i++)
		{
			if (map2[now.num][i] == 1)
			{
				myqueue.push(Node2{ i, now.level });
			}
		}
		myqueue.pop();
	}

	return 0;
}