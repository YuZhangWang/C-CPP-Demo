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
	void create(); //创建图，m个结点，k条边
	int locatex(char x);//定位结点位置
	void degree();//计算结点的边数
	void addarc();//增加一条边
	void deletearc();//删除一条边
	void deletenode();//删除一个结点
};

void graph::create()
{
	int m=0,k=0;
	cout << "请输入生成图的结点数和边数:"<<endl;
	cin >> m >> k;

	cout << "请输入结点处的数据:"<<endl;
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

	cout << "请输入结点以及权值:" << endl;
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
		cout << "请输入需要计算边数的结点:" << endl;
		cin >> x;
		h = locatex(x);
		if (h == -1)
		{
			cout << "不存在该点" << endl;
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
	cout << "该点的边数为:" << endl<<count<<endl;
}

void graph::addarc()
{
	char u = '0', v = '0', w = '0';
	cout << "请输入添加边对应结点以及权值:" << endl;
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
		cout << "请输入删除边的两个结点:"<<endl;
		cin >> u >> v;
		h = locatex(u);
		t = locatex(v);
		if (h == -1 || t == -1)                              
			cout << "不存在这条边" << endl;
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
		cout << "请输入需要删除的结点:" << endl;
		cin >> u;
		h = locatex(u);
		if (h == -1)
			cout << "不存在这个点" << endl;
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