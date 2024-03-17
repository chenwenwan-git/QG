#include <stdio.h>
#include <stdlib.h>

// 创建结构体
typedef struct Node {
    int data;//数据域
    struct Node* prev;// 前驱节点指针
    struct Node* next;// 后继节点指针
} Node;


typedef struct DoublyLinkedList {
    int size;
    Node* front;
    Node* tail;
} DoublyLinkedList;

// 创建函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


DoublyLinkedList* creatList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->size = 0;
    list->front = list->tail = NULL;
    return list;
}




// 插入头节点
void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->front == NULL) {
        list->front = newNode;
        list->tail = newNode;
    }
    else {
        list->front->prev = newNode;
        newNode->next = list->front;
    }
    list->front = newNode;
    list->size++;
    
}

void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) {
        list->front = newNode;
        
    }
    else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
    }
    list->tail = newNode;
    list->size++;
}

void insertAtPos(DoublyLinkedList* list, int data, int posdata) {
    if (list->size == 0) {
        printf("The list is empty.\n");
        return;
    }
    else if (list->front->data == posdata) {
        insertAtBeginning(list, data);
    }
    else {
        Node* posNode = list->front->next;
        Node* posNodeLeft = list->front;
        while (posNode != NULL && posNode->data != posdata) {
            posNodeLeft = posNode;
            posNode = posNode->next;

        }
        if (posNode == NULL) {
            printf("fail founded!\n");
            return;
        }
        else {
            Node* newNode = createNode(data);
            posNodeLeft->next = newNode;
            newNode->prev = posNodeLeft;
            newNode->next = posNode;
            posNode->prev = newNode;
        }
    }
}


// 打印函数
void displayByleft(DoublyLinkedList* list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
    }
    else {
        Node* current = list->tail;
        while (current) {

            printf("%d\t", current->data);
            current = current->prev;
        }
    }
    printf("\n");
}

void displayByright(DoublyLinkedList* list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
    }
    else {
        Node* current = list->front;
        while (current) {

            printf("%d\t", current->data);
            current = current->next;
        }
    }
    printf("\n");
}


int main() {
    DoublyLinkedList* list = creatList();

    insertAtBeginning(list, 3);
    insertAtBeginning(list, 2);
    insertAtBeginning(list, 1);
    insertAtPos(list, 200, 1);
    displayByleft(list);
    displayByright(list);
    insertAtEnd(list, 100);
    displayByleft(list);
    displayByright(list);
    

    return 0;
}
