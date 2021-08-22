#include <iostream>
using namespace std;

typedef struct bitnode
{
	int data;
	bitnode* lchild, * rchild;
}bitnode;

class bitt
{
public:
	bitnode* bt;
	void create(bitnode*& t);//创建一颗二叉树
	void createbittree();
};

void bitt::create(bitnode*& t)
{
	int ch;
	cin >> ch;
	if (ch == -1)
		t = NULL;
	else
	{
		t = new bitnode;
		t->data = ch;
		create(t->lchild);
		create(t->rchild);
	}
}

void bitt::createbittree()
{
	bitnode* t;
	create(t);
	bt = t;
}

int test(bitnode* t, bitnode* s)
{
 	if (!t->lchild && !t->rchild && !s->lchild && !s->rchild)
	{
		return 1;
	}
	else if (t->lchild && !t->rchild && s->lchild && !s->rchild)
	{
		test(t->lchild, s->lchild);
	}
	else if (!t->lchild && t->rchild && !s->lchild && s->rchild)
	{
		test(t->rchild, s->rchild);
	}
	else if (t->lchild && t->rchild && s->lchild && s->rchild)
	{
		test(t->lchild, s->lchild);
		test(t->rchild, s->rchild);
	}
	else
	{
		return 0;
	}
}

int main()
{
	bitt t, s;
	cout << "请输入第一个二叉树:" << endl;
	t.createbittree();
	cout << "请输入第二个二叉树:" << endl;
	s.createbittree();
	test(t.bt,s.bt);
}