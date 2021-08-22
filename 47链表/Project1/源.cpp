#include<iostream>   // p������ָ��  s��������
using namespace std;

//����������
typedef struct lnode
{
	int data;
	lnode  *next;
} lnode;

class linklist
{
public:
	lnode *head;
	linklist();
	void creatlist(int n); //β�巨��������
	void  deleteAll(int x); //ɾ������ֵ��ͬ��Ԫ��
	void  print();
	void  turn();			//��������
	void split(lnode *&hb);	//������ż��
	lnode* midnode();		//�м�ڵ�
	void insertx(int x);	//��������
	void rangedelete(int min, int max);	//��Χɾ��
	void Union(lnode *&pb);		//����
	void combine(lnode *&pb);		//����
};

linklist::linklist()
{
	head = new lnode;
	head->next = NULL;
}

//β�巨��������
void linklist::creatlist(int n)
{
	lnode *r = head;             /// rʼ��ָ���ն˽ڵ�
	for (int i = 0; i < n; i++)
	{
		lnode  *p = new lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;         ///���һ���ڵ�ָ����Ϊ��
}

void linklist::print()
{
	lnode *p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

//ɾ������ֵ��ͬ��Ԫ��
void  linklist::deleteAll(int x)
{
	lnode *p = head;
	lnode *pr = head->next;
	while (p != NULL)
	{
		if (p->data == x)
		{       ///��ȣ�ɾ��x; pr��p��ǰ��ָ�롣
			pr->next = p->next;     ///ɾȥֵΪx�Ľڵ㡣�ı�ǰ��ָ����
			p = p->next;
		}
		else
		{
			pr = p;                ///����ȣ�pr��pһ���ƶ���
			p = p->next;
		}
	}
}

//��������
void linklist::turn()
{
	lnode *p = head->next;
	if (!p || !p->next)return;
	lnode*qr = p->next, *q;
	p->next = NULL;
	while (qr->next)
	{
		q = qr->next;
		qr->next = p;
		p = qr;
		qr = q;
	}
	qr->next = p;
	head->next = qr;
}

//������ż��
void linklist::split(lnode *&hb)
{
	hb = new lnode;
	hb->next = NULL;
	lnode *par = head, *pa = head->next, *pb, *pbr = hb;
	while (pa)
	{
		if (pa->data % 2 == 0)
		{
			par = pa;
			pa = pa->next;
		}
		else
		{
			pb = new lnode;
			pb->data = pa->data;
			//pb->next = hb->next;
			pbr->next = pb;
			pbr = pb;
			pb = pb->next;
			//`hb ->next = pb;
			par->next = pa->next;
			delete pa;
			pa = par->next;
		}
	}
	pbr->next = NULL;
}

//�м�ڵ�
lnode *linklist::midnode()
{
	lnode *a1 = head->next, *a2;
	if (a1 == NULL || a1->next == NULL)
		return a1;
	a2 = a1->next;
	while (a2 && a2->next)
	{
		a1 = a1->next;
		a2 = a2->next->next;
	}
	return a1;
}

//��������
void linklist::insertx(int x)
{
	lnode *pr = head, *p = head->next;
	while (p && p->data < x)
	{
		pr = p;
		p = p->next;
	}
	lnode *s = new lnode;
	s->data = x;
	s->next = p;
	pr->next = s;
}

//��Χɾ��
void linklist::rangedelete(int min, int max)
{
	lnode *pr = head, *p = head->next;
	while (p && p->data <= min)
	{
		pr = p;
		p = p->next;
	}
	while (p && p->data < max)
	{
		pr->next = p->next;
		delete p;
		p = pr->next;
	}
}

//����
void  linklist::Union(lnode *&pb)
{
	lnode *pa = head->next, *par = head, *q;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			par->next = pa;
			par = pa;
			pa = pa->next;
			q = pb;
			pb = pb->next;
			delete q;
		}
		else if (pa->data < pb->data)
		{
			q = pa;
			pa = pa->next;
			delete q;

		}
		else
		{
			q = pb;
			pb = pb->next;
			delete q;
		}
	}

	while (pa)  // �ͷ�a�в��ǽ���Ԫ��
	{
		q = pa;
		pa = pa->next;
		delete q;
	}

	while (pb)  //�ͷ�b�в��ǽ���Ԫ��
	{
		q = pb;
		pb = pb->next;
		delete q;
	}
	par->next = NULL;
	//delete pb;
}

//����
void  linklist::combine(lnode *&pb)
{
	lnode *pa = head->next;
	lnode *pc = head, *q;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			q = pb;
			pb = pb->next;
			delete q;

		}
		else if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;

		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

	}
	pc->next = pa ? pa : pb;

}


#if 0
int main()
{
	int n;
	linklist L1;
	cout << "������list1������:";
	cin >> n;
	cout << "��Ϊlist1�����������Ԫ��:";
	L1.creatlist(n);

	cout << "���Ľڵ�Ϊ:" << L1.midnode() << endl;
	cout << "����Ԫ��5���list1:";
	L1.insertx(5);
	L1.print();
	cout << "ɾ������ֵΪ5Ԫ�ص�list1:";
	L1.deleteAll(5);
	L1.print();
	cout << "ɾ��ֵ1-5֮���Ԫ�ص�list1:";
	L1.rangedelete(1, 5);
	L1.print();
	cout << "list1�����ĵ�list1:";
	L1.turn();
	L1.print();
	return 0;
}
#endif 

#if 0
int main()
{
	linklist L1, L2;
	int n;
	cout << "������list1������:";
	cin >> n;
	cout << "��Ϊlist1�����������Ԫ��:";
	L1.creatlist(n);
	L1.split(L2.head);
	cout << "list1ż������:" << endl;
	L1.print();
	cout << "list1��������:" << endl;
	L2.print();
	return 0;
}
#endif

//���Բ���
#if 0
int main()
{
	linklist L1, L2;
	cout << "������4���������Ԫ��:";
	L1.creatlist(4);
	cout << "������5���������Ԫ��:";
	L2.creatlist(5);
	L1.combine(L2.head->next);
	L1.print();
	return 0;
}
#endif

//���Խ���
#if 1
int main()
{
	linklist L1, L2;
	cout << "������4���������Ԫ��:";
	L1.creatlist(4);
	cout << "������5���������Ԫ��:";
	L2.creatlist(5);
	L1.Union(L2.head->next);
	L1.print();
	return 0;
}
#endif