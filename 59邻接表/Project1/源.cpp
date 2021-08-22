#include<iostream>
using namespace std;
#define max 100

typedef struct arcnode
{
	int adjvex;
	int info;
	arcnode *nextarc;
}arcnode;

typedef struct
{
	char data;
	arcnode *firstarc;
}box;

class graph
{
	box adj[max];
	int n,e;
public:
	void create(); //����ͼ��m����㣬k����
	int locatex(char x);//��λ���λ��
	void degree();//������ı���
	void addarc();//����һ����
	void deletearc();//ɾ��һ����
	void deletenode();//ɾ��һ�����
};

void graph::create()
{
	int m=0,k=0;
	cout << "����������ͼ�Ľ�����ͱ���:"<<endl;
	cin >> m >> k;

	cout << "�������㴦������:"<<endl;
	for (int i = 0; i < m; i++)
	{
		cin >> adj[i].data;
		adj[i].firstarc = NULL;
	}
	n = m;
	e = k;

	char u='0', v='0';
	int h=0, t=0, w=0;
	arcnode *p;

	cout << "���������Լ�Ȩֵ:" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> u >> v >> w;
		h = locatex(u);
		t = locatex(v);

		p = new arcnode;
		p->adjvex = t;
		p->info = w;

		p->nextarc = adj[h].firstarc;
		adj[h].firstarc = p;
	}
}

int graph::locatex(char x)
{
	for (int i = 0; i < n; i++)
	{

		if (x == adj[i].data)
			return i;
	}
	return -1;
}

void graph::degree()
{
	char x;
	int h = 0;
	while (1)
	{
		cout << "��������Ҫ��������Ľ��:" << endl;
		cin >> x;
		h = locatex(x);
		if (h == -1)
		{
			cout << "�����ڸõ�" << endl;
		}
		else
			break;
	}

	arcnode *p = adj[h].firstarc;
	int count = 0;
	while(p)
	{
		count++;
		p = p->nextarc;
	}
	cout << "�õ�ı���Ϊ:" << endl<<count<<endl;
}

void graph::addarc()
{
	char u = '0', v = '0', w = '0';
	cout << "��������ӱ߶�Ӧ����Լ�Ȩֵ:" << endl;
	cin >> u >> v >> w;
	int h = locatex(u), t = locatex(v);
	if (h == -1)
	{
		adj[n].data = u;
		adj[n].firstarc = NULL;
		h = n;
		n++;
	}
	if (t == -1)
	{
		adj[n].data = v;
		adj[n].firstarc = NULL;
		t = n;
		n++;
	}

	arcnode *p = new arcnode;
	p->adjvex = t;
	p->info = w;
	p->nextarc = adj[h].firstarc;
	adj[h].firstarc = p;
	e++;
}

void graph::deletearc()
{
	char u='0',v='0';
	int h = 0, t = 0;
	while (1)
	{
		cout << "������ɾ���ߵ��������:"<<endl;
		cin >> u >> v;
		h = locatex(u);
		t = locatex(v);
		if (h == -1 || t == -1)                              
			cout << "������������" << endl;
		else
			break;
	}

	arcnode *pr = new arcnode;
	arcnode *p = new arcnode;
	pr = adj[h].firstarc;
	p = pr->nextarc;
	while(p->adjvex!=t)
	{     
		pr = p;
		p = p->nextarc;
	}
	pr->nextarc = p->nextarc;
	delete p;
	e--;
}

void graph::deletenode()
{
	char u = '0';
	int h = 0;
	while (1)
	{
		cout << "��������Ҫɾ���Ľ��:" << endl;
		cin >> u;
		h = locatex(u);
		if (h == -1)
			cout << "�����������" << endl;
		else
			break;
	}

	for (int i = 0,j=h;i<n-h-1;j++,i++)
	{
		adj[j] = adj[j + 1];
	}
	n--;

	for (int i = 0; i < n; i++)
	{
		arcnode *pr = new arcnode;
        arcnode *p = new arcnode;
		if (adj[i].firstarc)
		{
			pr = adj[i].firstarc;
			p = pr->nextarc;
			while (p->adjvex != h)
			{
				pr = p;
				p = p->nextarc;
			}
			pr->nextarc = p->nextarc;
			delete p;
			e--;
		}
		else
			continue;
	}
}

int main()
{
	graph g;

	g.create();
	g.degree();

    g.addarc();
	g.degree();

	g.deletearc();
	g.degree();


	g.deletenode();
	g.degree();
	return 0;
}