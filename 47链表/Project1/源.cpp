#include<iostream>   // p：工作指针  s：待插入
using namespace std;

//定义链表结点
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
	void creatlist(int n); //尾插法建立链表
	void  deleteAll(int x); //删除所有值相同的元素
	void  print();
	void  turn();			//倒置链表
	void split(lnode *&hb);	//分离奇偶数
	lnode* midnode();		//中间节点
	void insertx(int x);	//有序表插入
	void rangedelete(int min, int max);	//范围删除
	void Union(lnode *&pb);		//交集
	void combine(lnode *&pb);		//并集
};

linklist::linklist()
{
	head = new lnode;
	head->next = NULL;
}

//尾插法建立链表
void linklist::creatlist(int n)
{
	lnode *r = head;             /// r始终指向终端节点
	for (int i = 0; i < n; i++)
	{
		lnode  *p = new lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;         ///最后一个节点指针域为空
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

//删除所有值相同的元素
void  linklist::deleteAll(int x)
{
	lnode *p = head;
	lnode *pr = head->next;
	while (p != NULL)
	{
		if (p->data == x)
		{       ///相等，删除x; pr是p的前驱指针。
			pr->next = p->next;     ///删去值为x的节点。改变前后指针域。
			p = p->next;
		}
		else
		{
			pr = p;                ///不相等，pr和p一起移动，
			p = p->next;
		}
	}
}

//倒置链表
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

//分离奇偶数
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

//中间节点
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

//有序表插入
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

//范围删除
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

//交集
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

	while (pa)  // 释放a中不是交集元素
	{
		q = pa;
		pa = pa->next;
		delete q;
	}

	while (pb)  //释放b中不是交集元素
	{
		q = pb;
		pb = pb->next;
		delete q;
	}
	par->next = NULL;
	//delete pb;
}

//并集
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
	cout << "请输入list1链表长度:";
	cin >> n;
	cout << "请为list1输入有序递增元素:";
	L1.creatlist(n);

	cout << "中心节点为:" << L1.midnode() << endl;
	cout << "插入元素5后的list1:";
	L1.insertx(5);
	L1.print();
	cout << "删除所有值为5元素的list1:";
	L1.deleteAll(5);
	L1.print();
	cout << "删除值1-5之间的元素的list1:";
	L1.rangedelete(1, 5);
	L1.print();
	cout << "list1逆序后的的list1:";
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
	cout << "请输入list1链表长度:";
	cin >> n;
	cout << "请为list1输入有序递增元素:";
	L1.creatlist(n);
	L1.split(L2.head);
	cout << "list1偶数链表:" << endl;
	L1.print();
	cout << "list1奇数链表:" << endl;
	L2.print();
	return 0;
}
#endif

//调试并集
#if 0
int main()
{
	linklist L1, L2;
	cout << "请输入4个有序递增元素:";
	L1.creatlist(4);
	cout << "请输入5个有序递增元素:";
	L2.creatlist(5);
	L1.combine(L2.head->next);
	L1.print();
	return 0;
}
#endif

//调试交集
#if 1
int main()
{
	linklist L1, L2;
	cout << "请输入4个有序递增元素:";
	L1.creatlist(4);
	cout << "请输入5个有序递增元素:";
	L2.creatlist(5);
	L1.Union(L2.head->next);
	L1.print();
	return 0;
}
#endif