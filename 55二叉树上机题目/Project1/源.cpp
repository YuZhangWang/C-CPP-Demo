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
	void create(bitnode *&t);//����һ�Ŷ�����
	void preorder(bitnode *t);//��������
	int countone(bitnode *t);//����������ж�Ϊ1�Ľ�����
	int hight(bitnode *t);//���������������
	int countx(bitnode *t, int x);//����һ�Ŷ������н���ֵ����x�Ľ�����
	void addyz(bitnode *&t,int x,int y,int z);//���������н���ֵ����xʱ��ֵ����y���������z
	void changex(bitnode *&t, int x);//������������ֵ����xʱ���ý���������������

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
	cout << "�ö������н���ֵ����X�Ľ�����Ϊ:" << endl;
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
	cout << "��������Ҫ�γɵĶ�����:" << endl;
	tt.createbittree();

	cout << "�ö���������������Ϊ:" << endl;
	tt.preordertree();
	cout << endl;

	cout << "�ö������ж�Ϊ1�Ľ�����Ϊ:" << endl;
	cout << tt.countonebittree() << endl;

	cout << "�ö���������Ϊ:" << endl;
	cout << tt.hightbittreee() << endl;

	cout << "��Ϊ����ö������н���ֵ����x�Ľ���������һ���Ƚ�ֵX:" << endl;
	cout << tt.countxbittree() << endl;

	cout << "��Ϊʵ�ָö���������ֵ����Xʱ���ý�������������������һ���Ƚ�ֵX:" << endl;
	cin >> w;
	cout << "�ö������н���ֵ������X���������������������Ϊ:" << endl;
	tt.changexbittree(w);
	tt.preordertree();
	cout << endl;

	cout << "��Ϊʵ�ֵ��������н���ֵ����Xʱ��ֵ����Y���������Z����Ƚ�ֵX������Y������Z�������ÿպŸ���:" << endl;
	cin >> x >> y >> z;
	tt.addyzbittree(x,y,z);
	cout << "�ö������ȽϺ���Ϊ:" << endl;
	tt.preordertree();
	cout << endl;
	return 0;
}