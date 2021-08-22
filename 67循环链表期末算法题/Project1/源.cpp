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
	linklist();  //����һ���յĵ�ѭ������
	void creatlist(int n);  //������ѭ������
	void print();//��ӡѭ������
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
	cout << "������һ��5��Ԫ�صĵ���ѭ������:" << endl;
	l.creatlist(5);
	l.test(10);
	l.print();
	return 0;
}