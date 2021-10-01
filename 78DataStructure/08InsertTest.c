#include <stdio.h>
#include <stdbool.h>

#define MaxSize 5

typedef struct {    //定义一个顺序表SqList(静态分配)
    int data[MaxSize];
    int length;
} SqList;

void initSqlist(SqList *l) {     //初始化顺序表
    for (int i = 0; i < MaxSize; ++i) {     //将顺序表内所有元素初始化为0
        l->data[i] = 0;
    }
    l->length = 0;      //长度定义为0
}

void empty(SqList *l) {       //判空操作
    if (l->length == 0) {
        printf("当前顺序表为空\n");
    } else {
        printf("当前顺序表非空,顺序表长度为%d\n", l->length);
    }
}

int insertSqList(SqList *l, int i, int e) {       //往顺序表内插入元素
    if (l->length + 1 > MaxSize) {      //判断插入后长度是否超过数组最大长度
        printf("顺序表已到大长度,插入失败\n");
        return 0;
    } else if (i < 1 || i > l->length + 1) {     //判断插入位置是否正确
        printf("要插入的位置不正确\n");
        return 0;
    } else {
        for (int j = l->length; j >= i; j--) {
            l->data[j] = l->data[j - 1];
        }
        l->data[i - 1] = e;
        printf("插入前顺序表长度为%d\n", l->length);
        l->length++;
        printf("插入成功,插入后顺序表长度为%d\n", l->length);
        return 1;
    }
}

void printSqList(SqList *l) {     //遍历输出顺序表
    if (l->length == 0) {
        printf("当前顺序表内没有元素\n");
    } else {
        printf("当前顺序表内元素有: ");
        for (int i = 0; i < l->length; ++i) {
            printf("%d ", l->data[i]);
        }
        printf("\n");
    }
}

int get(SqList *l, int i) {     //按位查找
    if (i < 1 || i > l->length) {      //判断所查位置是否合法
        printf("所查位置不存在");
        return 0;
    } else {      //查找并返回结果
        int flag = l->data[i - 1];
        //printf("查找成功,所在位置元素为%d",flag);
        return flag;
    }
}

void locate(SqList *l, int e) {      //按值查找
    for (int i = 0; i < l->length; ++i) {
        if (e == l->data[i]) {
            printf("查找成功!值为%d的位置为%d\n", e, i + 1);
        }
    }
}

void change(SqList *l, int i, int e) {        //将第i个位置的元素修改成e
    if (i < 1 || i > l->length) {
        printf("所修改的位置不存在!");
    } else {
        l->data[i - 1] = e;
    }
}

bool deleteSqList(SqList *l, int i) {        //删除指定位置元素
    if (i < 1 || i > l->length) {
        printf("删除失败!输入的位置不存在\n");
        return false;
    } else {
        for (int j = i - 1; j < l->length; j++) {
            l->data[j] = l->data[j + 1];
        }
        l->length--;
        return true;
    }
}

int main() {
    SqList l;   //创建顺序表
    initSqlist(&l);     //初始化顺序表
    empty(&l);      //判空操作
    insertSqList(&l, 1, 3);       //在第一个位置插入3
    insertSqList(&l, 1, 2);       //在第一个位置插入2
    insertSqList(&l, 1, 1);       //在第一个位置插入1
    insertSqList(&l, 1, 4);       //在第一个位置插入3
    insertSqList(&l, 1, 4);       //在第一个位置插入3
    insertSqList(&l, 1, 4);       //在第一个位置插入3
    empty(&l);      //判空操作
    printSqList(&l);        //遍历输出顺序表
    int flag = get(&l, 3);       //查找位置为3的元素并赋值给flag(按位查找)
    printf("所查找位置的值为:%d\n", flag);
    locate(&l, 3);       //查找值为3的元素并输出(按值查找)
    deleteSqList(&l, 2);     //删除位置为2的元素
    printSqList(&l);        //遍历输出顺序表,查看删除后的结果
    change(&l, 1, 5);     //将第一个位置的元素修改成5
    printSqList(&l);        //遍历输出顺序表,查看删除后的结果
    return 0;
}