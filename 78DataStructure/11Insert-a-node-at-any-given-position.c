/*********************************** 
 * @author: YuZhangWang
 * @date: 2021/10/4 1:29
 * @link: https://www.yuzhang.wang/
***********************************/
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head;

int main() {
    head = NULL;  //empty list
    return 0;
};