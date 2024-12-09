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
Node* addToTail(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return NULL;
    }
    Node* temp = head; 
    head = head->next; 
    free(temp);
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
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        head = addToTail(head, value);
    }
    printf("Danh sach sau khi nhap: ");
    printList(head);
    head = deleteHead(head);
    printf("Danh sach sau khi xoa phan tu dau: ");
    printList(head);

    return 0;
}
