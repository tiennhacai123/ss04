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
int searchElement(Node* head, int value) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return index; y
        }
        temp = temp->next;
        index++;
    }
    return -1; 
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
    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    int result = searchElement(head, searchValue);
    if (result != -1) {
        printf("Tim thay gia tri %d o vi tri: %d\n", searchValue, result);
    } else {
        printf("Khong tim thay gia tri %d\n", searchValue);
    }

    return 0;
}
