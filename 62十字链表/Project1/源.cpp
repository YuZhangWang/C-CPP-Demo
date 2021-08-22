#include<iostream>
using namespace std;
#define max 100

typedef struct arcnode 
{
	int tailvex, headvex;
	int info;
	arcnode *tlink, *hlink;
}arcnode;

typedef struct box
{
	char data;
	arcnode *firstin, *firstout;
}box;

class olgraph 
{
	box xlist[max];
	int n, e;
public:
	int locatex(char x);
	void create(int m, int k);
	int indegree(char x);
	int outdegree(char x);
	void addarc(char u, char v, int w);
};

int olgraph::locatex(char x) 
{
	for (int i = 0; i < n; i++)
	{
		if (x == xlist[i].data)
		{
			return i;
		}
	}
	return -1;
}

void olgraph::create(int m, int k) 
{
	for (int i = 0; i < m; i++)
	{
		cin >> xlist[i].data;
		xlist[i].firstin = xlist[i].firstout = NULL;
	}
	n = m; e = k;
	char u, v;
	int t, h, w;
	arcnode *p;

	for (int i = 0; i < k; i++) 
	{
		cin >> u >> v >> w;
		t = locatex(u);
		h = locatex(v);
		p = new arcnode;
		p->tailvex = t;
		p->headvex = h;
		p->info = w;
		p->tlink = xlist[t].firstout;
		xlist[t].firstout = p;
		p->hlink = xlist[h].firstin;
		xlist[h].firstin = p;
	}
}

int olgraph::outdegree(char x) 
{
	int t = locatex(x);
	int count = 0;
	arcnode *p = xlist[t].firstout;
	while (p) 
	{
		count++;
		p = p->tlink;
	}
	return count;
}

int olgraph::indegree(char x) 
{
	int h = locatex(x);
	int count = 0;
	arcnode *p = xlist[h].firstin;
	while (p)
	{
		count++;
		p = p->hlink;
	}
	return count;
}

void olgraph::addarc(char u, char v, int w) 
{
	int t = locatex(u), h = locatex(v);
	arcnode *p;
	if (t == -1) 
	{
		xlist[n].data = u;
		xlist[n].firstin = xlist[n].firstout = NULL;
		t = n;
		n++;
	}

	if (h == -1) 
	{
		xlist[n].data = v;
		xlist[n].firstin = xlist[n].firstout = NULL;
		h = n;
		n++;
	}
	p = new arcnode;
	p->tailvex = t;
	p->headvex = h;
	p->info = w;
	p->tlink = xlist[t].firstout;
	xlist[t].firstout = p;
	p->hlink = xlist[h].firstin;
	xlist[h].firstin = p;
	e++;
}

int main()
{
	olgraph g;
	g.create(5, 10);
	cout << g.indegree('e') << endl;
	cout << g.outdegree('e') << endl;
	return 0;
}
