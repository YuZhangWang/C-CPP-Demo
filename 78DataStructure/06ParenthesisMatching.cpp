/*********************************** 
 * @author: YuZhangWang
 * @date: 2021/9/12 22:26
 * @link: https://www.yuzhang.wang/
***********************************/
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct lnode {
    char data;
    lnode *next;
} lnode;

class stack {
    lnode *top;
public:
    stack();

    ~stack();

    void push(char e);

    void pop();

    int emptystack();

    void pair(char *st);
};

stack::stack() {
    top = NULL;
}

stack::~stack() {
    lnode *p = new lnode;
    while (top) {
        p = top->next;
        delete top;
        top = p;
    }
}

void stack::push(char e) {
    lnode *s = new lnode;
    if (!s) {
        cout << "内存分配失败";
        return;
    }
    s->data = e;
    s->next = top;
    top = s;
}

void stack::pop() {
    if (top == NULL) {
        cout << "溢出";
        return;
    }

    lnode *p = new lnode;
    char x = '0';
    x = top->data;
    p = top;
    top = top->next;
    delete p;
}

int stack::emptystack() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

void stack::pair(char *st) {
    while (*st) {
        if (*st == '(' || *st == '[' || *st == '{') {
            push(*st);
            st++;
        } else if (*st == ')' || *st == ']' || *st == '}') {
            if (emptystack()) {
                if (*st == ')')
                    cout << "缺少圆括号" << endl;
                else if (*st == ']')
                    cout << "缺少方括号" << endl;
                else if (*st == '}')
                    cout << "缺少大括号" << endl;
                return;
            } else if (*st == ')') {
                if (top->data == '(') {
                    pop();
                    st++;
                } else {
                    cout << "缺少圆括号" << endl;
                    return;
                }
            } else if (*st == ']') {
                if (top->data == '[') {
                    pop();
                    st++;
                } else {
                    cout << "缺少方括号" << endl;
                    return;
                }
            } else if (*st == '}') {
                if (top->data == '{') {
                    pop();
                    st++;
                } else {
                    cout << "缺少大括号" << endl;
                    return;
                }
            }
        } else {
            cout << "字符串中带有非法规定输入" << endl;
            return;
        }
    }

    if (emptystack()) {
        cout << "括号匹配" << endl;
    } else {
        cout << "括号不匹配" << endl;
        return;
    }
}

int main() {
    char *st = new char[256];

    while (1) {
        char m;
        while (1) {
            cout << "请输入一串只有英文括号的字符串:" << endl;
            cin >> st;
            if (st[0] == '(' || st[0] == '[' || st[0] == '{') {
                break;
            } else if (st[0] == ')' || st[0] == ']' || st[0] == '}') {
                if (st[0] == ')')
                    cout << "缺少圆括号" << endl;
                else if (st[0] == ']')
                    cout << "缺少方括号" << endl;
                else
                    cout << "缺少大括号" << endl;

            } else {
                continue;
            }
        }
        stack s;
        s.pair(st);
        s.~stack();
        cout << "是否继续进行匹配？请输入Y或N:" << endl;
        cin >> m;
        if (m == 'N' || m == 'n') {
            break;
        }
    }
    return 0;
}