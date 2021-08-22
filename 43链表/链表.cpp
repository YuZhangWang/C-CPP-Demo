#include<iostream>                  /// p������ָ��  s��������
using namespace std;
typedef struct node {
	int data;
	node  *next;
} node;
class linklist {

public:
	node *head;
	linklist();
	void creatlist(int n); //β�巨��������
	void  deleteAll(int x); //ɾ������ֵ��ͬ��Ԫ��
	void  print();
	void  turn();			//��������
	void split(node *&hb);	//������ż��
	node* midnode();		//�м�ڵ�
	void insertx(int x);	//��������
	void rangedelete(int min, int max);	//��Χɾ��
	void Union(node *&pb);		//����
	void combine(node *&pb);		//����

};
linklist::linklist() {
	head = new node;
	head->next = NULL;
}
void linklist::creatlist(int n) {
	node *r = head;             /// rʼ��ָ���ն˽ڵ�
	for (int i = 0; i < n; i++) {
		node  *p = new node;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;         ///���һ���ڵ�ָ����Ϊ��
}
void linklist::print()
{
	node *p = head->next;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

void  linklist::deleteAll(int x) {
	node *p = head;
	node *pr = head->next;
	while (p != NULL) {
		if (p->data == x) {       ///��ȣ�ɾ��x; pr��p��ǰ��ָ�롣
			pr->next = p->next;     ///ɾȥֵΪx�Ľڵ㡣�ı�ǰ��ָ����
			p = p->next;
		}
		else {
			pr = p;                ///����ȣ�pr��pһ���ƶ���
			p = p->next;
		}
	}
}

void linklist::turn() {
	node *p = head->next;
	if (!p || !p->next)return;
	node*qr = p->next, *q;
	p->next = NULL;
	while (qr->next) {
		q = qr->next;
		qr->next = p;
		p = qr;
		qr = q;
	}
	qr->next = p;
	head->next = qr;
}

void linklist::split(node *&hb) {
	hb = new node;
	hb->next = NULL;
	node *par = head, *pa = head->next, *pb;
	while (pa)
		if (pa->data % 2 == 0) {
			par = pa;
			pa = pa->next;
		}
		else {
			pb = new node;
			pb->data = pa->data;
			pb->next = hb->next;
			hb->next = pb;
			par->next = pa->next;
			delete pa;
			pa = par->next;
		}
}

node* linklist::midnode() {
	node *a1 = head->next, *a2;
	if (a1 == NULL || a1->next == NULL)return a1;
	a2 = a1->next;
	while (a2 && a2->next) {
		a1 = a1->next;
		a2 = a2->next->next;
	}
	return a1;
}

void linklist::insertx(int x) {
	node *pr = head, *p = head->next;
	while (p && p->data < x) {
		pr = p;
		p = p->next;
	}
	node *s = new node;
	s->data = x;
	s->next = p;
	pr->next = s;
}

void linklist::rangedelete(int min, int max) {
	node *pr = head, *p = head->next;
	while (p && p->data <= min) {
		pr = p;
		p = p->next;
	}
	while (p && p->data < max) {
		pr->next = p->next;
		delete p;
		p = pr->next;
	}
}

void  linklist::Union(node *&pb)
{
	node *pa = head->next, *par = head, *q;
	while (pa&&pb)
	{
		if (pa->data == pb->data) {
			par->next = pa;
			par = pa;
			pa = pa->next;
			q = pb;
			pb = pb->next;
			delete q;
		}
		else if (pa->data < pb->data) {
			q = pa;
			pa = pa->next;
			delete q;

		}
		else {
			q = pb;
			pb = pb->next;
			delete q;
		}
	}
	while (pa)
	{
		q = pa;
		pa = pa->next;
		delete q;
	}
	while (pb)
	{
		q = pb;
		pb = pb->next;
		delete q;
	}
	par->next = NULL;
	//delete pb;


}

void  linklist::combine(node *&pb) {
	node *pa = head->next;
	node *pc = head,*q;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		/*	q=pb;
			pb=pb->next;
			delete q;*/
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

	}
	pc->next = pa ? pa : pb;

}



int main() {
	int n, k;
	linklist L1, L2;
	cout << "input list1 length:";
	cin >> n;
	cout << "�����������Ԫ�أ� ";
	L1.creatlist(n);
	cout<<"����Ԫ��5���list1: ";
	L1.insertx(5);
	L1.print();
	cout << "input list2 length:";
	cin >> k;
	cout << "�����������Ԫ��list2�� ";
	L2.creatlist(k);
	L2.print();
	cout << "L1��L2�Ĳ����� ";
	L1.combine(L2.head->next);
	L1.print();
	cout << "L2����������";
	L2.turn();
	L2.print();

	/*L1.Union(L2.head->next);
	cout << "L1��L2�Ľ�����";
	L1.print();*/
	cout << "ɾ������ֵΪ5Ԫ�أ�";
	L1.deleteAll(5);
	L1.print();
	cout<<"ɾ��ֵ1-5֮���Ԫ�أ�";
	L1.rangedelete(1,5);
	L1.print();
	return 0;

}