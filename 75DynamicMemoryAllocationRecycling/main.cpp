#include "stdio.h"
#include <iostream>
#include "string.h"
#include <iomanip>

using namespace std;

const int MAXJOB = 100;      //定义表最大记录数
typedef struct node {
    int start;
    int length;
    char tag[20];
} job;
job frees[MAXJOB];     //定义空闲区表
int free_quantity;
job occupys[MAXJOB];     //定义已分配区表
int occupy_quantity;

void initial()           //初始化函数
{
    int i;
    for (i = 0; i < MAXJOB; i++) {
        frees[i].start = -1;
        frees[i].length = 0;
        strcpy(frees[i].tag, "free");
        occupys[i].start = -1;
        occupys[i].length = 0;
        strcpy(occupys[i].tag, "");
    }
    free_quantity = 0;
    occupy_quantity = 0;
}

int readData()           //读数据函数
{
    FILE *fp;
    char fname[20];
    cout << "请输入初始空闲表文件名:";
    cin >> fname;
    if ((fp = fopen(fname, "r")) == NULL) {
        cout << "错误,文件打不开,请检查文件名" << endl;
    }
    else {
        while (!feof(fp)) {
            fscanf(fp, "%d,%d", &frees[free_quantity].start, &frees[free_quantity].length);
            free_quantity++;
        }
        return 1;
    }
    return 0;
}

void sort()        //空闲链表排序
{
    int i, j, p;
    for (i = 0; i < free_quantity - 1; i++) {
        p = i;
        for (j = i + 1; j < free_quantity; j++) {
            if (frees[j].start < frees[p].start) {
                p = j;
            }
        }
        if (p != i) {
            frees[free_quantity] = frees[i];
            frees[i] = frees[p];
            frees[p] = frees[free_quantity];
        }
    }
}

void view()          //显示函数
{
    int i;
    cout << endl << "----------------------------------------------------------" << endl;
    cout << "当前空闲表:" << endl;
    cout << "起始地址 长度 状态" << endl;
    for (i = 0; i < free_quantity; i++) {
        cout.setf(static_cast<_Ios_Fmtflags>(2));
        cout.width(12);
        cout << frees[i].start;
        cout.width(10);
        cout << frees[i].length;
        cout.width(8);
        cout << frees[i].tag << endl;
    }
    cout << endl << "----------------------------------------------------------" << endl;
    cout << "当前已分配表:" << endl;
    cout << "起始地址 长度 占用作业名" << endl;
    for (i = 0; i < occupy_quantity; i++) {
        cout.setf(static_cast<_Ios_Fmtflags>(2));
        cout.width(12);
        cout << occupys[i].start;
        cout.width(10);
        cout << occupys[i].length;
        cout.width(8);
        cout << occupys[i].tag << endl;
    }
}

void earliest(int th)     //内存分配
{
    char job_name[20];
    int job_length;
    int i, j, flag, index;
    cout << "请输入新申请内存空间的作业名和空间大小:";
    cin >> job_name;
    cin >> job_length;
    flag = 0;
    for (i = 0; i < free_quantity; i++) {
        if (frees[i].length >= job_length) {
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 0) {
        cout << endl << "Sorry,当前没有能满足你申请长度的空闲内存,请稍候再试" << endl;
    }
    else {
        i = index;

        occupys[occupy_quantity].start = frees[i].start;
        strcpy(occupys[occupy_quantity].tag, job_name);
        if (frees[i].length > job_length + th) {
            occupys[occupy_quantity].length = job_length;
            frees[i].start += job_length;
            frees[i].length -= job_length;
        }
        else {
            occupys[occupy_quantity].length = frees[i].length;

            for (j = i; j < free_quantity - 1; j++) {
                frees[j] = frees[j + 1];
            }
            free_quantity--;
        }
        cout << "内存空间成功:)" << endl;
        occupy_quantity++;
    }
}

void finished()      //内存回收
{
    char job_name[20];
    int i, j, flag, p = 0;
    int start;
    int length;

    cout << "请输入要撤消的作业名:";
    cin >> job_name;
    flag = -1;
    for (i = 0; i < occupy_quantity; i++) {
        if (!strcmp(occupys[i].tag, job_name)) {
            flag = i;
            start = occupys[i].start;
            length = occupys[i].length;
        }
    }
    if (flag == -1) {
        cout << "没有这个作业名" << endl;
    }
    else {
        //加入空闲表
        for (i = 0; i < free_quantity; i++) {
            if ((frees[i].start + frees[i].length) == start) {
                if (((i + 1) < free_quantity) && (frees[i + 1].start == start + length)) {
                    frees[i].length = frees[i].length + frees[i + 1].length + length;
                    for (j = i + 1; j < free_quantity; j++) {
                        frees[j] = frees[j + 1];
                    }
                    free_quantity--;
                    p = 1;
                }
                else {
                    frees[i].length += length;
                    p = 1;
                }
            }
            if (frees[i].start == (start + length)) {
                frees[i].start = start;
                frees[i].length += length;
                p = 1;
            }
        }
        if (p == 0) {
            frees[free_quantity].start = start;
            frees[free_quantity].length = length;
            free_quantity++;
        }
        //删除分配表中的该作业
        for (i = flag; i < occupy_quantity; i++) {
            occupys[i] = occupys[i + 1];
        }
        occupy_quantity--;
    }
}

int main() {
    int flag = 0;
    int t = 1;
    int chioce = 0;
    cout << " 　　　 　可变分区存储管理模拟系统　 　　　　  " << endl;
    cout << "       ━━━━━━━━━━━━━━━━━━━━━━━         " << endl;
    initial();
    flag = readData();
    while (flag == 1) {
        sort();
        cout << endl << endl << "==================================================" << endl;
        cout << " 可变分区存储管理模拟系统" << endl;
        cout << "=========================================================" << endl;
        cout << " 1.申请空间 2.撤消作业 3.显示空闲表和分配表 0.退出" << endl;
        cout << "请选择:";
        cin >> chioce;
        switch (chioce) {
            case 1:
                earliest(1);
                break;
            case 2:
                finished();
                break;
            case 3:
                view();
                break;
            case 0:
                flag = 0;
                break;
            default:
                cout << "选择错误!" << endl;
        }
    }
}