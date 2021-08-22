#include<iostream>
using namespace std;

typedef struct bstnode 
{
	int data;
	bstnode* lchild, * rchild;
}bstnode;

class bst 
{
	bstnode* bt;
	bstnode* search(bstnode *t, int key);  //搜索
	void insert(bstnode *&t, int key);   //插入
	void inorder(bstnode *t);  //中序遍历
public:
	bstnode* searchbst(int key);
	void insertbst(int key);
	void createbst(int a[], int n);  //创建新二叉排序树
	void inorderbst();
};

bstnode* bst::search(bstnode* t, int key) 
{
	if (t == NULL || t->data == key)
		return t;
	else if (t->data < key)
		return search(t->rchild, key);
	else
		return search(t->lchild, key);
}

bstnode* bst::searchbst(int key) 
{
	bstnode* t = bt;
	return search(t, key);
}

void bst::insert(bstnode *&t, int key) 
{
	if (t == NULL) 
	{
		t = new bstnode;
		t->data = key;
		t->lchild = t->rchild = NULL;
	}
	else if (t->data < key)
		insert(t->rchild, key);
	else 
		insert(t->lchild, key);
}

void bst::insertbst(int key) 
{

	bstnode* t = bt;
	insert(t, key);
}

void bst::createbst(int a[], int n) 
{
	bstnode* t = NULL;
	for (int i = 0; i < n; i++)
		insert(t, a[i]);
	bt = t;
}

void bst::inorder(bstnode* t) 
{
	if (t) 
	{
		inorder(t->lchild);
		cout << t->data << ' ';
		inorder(t->rchild);
	}
}

void bst::inorderbst() 
{
	bstnode  *t = bt;
	inorder(t);
}

int main() 
{
	bst st;
	int a[] = { 20,90,100,36,46,72,15,66,120 };
	st.createbst(a, sizeof(a) / sizeof(int));
	st.inorderbst();
	cout << endl;
	for (int i = 1; i <= 10; i++)
	{
		st.insertbst(i);
	}
	st.inorderbst();
	return 0;
}