#include <iostream>
using namespace std;
#define initlistsize 100
#define increment 10

class sqlist
{
public:
	int *elem;
	int listsize;
	int length;
public:
	sqlist();
	void initlistn(int n);
	void print();
	void inserlist(int pos,int e);
	void deletelist(int pos,int &e);
	int search(int x);
	void turnlist();
};

sqlist::sqlist()
{
	elem = new int[initlistsize];
	listsize = initlistsize;
	length = 0;
}

void sqlist::initlistn(int n)
{
	for(int i = 0;i < n;i++)
		cin >> elem[i];
	length = n;
}

void sqlist::print()
{
	for(int i = 0;i < length;i++)
		cout << elem[i] << ' ';
	cout << endl;
}

void sqlist::inserlist(int pos,int e)
{
	if(pos < 1 || pos > length + 1)
		return;
	if(length >= listsize)
	{
		int *elem1 = new int[listsize + increment];
		for(int i = 0;i < length;i++)
		elem1[i] = elem[i];
		delete[]elem;
		elem = elem1;
		listsize += increment;
	}

	int *p = &elem[pos - 1],*q = &elem[length - 1];
	for(;p<=q;q--)
		*(q+1) = *q;
	*p = e;
	length++;
}

void sqlist::deletelist(int pos,int &e)
{
	if(pos < 1 || pos > length)
		return;
	int *p = &elem[pos -1],*q = &elem[length - 1];
	e = *p;
	for( ;p < q;p++)
		*p = *(p+1);
	length--;
}	

int sqlist::search(int x)
{
	for(int i = 0;i < length;i ++)
		if(x == elem[i])
			return i;
		return -1;
}	

void sqlist::turnlist()
{
	int *temp = new int;
	int *p = elem,*q = &elem[length - 1];
	for(;p < q;p++,q--)
	{
		*temp = *p;
		*p = *q;
		*q = *temp;
	}
}

void mergelilst(sqlist la,sqlist lb,sqlist &lc)
{
	int *pa=la.elem,*pa_last=&la.elem[la.length-1];
	int *pb=lb.elem,*pb_last=&lb.elem[lb.length-1];

	lc.elem=new int[la.length+lb.length];
	int *pc=lc.elem;
	while(pa<=pa_last && pb<=pb_last)
		if(*pa<=*pb) *pc=*pa++;
		else *pc++=*pb++;

	while(pb<=pb_last) *pc++=*pb++;
	while(pa<=pa_last) *pc++=*pa++;
	lc.length=la.length+lb.length; 
}


int main()
{
	sqlist la;
	la.initlistn(10);
	la.print();
	la.inserlist(8,100);
	la.print();
	int e;
	la.deletelist(6,e);
	la.print();
	la.turnlist();
	la.print();
	return 0;
}
