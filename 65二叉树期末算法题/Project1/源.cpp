#include <iostream>
using namespace std;

typedef struct bitnode
{
	int data;
	bitnode* lchild, * rchild;
}bitnode;

class bitt
{
	bitnode* bt;
	void create(bitnode*& t);//创建一颗二叉树
	void preorder(bitnode* t);//先序历遍
	int change(bitnode*& t);//计算二叉树中度为1的结点个数;当二叉树度为2时，该结点的左右子树交换

public:
	void createbittree();
	void preordertree();
	int changetree();
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

void bitt::preorder(bitnode* t)
{
	if (t)
	{
		cout << t->data << " ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void bitt::preordertree()
{
	bitnode* t = bt;
	preorder(t);
}

int bitt::change(bitnode*& t)
{
	bitnode* temp = new bitnode;
	if (t == NULL)
	{
		return 0;
	}
	if ((t->lchild == NULL && t->rchild != NULL) || (t->rchild == NULL && t->lchild != NULL))
	{
		return 1 + change(t->lchild) + change(t->rchild);
	}
	if (t->lchild != NULL && t->rchild != NULL)
	{
		temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
		return change(t->lchild) + change(t->rchild);
	}
	return change(t->lchild) + change(t->rchild);
}

int bitt::changetree()
{
	bitnode* t = bt;
	return change(t);
}

int main()
{
	bitt tt;
	cout << "请输入需要形成的二叉树:" << endl;
	tt.createbittree();

	cout << "该二叉树先序历遍结果为:" << endl;
	tt.preordertree();
	cout << endl;

	cout << "该二叉树中度为1的结点个数为:" << endl;
	cout << tt.changetree() << endl;

	cout << "该二叉树中结点度为2时，该结点的左右子树交换，交换结果为:" << endl;
	tt.preordertree();
	cout<< endl;
}