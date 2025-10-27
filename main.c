//
//  main.c
//  LInklistDemo
//
//  Created by edy on 2025/10/27.
//

#include <stdio.h>
#include <stdlib.h> // malloc, free

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *next;
} LinkNode, *LinkList;   // LinkList 是指向结点的指针， L 指向头结点 (哨兵)


// 5 -1 3 5

void deleteMin(LinkList L) {
    // 删除唯一最小值结点（假设最小值存在且唯一；若链表空或只有头结点则直接返回）
    if (L == NULL || L -> next == NULL) return;
    
    LinkList prev = L;
    LinkList p = L -> next;
    LinkList minPrev = L;
    LinkList minNode = L -> next;
    
    while (p != NULL) {
        if (p -> data < minNode ->data) { // 如果更小值，则更新
            minNode = p;
            minPrev = prev;
        }
        prev = p;
        p = p -> next;
    }
    // 断链表并释放最小结点
    minPrev -> next = minNode -> next;
    free(minNode);
}

void appendNode(LinkList head, DataType val) {
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->data = val;
    node->next = NULL;
    
    LinkNode *tail = head;
    while (tail -> next) {
        tail = tail -> next;
    }
    tail->next = node;
}

void printList(LinkList head, const char *msg) {
    printf("%s", msg);
    LinkNode *p = head -> next; // 跳过哨兵
    while (p != NULL) {
        printf("%d",p->data);
        if (p -> next != NULL) {
            printf(" -> ");
        }
        p = p -> next; // 无论如何都要前进
    }
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    LinkList head = (LinkNode *)malloc(sizeof(LinkNode));
    head -> next = NULL;
    
    appendNode(head, 5);
    appendNode(head, -1);
    appendNode(head, 4);
    appendNode(head, -5);

    printList(head, "Before deleteMin: ");

    deleteMin(head);
    
    printList(head, "After deleteMin:");
    
    return 0;
}
