#include<iostream>
using namespace std;

typedef struct lnode
{
	int data;
	lnode* next;
} lnode;

class linklist
{
	lnode* head;
public:
	linklist();
	void creatlist(int n); //尾插法建立链表
	void  print();//打印链表
	void test(int x, int y);//值等于x的第一个结点后插入y，该结点不存在，在链表最后插入y结点
};

linklist::linklist()
{
	head = new lnode;
	head->next = NULL;
}

void linklist::creatlist(int n)
{
	lnode* r = head;             
	for (int i = 0; i < n; i++)
	{
		lnode* p = new lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;         
}

void linklist::print()
{
	lnode* p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

void linklist::test(int x, int y)
{
	lnode* s = new lnode;
	lnode* pr, * p;
	pr = head;
	p = head->next;
	s->data = y;
	while (p)
	{
		if (p->data == x)
		{
			s -> next = p->next;
			p->next = s;
			return;
		}
		pr = p;
		p = p->next;
	}
	pr->next = s;
	s->next = NULL;
}

int main()
{
	linklist l;
	cout << "请输入一串5个元素链表:" << endl;
	l.creatlist(5);
	l.test(5,10);
	l.print();
	return 0;
}