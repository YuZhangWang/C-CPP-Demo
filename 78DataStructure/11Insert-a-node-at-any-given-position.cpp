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

void Insert(int data, int n) {
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
};

void Print() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
};

int main() {
    head = NULL;  //empty list
    Insert(2, 1); //List: 2
    Insert(3, 2); //List: 2,3
    Insert(4, 1); //List: 4,2,3
    Insert(5, 2); //List: 4,5,2,3
    Print();
    return 0;
};