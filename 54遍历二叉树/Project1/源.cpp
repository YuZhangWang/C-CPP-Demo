#include<iostream>
using namespace std;

typedef struct bitnode 
{
	char data;
	bitnode *lchild, *rchild;
}bitnode;

class bitt 
{
	bitnode *bt;
	void create(bitnode *&t);//创建二叉树
	void preorder(bitnode *t);//先序历遍
	int high(bitnode *t);//计算树高
	int countleaf(bitnode *t);//计算树叶数
	int countnode(bitnode *t); //计算结点数
	int countpartnode(bitnode *t);//计算分支点个数
	void copy(bitnode *&t, bitnode *&s);//二叉树拷贝
	void changebit(bitnode *&t);//二叉树左右子树交换
public:
	void createtree();//创建二叉树
	void preordertree();//先序历遍
	int hightree();//计算树高
	int countleaftree();//计算树叶数
	int countnodetree();//计算结点数
	int countpartnodetree();//计算分支点个数
	void copytree();//二叉树拷贝
	void changebittree();//二叉树左右子树交换
};

void bitt::create(bitnode *&t) 
{
	char ch;
	cin >> ch;
	if(ch == '.')
		t = NULL;
	else 
	{
		t = new bitnode;
		t->data = ch;
		create(t->lchild);
		create(t->rchild);
	}
}

void bitt :: createtree() 
{
	bitnode *t;
	create(t);
	bt = t;
}

void bitt::preorder(bitnode *t) 
{
	if (t) 
	{
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void bitt::preordertree() 
{
	bitnode *t = bt;
	preorder(t);
}

int bitt::high(bitnode *t) 
{
	if (t == NULL)
		return 0;
	else 
	{
		int m = 1 + high(t->lchild);
		int n = 1 + high(t->rchild);
		if (m >= n)
			return m;
		else 
			return n;
	}
}

int bitt::hightree() 
{
	bitnode *t = bt;
	return high(t);
}

int bitt::countleaf(bitnode *t) 
{
	if (t == NULL)
		return 0;
	else 
	{
		int m = countleaf(t->lchild);
		int n = countleaf(t->rchild);
		if (m + n == 0)
			return 1;
		else 
			return m + n;
	}
}

int bitt::countleaftree() 
{
	bitnode *t = bt;
	return countleaf(t);
}

int bitt::countnode(bitnode *t) 
{
	if (t) 
	{
		int m = countnode(t->lchild);
		int n = countnode(t->rchild);
		return 1 + m + n;
	}
	else 
        return 0;
}

int bitt::countnodetree() 
{
	bitnode *t = bt;
	return countnode(t);
}

int bitt::countpartnode(bitnode *t)
{
	if (t && (t->lchild || t->rchild ))
	{
		int m = countpartnode(t->lchild);
		int n = countpartnode(t->rchild);
		return 1 + m + n;
	}
	else
		return 0;
}

int bitt::countpartnodetree()
{
	bitnode *t = bt;
	return countpartnode(t);
}

void bitt::copy(bitnode *&t, bitnode *&s)
{
	if (t == NULL)
		s = NULL;
	else
	{
		s = t;
		copy(t->lchild, s->lchild);
		copy(t->rchild, s->rchild);
	}
}

void bitt::copytree()
{
	bitnode *t = bt;
	bitnode *s;
	copy(t, s);
	if (s)
	{
		cout << s->data;
		preorder(s->lchild);
		preorder(s->rchild);
	}
}

void bitt::changebit(bitnode *&t) 
{
	bitnode *temp = new bitnode;
	if(t) 
	{
		temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
		changebit(t->lchild);
		changebit(t->rchild);
	}
}

void bitt::changebittree() 
{
	bitnode *t = bt;
	changebit(t);
	bt = t;
}

int main() 
{
	bitt tt;
	cout << "请输入需要形成的二叉树:" << endl;
	tt.createtree();
	cout << "该二叉树先序历遍结果为:" << endl;
	tt.preordertree();
	cout << endl;
	cout << "该二叉树树高为:" << endl;
	cout << tt.hightree() << endl;
	cout << "该二叉树树叶数为:" << endl;
	cout << tt.countleaftree() << endl;
	cout << "该二叉树结点数为:" << endl;
	cout << tt.countnodetree() << endl;
	cout << "该二叉树分支点数为:" << endl;
	cout << tt.countpartnodetree() << endl;
	cout << "该二叉树拷贝结果为:" << endl;
	tt.copytree();
	cout << endl;
	cout << "该二叉树左右子树交换结果为:" << endl;
	tt.changebittree();
    tt.preordertree();
	cout << endl;
	return 0;
}