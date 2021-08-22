#include <iostream.h>

typedef struct lnode
{
	int data;
	lnode *next;
}lnode;

class linklist
{
	lnode *head;
public:
	linklist();
	void initlist(int n);
    void print();
	void insertlist(int i,int e);
	int deletelist(int i);
	int locatex(int x);
    int countnode();
	void deletex(int x);
	void deleteallx(lnode *&head, int x);
	void turn(lnode *&head);
	void *midnode(lnode *head);
	void split(lnode *&ha,lnode *&hb);
	void insertx(lnode *&head,int x);
	void rangedelete(lnode *&head,int min,int max);
	//void intersetion(lnode *&hb);
	//void union(lnode *&hb);
};

//创建空表
linklist::linklist() 
{
    head = new lnode;
    head->next = NULL;
}

//打印
void linklist::print() 
{
    lnode *p = head->next;
    while(p) 
	{
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

//创建n个元素的链表
void linklist::initlist(int n) 
{
    lnode *p;  //lnode *p,*s; //s=head;
    for(int i = 0; i < n; i++) 
	{
		p=new lnode;
        cin >> p->data;
        p->next = head->next; //p->next = NULL;
        head->next=p;  //s->next=p; s=p;
    }
}

//插入元素
void linklist::insertlist(int i, int e) 
{
    lnode *p = head;
    int j = 0;
    while(p && j < i- 1) 
	{
        p = p->next; //移动指针
        j++;
    }
    if(!p || j > i-1) 
		return;
    lnode *s = new lnode;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//删除元素操作
int linklist::deletelist(int i) 
{
    lnode *p = head;
    int j = 0;
    while(p->next && j < i - 1) 
	{
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1)return -1;
    lnode *s = p->next;
    p->next = s->next;
    int e = s->data;
    delete s;
    return e;
}

//查找值等于x的结点，若存在返回1，否则返回0
int linklist::locatex(int x) 
{
    lnode *p = head->next;
    while(p) 
	{
        if(p->data == x)
			return 1;
        p = p->next;
    }
    return 0;
}

//计算链表中结点的个数
int linklist::countnode() 
{
    lnode *p = head->next;
    int n = 0;
    while(p) 
	{
        n++;  //if(p->data%2==0)n++;
        p = p->next;
    }
    return n;
}

//删除第一个值等于x的结点
void linklist::deletex(int x)
{
    lnode *pr=head,*p=head->next;
    while(p&&p->data!=x)
	{
		pr=p;
		p=p->next;
	}
    pr->next=p->next;
    delete p;
}

//删除值等于x的所有结点
void linklist::deleteallx(lnode *&head,int x)
{
    lnode *pr=head,*p=head->next;
    while(p)
	{
		if(p->data != x)
		{
			pr=p;
			p=p->next;
		}
		else
		{
			pr->next = p->next;
			delete p;
			p=pr->next;
		}
	}
}

//链表的倒置
void linklist::turn(lnode *&head)
{
	lnode *p=head->next;
	if(!p || !p->next)
		return;
	lnode *qr = p->next,*q;
	p->next = NULL;
	while(qr->next)
	{
		q=qr->next;
		qr->next=p;
		p=qr;
		qr=q;
	}
	qr->next = p;
	head->next = qr;
}

//分裂链表，已知链表ha存放一组整数，把值为偶数的结点放在ha中，值为奇数的结点放在hb中
void linklist::split(lnode *&ha,lnode *&hb)
{
	hb=new lnode;
	hb->next=NULL;
	lnode *pr=ha,*p=ha->next,*s;
	while(p)
        if(p->data%2==0)
		{
			pr=p;
			p=p->next;
		}
        else
		{
			s=new lnode;
			s->data = p->data;
			s->next=hb->next;
			hb->next=s;
			pr->next=p->next;
			delete p;
			p=pr->next;             
		}
}

//已知链表中有n个结点，返回中心结点的地址，即第[n/2]个结点的首地址，[x]不比x小的最小整数
lnode linklist::*midnode(lnode *head)
{
	lnode *p=head->next;
	if(p == NULL || p->next == NULL)
		return p;
	
	lnode *q = p->next;
	while(q && q->next)
	   {
		p=p->next;
		q=q->next->next;
		
	}
	return p;
}  

//在有序表中插入值等于x的结点，插入后仍然有序
void linklist::insertx(lnode *&head,int x)
{
	lnode *pr=head,*p=head->next;
	while(p && p->data<x)
	{
		pr = p;
		p = p->next;
	}      
	
	lnode *s = new lnode;
	s->data = x;
	s->next = p;
	pr->next = s;
}

//区域删除，删除值大于min，小于max的所有结点
void linklist::rangedelete(lnode *&head,int min,int max)
{
	lnode *pr=head,*p=head->next;
	while(p && p->data <= min)
	{
		pr=p;
		p=p->next;
	}
	
	while(p&&p->data<max)
	{
		pr->next=p->next;
		delete p;
		p=pr->next;
	}
}

int main()
{
	linklist l;

    l.initlist(10);
	l.print();

	l.insertlist(10,9);
	l.print();

	l.deletelist(7);
	l.print();

	cout << l.locatex(1)<<endl;
    cout << l.countnode() <<endl;

	l.deletex(5);
	l.print();

	//l.deleteallx(9);
	//l.print();

	//l.turn();
	//l.print();

	//l.*midnode();

	//l.split();
	//l.print();

	//l.insertx(100);
	//l.print();

	//l.rangedelete(4,7);
	//l.intersetion(l);
	//l.union();

	return 0;
}











