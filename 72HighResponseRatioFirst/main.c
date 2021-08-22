#include"string.h"
#include <stdio.h>

#define n 10
typedef struct jcb {
    char name[4]; //��ҵ��
    int length;  //��ҵ��С
    int tape; //�Ŵ�����
    int printer; //��ӡ����
    int waittime; //�ȴ�ʱ��
    int runtime; //��������ʱ��
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
            printf("ѡ�е���ҵ����ҵ��: %s\n", jobtable[q].name);
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
    printf("��������ҵ�������(����ҵ��СΪ����ֹͣ����):\n");
    printf("������ҵ�� ��ҵ��С �Ŵ����� ��ӡ���� �ȴ�ʱ�� ��������ʱ��\n");
    scanf("%s %d %d %d %d %d", name, &size, &tcount, &pcount, &wtime, &rtime);
    while (size != -1) {
        if (jobcount < n)
            p = jobcount;
        else {
            printf("�޷��ڴ�����ҵ\n");
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
        printf("������ҵ�� ��ҵ��С �Ŵ����� ��ӡ���� �ȴ�ʱ�� ��������ʱ��\n");
        scanf("%s %d %d %d %d %d", name, &size, &tcount, &pcount, &wtime, &rtime);
    }
    shedule();
    return;
}