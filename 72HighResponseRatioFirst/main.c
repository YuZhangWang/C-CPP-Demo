#include"string.h"
#include <stdio.h>

#define n 10
typedef struct jcb {
    char name[4]; //作业名
    int length;  //作业大小
    int tape; //磁带机数
    int printer; //打印机数
    int waittime; //等待时间
    int runtime; //估计运行时间
    int next;
} JCB;

int head;
int tape, printer;
long memory;
JCB jobtable[n];
int jobcount = 0;

shedule() {
    float xk, k;
    int p, q, s, t;
    do {
        p = head;
        q = s = -1;
        k = 0;
        while (p != -1) {
            if (jobtable[p].length <= memory && jobtable[p].tape <= tape && jobtable[p].printer <= printer) {
                xk = (float) (jobtable[p].runtime);
                if (q == 0 || xk < jobtable[p + 1].runtime) {
                    k = xk;
                    q = p;
                    t = s;
                }
            }
            s = p;
            p = jobtable[p].next;
        }
        if (q != -1) {
            if (t == -1)
                head = jobtable[head].next;
            else
                jobtable[t].next = jobtable[q].next;
            memory = memory - jobtable[q].length;
            tape = tape - jobtable[q].tape;
            printer = printer - jobtable[q].printer;
            printf("选中的作业的作业名: %s\n", jobtable[q].name);
        }
    } while (q != -1);
}

void main() {
    char name[4];
    int size, tcount, pcount, wtime, rtime;
    int p;
    memory = 65536;
    tape = 4;
    printer = 2;
    head = -1;
    printf("请输入作业相关数据(以作业大小为负数停止输入):\n");
    printf("输入作业名 作业大小 磁带机数 打印机数 等待时间 估计运行时间\n");
    scanf("%s %d %d %d %d %d", name, &size, &tcount, &pcount, &wtime, &rtime);
    while (size != -1) {
        if (jobcount < n)
            p = jobcount;
        else {
            printf("无法在创建作业\n");
            break;
        }
        jobcount++;
        strcpy(jobtable[p].name, name);
        jobtable[p].length = size;
        jobtable[p].printer = pcount;
        jobtable[p].tape = tcount;
        jobtable[p].runtime = rtime;
        jobtable[p].waittime = wtime;
        jobtable[p].next = head;
        head = p;
        printf("输入作业名 作业大小 磁带机数 打印机数 等待时间 估计运行时间\n");
        scanf("%s %d %d %d %d %d", name, &size, &tcount, &pcount, &wtime, &rtime);
    }
    shedule();
    return;
}