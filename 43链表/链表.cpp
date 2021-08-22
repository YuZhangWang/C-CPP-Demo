#include<iostream>                  /// p：工作指针  s：待插入
using namespace std;
typedef struct node {
	int data;
	node  *next;
} node;
class linklist {

public:
	node *head;
	linklist();
	void creatlist(int n); //尾插法建立链表
	void  deleteAll(int x); //删除所有值相同的元素
	void  print();
	void  turn();			//倒置链表
	void split(node *&hb);	//分离奇偶数
	node* midnode();		//中间节点
	void insertx(int x);	//有序表插入
	void rangedelete(int min, int max);	//范围删除
	void Union(node *&pb);		//交集
	void combine(node *&pb);		//并集

};
linklist::linklist() {
	head = new node;
	head->next = NULL;
}
void linklist::creatlist(int n) {
	node *r = head;             /// r始终指向终端节点
	for (int i = 0; i < n; i++) {
		node  *p = new node;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;         ///最后一个节点指针域为空
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
		if (p->data == x) {       ///相等，删除x; pr是p的前驱指针。
			pr->next = p->next;     ///删去值为x的节点。改变前后指针域。
			p = p->next;
		}
		else {
			pr = p;                ///不相等，pr和p一起移动，
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
	cout << "输入有序递增元素： ";
	L1.creatlist(n);
	cout<<"插入元素5后的list1: ";
	L1.insertx(5);
	L1.print();
	cout << "input list2 length:";
	cin >> k;
	cout << "输入有序递增元素list2： ";
	L2.creatlist(k);
	L2.print();
	cout << "L1和L2的并集： ";
	L1.combine(L2.head->next);
	L1.print();
	cout << "L2逆序后的链表：";
	L2.turn();
	L2.print();

	/*L1.Union(L2.head->next);
	cout << "L1和L2的交集：";
	L1.print();*/
	cout << "删除所有值为5元素：";
	L1.deleteAll(5);
	L1.print();
	cout<<"删除值1-5之间的元素：";
	L1.rangedelete(1,5);
	L1.print();
	return 0;

}