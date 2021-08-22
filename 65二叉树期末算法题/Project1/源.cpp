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
	void create(bitnode*& t);//����һ�Ŷ�����
	void preorder(bitnode* t);//��������
	int change(bitnode*& t);//����������ж�Ϊ1�Ľ�����;����������Ϊ2ʱ���ý���������������

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
	cout << "��������Ҫ�γɵĶ�����:" << endl;
	tt.createbittree();

	cout << "�ö���������������Ϊ:" << endl;
	tt.preordertree();
	cout << endl;

	cout << "�ö������ж�Ϊ1�Ľ�����Ϊ:" << endl;
	cout << tt.changetree() << endl;

	cout << "�ö������н���Ϊ2ʱ���ý������������������������Ϊ:" << endl;
	tt.preordertree();
	cout<< endl;
}