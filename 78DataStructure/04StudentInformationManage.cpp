/***********************************
 * @author: YuZhangWang
 * @date: 2021/9/3 16:42
 * @link: https://www.yuzhang.wang/
***********************************/

#include<iostream>
#include<string>

using namespace std;

typedef struct Node {
    int num;
    char name[20];
    float DataStructure;
    float English;
    float average;
    Node *next;
} Node;

class StudList {
    Node *head;//头节点
public:
    StudList();//构造函数
    void CreateList();//建立一个空表
    void Display();//显示链表
    int getlen();//获取链表长度

    Node *GetHead();

    void averGrade(Node *node);//求平均成绩
    void Add();//头插法添加一个学生
    void Insert();//在第i个位置插入一个学生
    void Delete();//删除一个个学生
    void Alter();//修改指定学号学生的信息
    void sort();//根据输入的参数决定使用某门课程成绩排序
    void sortD();//按数据结构成绩排序
    void sortE();//按大学英语成绩排序
    void sortAver();//平均成绩排序
    void Seek();//查找相关学生信息

    void CountNode();//查询某一门学科不及格的人数和成绩单
    int CountNotD();//查询数据结构不及格的人数和成绩单
    int CountNotE();//查询某大学英语不及格的人数和成绩单
    void menu(StudList *list); //显示菜单
    void swapNode(Node *a, Node *b); //交换两节结点信息
};

StudList::StudList() {
    head = new Node();
    head->next = NULL;
}

void StudList::CreateList() {
    head->num = 0;
}

void StudList::Display() {
    Node *cur = head;
    int len = getlen();
    cout << "学生人数:" << len << endl;
    while (len--) {
        cout << "学号:" << cur->num;
        cout << " 姓名:" << cur->name;
        cout << " 数据结构成绩:" << cur->DataStructure;
        cout << " 大学英语成绩:" << cur->English;
        cout << " 平均成绩:" << cur->average << endl;
        cur = cur->next;
    }
}

int StudList::getlen() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }
    return n;
}

Node *StudList::GetHead() {
    return head;
}

void StudList::averGrade(Node *node) {
    node->average = (node->English + node->DataStructure) / 2;
}

void StudList::Add() {
    Node *p, *t;
    if (!head) {
        head = new Node();
    }
    t = head;
    p = new Node();

    cout << "输入学号:" << endl;
    cin >> p->num;

    while (t) {
        if (t->num == p->num) {
            cout << "已存在该学号！" << endl;
            return;
        }
        t = t->next;
    }

    cout << "输入姓名:" << endl;
    cin >> p->name;
    cout << "输入数据结构成绩:" << endl;
    cin >> p->DataStructure;
    cout << "输入大学英语成绩:" << endl;
    cin >> p->English;

    averGrade(p);

    if (head->num == 0) {
        head = p;
        return;
    }

    p->next = head;
    head = p;
}

void StudList::Insert() {
    int i, len;
    cout << "输入要插入学生的位置(插入到该位置前):";
    cin >> i;
    len = getlen();

    Node *cur, *t, *pr, *newNode;
    if (head == NULL || head->num == 0) {
        cout << "当前表为空！" << endl;
        StudList();
        return;
    }

    if (i < 2 || i > len) {
        cout << "该位置不存在" << endl;
        return;
    }

    cur = head;
    pr = head;

    i--;

    while (cur && i--) {
        pr = cur;
        cur = cur->next;
    }

    newNode = new Node();

    t = head;
    cout << "输入插入学生的学号:" << endl;
    cin >> newNode->num;

    while (t)//判断是否从在已有学号
    {
        if (t->num == newNode->num) {
            cout << "已存在该学号!" << endl;
            return;
        }
        t = t->next;
    }

    cout << "输入姓名:" << endl;
    cin >> newNode->name;
    cout << "输入数据结构成绩:" << endl;
    cin >> newNode->DataStructure;
    cout << "输入大学英语成绩:" << endl;
    cin >> newNode->English;
    averGrade(newNode);

    pr->next = newNode;
    newNode->next = cur;
}

void StudList::Delete() {
    int n;//n表示学号
    Node *cur, *pr;
    cur = head;
    pr = head;
    cout << "输入要删除学生的学号:";
    cin >> n;
    while (cur) {
        if (cur->num == n) {
            if (cur == head) {
                head = head->next;//如果删除的是头节点，直接令头节点为头节点的下一节点
                return;
            }
            pr->next = cur->next;
            return;
        }
        pr = cur;
        cur = cur->next;
    }
    cout << "没有查到要删除的学号" << endl;
    return;
}

void StudList::Alter() {
    int a, n;//n为学号
    Node *cur;
    cur = head;
    cout << "输入要修改学生的学号:";
    cin >> n;
    int len = getlen();
    if (n < 1 || n > len) {
        cout << "不存在该学号!" << endl;
        return;
    }

    while (cur) {
        if (cur->num == n) {
            cout << "1.修改姓名" << endl;
            cout << "2.修改数据结构成绩" << endl;
            cout << "3.修改大学英语成绩" << endl;
            cout << "请输入要修改的项目(输入其它不做修改):";
            cin >> a;
            switch (a) {
                case 1:
                    cout << "请输入修改姓名:";
                    cin >> cur->name;
                    return;
                case 2:
                    cout << "请输入修改的数据结构成绩:";
                    cin >> cur->DataStructure;
                    averGrade(cur);
                    return;
                case 3:
                    cout << "请输入修改的大学英语成绩:";
                    cin >> cur->English;
                    averGrade(cur);
                    return;
                default:
                    cout << "退出修改" << endl;
                    return;
            }
        }
        cur = cur->next;
    }
    return;
}

