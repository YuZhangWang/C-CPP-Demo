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
	void creatlist(int n); //β�巨��������
	void  print();//��ӡ����
	void test(int x, int y);//ֵ����x�ĵ�һ���������y���ý�㲻���ڣ�������������y���
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
	cout << "������һ��5��Ԫ������:" << endl;
	l.creatlist(5);
	l.test(5,10);
	l.print();
	return 0;
}