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

//�����ձ�
linklist::linklist() 
{
    head = new lnode;
    head->next = NULL;
}

//��ӡ
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

//����n��Ԫ�ص�����
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

//����Ԫ��
void linklist::insertlist(int i, int e) 
{
    lnode *p = head;
    int j = 0;
    while(p && j < i- 1) 
	{
        p = p->next; //�ƶ�ָ��
        j++;
    }
    if(!p || j > i-1) 
		return;
    lnode *s = new lnode;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//ɾ��Ԫ�ز���
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

//����ֵ����x�Ľ�㣬�����ڷ���1�����򷵻�0
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

//���������н��ĸ���
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

//ɾ����һ��ֵ����x�Ľ��
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

//ɾ��ֵ����x�����н��
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

//����ĵ���
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

//����������֪����ha���һ����������ֵΪż���Ľ�����ha�У�ֵΪ�����Ľ�����hb��
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

//��֪��������n����㣬�������Ľ��ĵ�ַ������[n/2]�������׵�ַ��[x]����xС����С����
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

//��������в���ֵ����x�Ľ�㣬�������Ȼ����
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

//����ɾ����ɾ��ֵ����min��С��max�����н��
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











