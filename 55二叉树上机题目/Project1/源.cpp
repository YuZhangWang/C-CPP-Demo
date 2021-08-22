#include <iostream>
using namespace std;

typedef struct bitnode
{
	int data;
	bitnode *lchild, *rchild;
}bitnode;

class bitt
{
	bitnode *bt;
	void create(bitnode *&t);//创建一颗二叉树
	void preorder(bitnode *t);//先序历遍
	int countone(bitnode *t);//计算二叉树中度为1的结点个数
	int hight(bitnode *t);//计算二叉树的树高
	int countx(bitnode *t, int x);//计算一颗二叉树中结点的值大于x的结点个数
	void addyz(bitnode *&t,int x,int y,int z);//当二叉树中结点的值大于x时，值加上y，否则加上z
	void changex(bitnode *&t, int x);//当二叉树结点的值大于x时，该结点的左右子树交换

public:
	void createbittree();
	void preordertree();
	int countonebittree();
	int hightbittreee();
	int countxbittree();
	void addyzbittree(int x, int y, int z);
	void changexbittree(int x);
};

void bitt::create(bitnode *&t)
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
	bitnode *t;
	create(t);
	bt = t;
}

void bitt::preorder(bitnode *t)
{
	if (t)
	{
		cout << t->data<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void bitt::preordertree()
{
	bitnode *t = bt;
	preorder(t);
}

int bitt::countone(bitnode *t)
{
	if (t == NULL)
	{
		return 0;
	}
	if (t->lchild == NULL && t->rchild != NULL || t->rchild == NULL && t->lchild != NULL)
	{
		return 1 + countone(t->lchild) + countone(t->rchild);
	}

	return countone(t->lchild) + countone(t->rchild);
}

int bitt::countonebittree()
{
	bitnode *t = bt;
	return countone(t);
}

int bitt::hight(bitnode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		int m = 1 + hight(t->lchild);
		int n = 1 + hight(t->rchild);
		if (m >= n)
			return m;
		else
			return n;
	}
}

int bitt::hightbittreee()
{
	bitnode *t = bt;
	return hight(t);
}

int bitt::countx(bitnode *t, int x)
{
	if (t == NULL)
	{
		return 0;
	}
	if (t->data > x)
	{
		return 1 + countx(t->lchild,x) + countx(t->rchild,x);
	}
	return countx(t->lchild,x) + countx(t->rchild,x);
}

int bitt::countxbittree()
{
	int x;
	cin >> x;
	bitnode *t = bt;
	cout << "该二叉树中结点的值大于X的结点个数为:" << endl;
	return countx(t,x);
}

void bitt::addyz(bitnode *&t, int x, int y, int z)
{
	if (t)
	{
		if (t->data > x)
			t->data += y;
		else
			t->data += z;
		addyz(t->lchild, x, y, z);
		addyz(t->rchild, x, y, z);
	}
}

void bitt::addyzbittree(int x,int y,int z)
{
	bitnode *t = bt;
	addyz(t, x, y, z);
}

void bitt::changex(bitnode *&t, int x)
{
	bitnode *temp = new bitnode;
	if (t)
	{
		if (t->data > x)
		{
			temp = t->lchild;
			t->lchild = t->rchild;
			t->rchild = temp;
		}
		changex(t->lchild, x);
		changex(t->rchild, x);
	}
}

void bitt::changexbittree(int x)
{
	bitnode *t=bt;
	changex(t,x);
	bt = t;
}

int main()
{
	bitt tt;
	int x, y, z,w;
	cout << "请输入需要形成的二叉树:" << endl;
	tt.createbittree();

	cout << "该二叉树先序历遍结果为:" << endl;
	tt.preordertree();
	cout << endl;

	cout << "该二叉树中度为1的结点个数为:" << endl;
	cout << tt.countonebittree() << endl;

	cout << "该二叉树树高为:" << endl;
	cout << tt.hightbittreee() << endl;

	cout << "请为计算该二叉树中结点的值大于x的结点个数输入一个比较值X:" << endl;
	cout << tt.countxbittree() << endl;

	cout << "请为实现该二叉树结点的值大于X时，该结点的左右子树交换输入一个比较值X:" << endl;
	cin >> w;
	cout << "该二叉树中结点的值若大于X左右子树交换，交换结果为:" << endl;
	tt.changexbittree(w);
	tt.preordertree();
	cout << endl;

	cout << "请为实现当二叉树中结点的值大于X时，值加上Y，否则加上Z输入比较值X，增量Y，增量Z，三者用空号隔开:" << endl;
	cin >> x >> y >> z;
	tt.addyzbittree(x,y,z);
	cout << "该二叉树比较后结果为:" << endl;
	tt.preordertree();
	cout << endl;
	return 0;
}