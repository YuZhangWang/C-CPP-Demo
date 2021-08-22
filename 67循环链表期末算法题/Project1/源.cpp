#include <iostream>
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
	linklist();  //创建一个空的单循环链表
	void creatlist(int n);  //建立单循环链表
	void print();//打印循环链表
	void test(int x);
};

linklist::linklist()
{
	head = new lnode;
	head->next = head;
}

void linklist::creatlist(int n)
{
	lnode* r = head->next;
	for (int i = 0; i < n; i++)
	{
		lnode* p = new lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = head;
}

void linklist::print()
{
	lnode* p = head->next;
	while (true)
	{
		cout << p->data << ' ';
		p = p->next;

		if (p->next == head)
		{
			cout << p->data << ' ';
			break;
		}
	}
	cout << endl;
}

void linklist::test(int x)
{
	lnode* pr, * p;
	lnode* s = new lnode;
	pr = head;
	p = head->next;
	s->data = x;
	while (p != head)
	{
		if (p->data >= x)
		{
			pr->next = s;
			s->next = p;
			return;
		}
		pr = p;
		p = p->next;
	}
	pr->next = s;
	s->next = p;
}

int main()
{
	linklist l;
	cout << "请输入一组5个元素的递增循环链表:" << endl;
	l.creatlist(5);
	l.test(10);
	l.print();
	return 0;
}