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
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return head;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    int index = 0;
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL || temp->next == NULL) { 
        printf("Vi tri khong hop le\n");
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

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
    head->next->next->next = createNode(40);
    printf("Danh sach ban dau: ");
    printList(head);
    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);
    printf("Danh sach sau khi xoa: ");
    printList(head);

    return 0;
}
