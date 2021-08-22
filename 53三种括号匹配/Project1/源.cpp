#include<iostream>
#include<stdlib.h>
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
	~stack();
	void push(char e);
	void pop();
	int emptystack();
	void pair(char *st);
};

stack::stack()
{
	top = NULL;
}

stack::~stack()
{
	lnode *p = new lnode;
	while (top)
	{
		p = top->next;
		delete top;
		top = p;
	}
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
		if (*st == '(' || *st == '[' || *st == '{')
		{
			push(*st);
			st++;
		}
		else if (*st == ')' || *st == ']' || *st == '}')
		{
			if (emptystack())
			{
				if (*st == ')')
					cout << "ȱ��Բ����" << endl;
				else if (*st == ']')
					cout << "ȱ�ٷ�����" << endl;
				else if (*st == '}')
					cout << "ȱ�ٴ�����" << endl;
				return;
			}
			else if (*st == ')')
			{
				if (top->data == '(')
				{
					pop();
					st++;
				}
				else
				{
					cout << "ȱ��Բ����" << endl;
					return;
				}
			}
			else if (*st == ']')
			{
				if (top->data == '[')
				{
					pop();
					st++;
				}
				else 
				{
					cout << "ȱ�ٷ�����" << endl;
					return;
				}
			}
			else if (*st == '}')
			{
				if (top->data == '{')
				{
					pop();
					st++;
				}
				else
				{
					cout << "ȱ�ٴ�����" << endl;
					return;
				}
			}
		}
		else
		{
			cout << "�ַ����д��зǷ��涨����" << endl;
			return;
		}
	}

	if (emptystack())
	{
		cout << "����ƥ��" << endl;
	}
	else
	{
		cout << "���Ų�ƥ��" << endl;
		return;
	}
}

int main()
{
	char *st = new char[256];

	while (1)
	{
		char m;
		while (1)
		{
			cout << "������һ��ֻ��Ӣ�����ŵ��ַ���:" << endl;
			cin >> st;
			if (st[0] == '(' || st[0] == '[' || st[0] == '{')
			{
				break;
			}
			else if (st[0] == ')' || st[0] == ']' || st[0] == '}')
			{
				if (st[0] == ')')
					cout << "ȱ��Բ����" << endl;
				else if (st[0] == ']')
					cout << "ȱ�ٷ�����" << endl;
				else
					cout << "ȱ�ٴ�����" << endl;

			}
			else
			{
				continue;
			}
		}
		stack s;
		s.pair(st);
		s.~stack();
		cout << "�Ƿ��������ƥ�䣿������Y��N:" << endl;
		cin >> m;
		if (m == 'N' || m == 'n')
		{
			break;
		}
	}
	return 0;
}