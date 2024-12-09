#include<stdio.h>
#include<stdlib.h>
//dinh nghia 1 node(nut)
typedef struct Node{
    int data; //phan du lieu cua node
    struct Node* next; // con tro tro den node tiep theo
} Node;

// Tao 1 Node moi
Node* createNode(int value){
    // cấp phát bộ nhớ động
    Node* newNode = (Node*) malloc(sizeof(Node));
    // gán data cho node
    newNode->data = value;
    // gán phần link
    newNode->next = NULL;
    return newNode;
}
//thêm 1  phần tử vào list
void insertHead(Node** head, int value){
    // tạo node mới 
    Node* newNode = createNode(value);
    // trỏ node mới đến head
    newNode->next = *head;
    // cập nhật head trỏ đến node mới
    *head = newNode;
}

void insertEnd(Node** head, int  value) {
    // Tạo nút mới
    Node* newNode = createNode(value);
    // tro node moi den head

    if(head == NULL){

    }
}

// duyệt danh sách 
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL ){
        printf("%d-->NULL", temp->data);
        temp = temp->next;
    }
}
int main(){
    Node* head = NULL;
    // them 1 phan tu vao đầu danh sách (head)
    
    // in ra danh sách 
    printf("Danh sach:");
    printList(head);
    do{
        printf("\n=================Menu=================");
        printf("\n 1. Them 1 phan tu vao dau");
        printf("\n2. Xem danh sach");
        printf("\n 3. Thoat");
        printf("\nMoi ban chon");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Moi ban nhap vao phan tu dau: ");
                int value;
                scanf("%d",&value);
                insertHead(&head, value);
            break;
            case 2:
                // in ra  
                    printf("Danh sach:");
                    printList(head);
                    break;
            case 3:
                exit(0);
            default:
            printf("Vui long chon lai");
        }
    }while(1==1);
    return 0;
}