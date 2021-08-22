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
	void create(bitnode *&t);//����������
	void preorder(bitnode *t);//��������
	int high(bitnode *t);//��������
	int countleaf(bitnode *t);//������Ҷ��
	int countnode(bitnode *t); //��������
	int countpartnode(bitnode *t);//�����֧�����
	void copy(bitnode *&t, bitnode *&s);//����������
	void changebit(bitnode *&t);//������������������
public:
	void createtree();//����������
	void preordertree();//��������
	int hightree();//��������
	int countleaftree();//������Ҷ��
	int countnodetree();//��������
	int countpartnodetree();//�����֧�����
	void copytree();//����������
	void changebittree();//������������������
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
	cout << "��������Ҫ�γɵĶ�����:" << endl;
	tt.createtree();
	cout << "�ö���������������Ϊ:" << endl;
	tt.preordertree();
	cout << endl;
	cout << "�ö���������Ϊ:" << endl;
	cout << tt.hightree() << endl;
	cout << "�ö�������Ҷ��Ϊ:" << endl;
	cout << tt.countleaftree() << endl;
	cout << "�ö����������Ϊ:" << endl;
	cout << tt.countnodetree() << endl;
	cout << "�ö�������֧����Ϊ:" << endl;
	cout << tt.countpartnodetree() << endl;
	cout << "�ö������������Ϊ:" << endl;
	tt.copytree();
	cout << endl;
	cout << "�ö��������������������Ϊ:" << endl;
	tt.changebittree();
    tt.preordertree();
	cout << endl;
	return 0;
}