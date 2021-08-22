#include <iostream>
using namespace std;
#define initlistsize 100
#define increment 10

class sqlist
{
	int *elem;
	int listsize;
	int length;
public:
	sqlist();
	void initlistn(int n);
	void print();
	void insertlist(int pos, int e);
	void deletelist(int pos, int &e);
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
	for (int i = 0; i < n; i++)
		cin >> elem[i];
	length = n;
}

void sqlist::print() {
	for (int i = 0; i < length; i++)
		cout << elem[i] << ' ';
	cout << endl;
}

void sqlist::insertlist(int pos, int e)
{
	if (pos<1 || pos>length + 1)return;
	if (length >= listsize) {
		int *elem1 = new int[listsize + increment];
		for (int i = 0; i < length; i++)
			elem1[i] = elem[i];
		delete[]elem;
		elem = elem1;
		listsize += increment;
	}
	int *p = &elem[pos - 1], *q = &elem[length - 1];
	for (; p <= q; q--)
		*(q + 1) = *q;
	*p = e;
	length++;
}

void sqlist::deletelist(int pos, int &e)
{
	if (pos<1 || pos>length)return;
	int *p = &elem[pos - 1], *q = &elem[length - 1];
	e = *p;
	for (; p < q; p++)
		*p = *(p + 1);
	length--;
}


int sqlist::search(int x)
{
	for (int i = 0; i < length; i++)
		if (x == elem[i])return i;
	return -1;
}

void sqlist::turnlist()
{
	int *temp = new int;
	int *p = elem, *q = &elem[length - 1];
	for (; p < q; p++, q--) {
		*temp = *p;
		*p = *q;

		*q = *temp;
	}
}

int main()
{
	sqlist la;
	la.initlistn(10);
	la.print();
	la.insertlist(8, 100);
	la.print();
	int e;
	la.deletelist(6, e);
	la.print();
	la.turnlist();
	la.print();
	return 0;
}