void StudList::sort() {
    int m;
    cout << "1.按数据结构成绩排序" << endl;
    cout << "2.按大学英语成绩排序" << endl;
    cout << " 选择某一门排序方式:";
    cin >> m;
    switch (m) {
        case 1:
            sortD();
            break;
        case 2:
            sortE();
            break;
        default:
            break;
    }
}

void StudList::sortD() {
    int len, inlen;
    Node *cur;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (inlen--) {
            if (cur->DataStructure < cur->next->DataStructure) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
}

void StudList::sortE() {
    int len, inlen;
    Node *cur;
    cur = head;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (cur && inlen--) {
            if (cur->English < cur->next->English) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
}

void StudList::sortAver() {
    int len, inlen, rank = 1;
    Node *cur;
    cur = head;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (cur && inlen--) {
            if (cur->average < cur->next->average) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
    cur = head;
    while (cur) {
        cout << "学号:" << cur->num
             << " 姓名:" << cur->name
             << "  数据结构成绩:" << cur->DataStructure
             << "  大学英语成绩:" << cur->English
             << "  平均成绩:" << cur->average
             << " 名次:" << rank << endl;

        if (cur->next && cur->average == cur->next->average) {
            cur = cur->next;
            continue;
        }
        rank++;
        cur = cur->next;
    }
}

void StudList::Seek() {
    int n;//n表示学号
    Node *cur, *pr;
    cur = head;
    pr = head;
    cout << "输入要查找学生的学号:";
    cin >> n;
    while (cur) {
        if (cur->num == n) {
            cout << "学号:" << cur->num;
            cout << "  姓名:" << cur->name;
            cout << "  数据结构成绩:" << cur->DataStructure;
            cout << "  大学英语成绩:" << cur->English;
            cout << "  平均成绩:" << cur->average << endl;
            return;
        }
        pr = cur;
        cur = cur->next;
    }
    cout << "没有查到要查找的学号" << endl;
    return;
}

void StudList::CountNode() {
    int m;
    cout << "1.统计数据结构成绩不及格名单。" << endl;
    cout << "2.统计大学英语成绩不及格名单。" << endl;
    cout << "输入选择方式：";
    cin >> m;
    switch (m) {
        case 1:
            CountNotD();
            break;
        case 2:
            CountNotE();
            break;
        default:
            break;
    }
}

int StudList::CountNotE() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        if (cur->English < 60) {
            cout << "学号:" << cur->num
                 << " 姓名:" << cur->name
                 << " 成绩:" << cur->English << endl;
            n++;
        }
        cur = cur->next;
    }
    cout << "共计大学英语不及格人数:" << n << endl;
    return n;
}

int StudList::CountNotD() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        if (cur->DataStructure < 60) {
            cout << "学号：" << cur->num
                 << " 姓名：" << cur->name
                 << " 成绩：" << cur->DataStructure << endl;
            n++;
        }
        cur = cur->next;
    }
    cout << "共计数据结构不及格人数：" << n << endl;
    return n;
}

void StudList::menu(StudList *list) {
    int a;
    cout << "------------------------------------" << endl;
    cout << "--   欢迎使用学生成绩表管理系统   --" << endl;
    cout << "------------------------------------" << endl;
    while (1) {
        cout << "  " << "--------------------------------" << endl;
        cout << "  " << "|   1.显示所有学生信息         |" << endl;
        cout << "  " << "|   2.添加一个学生信息         |" << endl;
        cout << "  " << "|   3.修改一个学生成绩         |" << endl;
        cout << "  " << "|   4.删除一个学生成绩         |" << endl;
        cout << "  " << "|   5.插入一个学生成绩         |" << endl;
        cout << "  " << "|   6.按平均成绩排名           |" << endl;
        cout << "  " << "|   7.按某一课成绩排序         |" << endl;
        cout << "  " << "|   8.统计某一课成绩不及格人数 |" << endl;
        cout << "  " << "|   9.查找相关学生信息         |" << endl;
        cout << "  " << "--------------------------------" << endl;
        cin >> a;
        switch (a) {
            case 1:
                list->Display();
                break;

            case 2:
                list->Add();
                break;

            case 3:
                list->Display();
                list->Alter();
                list->Display();
                break;

            case 4:
                list->Display();
                list->Delete();
                list->Display();
                break;

            case 5:
                list->Display();
                list->Insert();
                list->Display();
                break;

            case 6:
                list->sortAver();
                break;

            case 7:
                list->sort();
                list->Display();
                break;

            case 8:
                list->CountNode();
                break;

            default:
                list->Seek();
                break;
        }
    }
}

void StudList::swapNode(Node *a, Node *b)//交换两结点的信息 
{
    int temp;
    char c;
    float ft;

    temp = a->num;
    a->num = b->num;
    b->num = temp;


    for (int i = 0; i < 20; i++)//姓名交换
    {
        c = a->name[i];
        a->name[i] = b->name[i];
        b->name[i] = c;
    }

    ft = a->DataStructure;
    a->DataStructure = b->DataStructure;
    b->DataStructure = ft;

    ft = a->English;
    a->English = b->English;
    b->English = ft;

    ft = a->average;
    a->average = b->average;
    b->average = ft;
}

int main() {
    StudList list;
    list.CreateList();
    list.menu(&list);
    return 0;
}