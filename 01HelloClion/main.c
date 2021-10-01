#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10 //定义最大长度

typedef struct {
    int data[MaxSize]; //用静态的“数组”存放数据元素
    int length; //顺序表的当前长度
} SqList;

void InitList(SqList L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0; //所有元素初始值为10以内的随机数
    }
    L.length = 0; //表的初始长度为0
}
/*
void ListInsert(SqList &L,int i,int e){
	for(int j=L.length;j>=i;j--){ //将第i个元素及之后的元素往后移
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e; //在位置i处放入e
	L.length++;	 //长度加1
}
*/
//判断插入数据是否合法,并插入
bool ListInsert(SqList L, int i, int e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) { //将第i个元素及之后的元素往后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; //在位置i处放入e
    L.length++;
    return true;
}

bool ListDelete(SqList L, int i, int e) {
    if (i < 1 || i > L.length) //判断i的范围是否有效
        return false;
    e = L.data[i - 1]; //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++) { //将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    }
    L.length--; //线性表长度减1
    return true;
}

void PrintList(SqList L) {
    for (int i = 0; i < MaxSize; i++) {
        printf("%d\n", L.data[i]);
    }
}

int main() {
    SqList L; //声明一个顺序表
    InitList(L); //初始化顺序表
    PrintList(L);
    printf("\n");
    ListInsert(L, 1, 3);
    PrintList(L);
    return 0;
}