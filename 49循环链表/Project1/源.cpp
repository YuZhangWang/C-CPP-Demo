#include <iostream>
using namespace std;

typedef struct lnode
{
	int data;
	lnode  *next;
} lnode;

class linklist
{
public:
	linklist();
	lnode *rear;
	void  print();
	void creatlist(int n);  //������ѭ������
	void insertx(int x);
	void deletex(int x);
};

linklist::linklist()  //����һ���յĵ�ѭ������
{
	rear = new lnode;
	rear->next = rear;
}

void linklist::creatlist(int n)
{
	lnode *r = rear->next;
	for (int i = 0; i < n; i++)
	{
		lnode  *p = new lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = rear;
}

void linklist::print()
{
	lnode *p = rear->next;
	while (true)
	{
		cout << p->data << ' ';
		p = p->next;

		if (p->next == rear)
		{
			cout << p->data << ' ';
			break;
		}
	}
	cout << endl;
}


/* void insertx(lnode *&raer->next, int x) { //���������һ��ֵ����X�Ľ��
	lnode *pr = raer->next, *p = raer->next->next;
	while (p != raer->next && p->data < x)
	{
		pr = p; p = p->next;
	}
	lnode*s = new lnode;
	s->data = x;
	s->next = p;
	pr->next = s;
} */

void linklist::insertx(int x) //��ѭ���������һ��ֵ����X�Ľ��
{
	lnode *pr = rear->next, *p = rear->next->next;
	while (true)
	{
		if (p && p->data < x)
		{
			pr = p;
			p = p->next;
		}
		else if (p && p->data == x)
		{
			break;
		}
	}
	lnode *s = new lnode;
	s->data = x;
	s->next = p;
	pr->next = s;
}

void linklist::deletex(int x)  //ɾ�������е�һ����Ҫɾ���Ľ��
{
	lnode *p = rear->next->next, *pr = rear->next;
	while (p && p->data != x)
	{
		pr = p;
		p = p->next;
	}
	pr->next = p->next;
	delete p;
}

int main()
{
	linklist L1;
	int n;
	int m;
	int k;
	while (true)
	{
		cout << "�����벻Ϊ���list1������:";
		cin >> n;
		if (n != 0)
		{
			break;
		}
	}

	cout << "��Ϊlist1����n���������Ԫ��:";
	L1.creatlist(n);
	L1.print();
	cout << "������Ҫ�����Ԫ��:";
	cin >> m;
	L1.insertx(m);
	L1.print();
	cout << "������Ҫɾ����Ԫ��:";
	cin >> k;
	L1.deletex(k);
	L1.print();
	return 0;
}