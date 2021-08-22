#include<iostream>
using namespace std;
#define max 100

typedef struct node 
{
	int child;
	node *nextchild;
}node;

typedef struct
{
	char data;
	node *firstchild;
}box;

class ctt 
{
	box adj[max];
	int n;
public:
	void create(int m);
	int locatex(char x);
	int degree(char x);
	void addxy(char u, char v);
};

void ctt::create(int m)
{
	for (int i = 0; i < m; i++)
	{
		cin >> adj[i].data;
		adj[i].firstchild = NULL;
	}

	char u, v;
	int h, t; node *s;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		h = locatex(u);
		while (v != '.')
		{
			t = locatex(v);
			s = new node;
			s->child = t;
			s->nextchild = adj[h].firstchild;
			adj[h].firstchild = s;
			cin >> v;
		}
	}
	n = m;
}

int ctt::locatex(char x)
{
	for (int i = 0; i < n; i++)
	{
		if (x == adj[i].data)
			return i;
	}
	return -1;
}

int ctt::degree(char x) 
{
	int h = locatex(x);
	node *p = adj[h].firstchild;
	int count = 0;

	while (p) 
	{
		count++;
		p = p->nextchild;
	}
	return count;
}

void ctt::addxy(char u, char v) 
{
	int h = locatex(u), t;
	adj[n].data = v;
	adj[n].firstchild = NULL;
	t = n;
	n++;
	node *s = new node;
	s->child = t;
	s->nextchild = adj[h].firstchild;
	adj[h].firstchild = s;
}

int main() 
{
	ctt ct;
	ct.create(10);
	cout << ct.degree('d') << endl;
	ct.addxy('c', 'l');
	return 0;
}