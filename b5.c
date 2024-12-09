#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) { 
        printf("Vi tri nam ngoai pham vi danh sach\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    printf("Danh sach ban dau: ");
    printList(head);
    int value, position;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);
    printf("Danh sach sau khi chen: ");
    printList(head);

    return 0;
}
