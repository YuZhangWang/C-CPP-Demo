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
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü";
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
		cout << "Òç³ö";
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
					cout << "È±ÉÙÔ²À¨ºÅ" << endl;
				else if (*st == ']')
					cout << "È±ÉÙ·½À¨ºÅ" << endl;
				else if (*st == '}')
					cout << "È±ÉÙ´óÀ¨ºÅ" << endl;
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
					cout << "È±ÉÙÔ²À¨ºÅ" << endl;
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
					cout << "È±ÉÙ·½À¨ºÅ" << endl;
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
					cout << "È±ÉÙ´óÀ¨ºÅ" << endl;
					return;
				}
			}
		}
		else
		{
			cout << "×Ö·û´®ÖÐ´øÓÐ·Ç·¨¹æ¶¨ÊäÈë" << endl;
			return;
		}
	}

	if (emptystack())
	{
		cout << "À¨ºÅÆ¥Åä" << endl;
	}
	else
	{
		cout << "À¨ºÅ²»Æ¥Åä" << endl;
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
			cout << "ÇëÊäÈëÒ»´®Ö»ÓÐÓ¢ÎÄÀ¨ºÅµÄ×Ö·û´®:" << endl;
			cin >> st;
			if (st[0] == '(' || st[0] == '[' || st[0] == '{')
			{
				break;
			}
			else if (st[0] == ')' || st[0] == ']' || st[0] == '}')
			{
				if (st[0] == ')')
					cout << "È±ÉÙÔ²À¨ºÅ" << endl;
				else if (st[0] == ']')
					cout << "È±ÉÙ·½À¨ºÅ" << endl;
				else
					cout << "È±ÉÙ´óÀ¨ºÅ" << endl;

			}
			else
			{
				continue;
			}
		}
		stack s;
		s.pair(st);
		s.~stack();
		cout << "ÊÇ·ñ¼ÌÐø½øÐÐÆ¥Åä£¿ÇëÊäÈëY»òN:" << endl;
		cin >> m;
		if (m == 'N' || m == 'n')
		{
			break;
		}
	}
	return 0;
}