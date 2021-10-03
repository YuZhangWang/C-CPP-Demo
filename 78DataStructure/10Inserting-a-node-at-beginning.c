/***********************************
 * @author: YuZhangWang
 * @date: 2021/10/4 0:45
 * @link: https://www.yuzhang.wang/
***********************************/
//Linked List: Inserting a node at beginning
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};
// struct Node *head;  //global variable, can be accessed anywhere

void Insert(struct Node **pointerToHead, int x) {
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (*pointerToHead != NULL) temp->next = *pointerToHead;
    *pointerToHead = temp;
}

void Print(struct Node *head) {
    // struct Node *temp = head;
    printf("List is:");
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;  //empty list
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    printf("Enter the number \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    return 0;
};