#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct LNode {
    int data; // 数据域
    struct LNode* next; // 指针域，指向下一个节点
} LNode, * LinkedList;

// 函数声明
void CreateLinkedList(LinkedList* L);
void InsertLinkedList(LinkedList L, int position, int value);
void DeleteLinkedList(LinkedList* L, int position);
void DestroyLinkedList(LinkedList* L);
void PrintLinkedList(LinkedList L);

int main() {
    // 创建链表
    LinkedList L;
    CreateLinkedList(&L);

    // 向链表插入数据
    InsertLinkedList(L, 1, 1);
    InsertLinkedList(L, 2, 2);
    InsertLinkedList(L, 3, 3);

    // 打印链表
    PrintLinkedList(L);

    // 删除链表中的节点
    DeleteLinkedList(&L, 2);

    // 再次打印链表
    PrintLinkedList(L);

    // 销毁链表
    DestroyLinkedList(&L);

    return 0;
}

// 创建链表函数实现
void CreateLinkedList(LinkedList* L) {
    *L = (LNode*)malloc(sizeof(LNode)); // 创建头结点
    (*L)->next = NULL; // 初始化头结点的指针域为NULL
}

// 插入节点函数实现
void InsertLinkedList(LinkedList L, int position, int value) {
    int i;
    LNode* p = L; // p指向头结点
    LNode* current;

    // 寻找插入位置的前一个节点
    for (i = 1; p != NULL && i < position; i++) {
        p = p->next;
    }

    // 检查position是否有效
    if (p == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // 创建新节点
    current = (LNode*)malloc(sizeof(LNode));
    current->data = value; // 设置新节点的数据
    current->next = p->next; // 将新节点的指针域指向前一个节点的下一个节点
    p->next = current; // 更新前一个节点的指针域，指向新节点
}

// 删除节点函数实现
void DeleteLinkedList(LinkedList* L, int position) {
    int i;
    LNode* p = *L; // p指向头结点
    LNode* temp;

    // 寻找要删除的节点的前一个节点
    for (i = 1; p != NULL && i < position; i++) {
        p = p->next;
    }

    // 检查position是否有效
    if (p == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // 删除节点
    temp = p->next;
    p->next = temp->next;
    free(temp); // 释放被删除节点的内存
}

// 销毁链表函数实现
void DestroyLinkedList(LinkedList* L) {
    LNode* p = *L;
    while (p != NULL) {
        LNode* temp = p;
        p = p->next;
        free(temp);
    }
    *L = NULL;
    printf("The linked list has been destroyed.\n");
}

// 打印链表函数实现
void PrintLinkedList(LinkedList L) {
    LNode* p = L->next; // 从头结点的下一个节点开始遍历
    if (p == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List (head to tail): ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
