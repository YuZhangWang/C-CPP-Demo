#include<iostream>
using namespace std;

typedef struct lnode
{
	char data;
	lnode *next;
}lnode;

class stack
{
	lnode *top;
public:
	stack();
	void push(char e);
    void pop();
    int emptystack();
    void pair(char *st);
};

stack::stack()
{
	top = NULL;
}

void stack::push(char e)
{
	lnode *s = new lnode;
	if (!s)
	{
		cout << "�ڴ����ʧ��";
		return;
	}
	s->data = e;
	s->next = top;
	top = s;
}

void stack::pop()
{
	if (top == NULL)
	{
		cout << "���";
		return;
	}

	lnode *p = new lnode;
	char x = '0';
	x = top->data;
	p = top;
	top = top->next;
	delete p;
}

int stack::emptystack()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

void stack::pair(char *st)
{
	while (*st)
	{
		if (*st == '(')
		{
			push(*st);
			st++;
		}
		else if (*st == ')')
		{
			if(emptystack())
			{
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
			else
			{
				pop();
				st++;
			}
		}
		else
		{
			cout << "���Ų�ƥ��" << endl;
			exit(0);
		}
	}

	if (emptystack())
	{
		cout << "����ƥ��" << endl;
	}
	else
	{
		cout << "���Ų�ƥ��" << endl;
	}
}

int main()
{
	char *st = new char[256];
	while (1)
	{
		cout << "������һϵ��Ӣ������:" << endl;
		cin >> st;
		if (st[0] == '(')
		{
			break;
		}
		cout << "���Ų�ƥ�����������" << endl;
	}
	stack s;
	s.pair(st);
	return 0;
}