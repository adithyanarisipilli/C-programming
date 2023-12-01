#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* CREATE_NODE(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
struct Node* LIST_SEARCH(struct Node* head, int y) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == y) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
struct Node* LIST_INSERT_FRONT(struct Node* head, int x) {
    struct Node* temp = CREATE_NODE(x);
    if (head == NULL) {
        head = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}
struct Node* LIST_INSERT_TAIL(struct Node* head, int x) {
    struct Node* temp = CREATE_NODE(x);
    struct Node* trv = head;
    if (trv == NULL) {
        head = temp;
        return head;
    }
    while (trv->next != NULL) {
        trv = trv->next;
    }
    trv->next = temp;
    temp->prev = trv;
    return head;
}
struct Node* LIST_INSERT_AFTER(struct Node* head, int x, int y) {
    struct Node* temp1 = LIST_SEARCH(head, y); //this is pptr
    struct Node* temp2 = CREATE_NODE(x);
    if (temp1->next == NULL) {
        head = LIST_INSERT_TAIL(head, x);
        return head;
    }
    else {
        temp1->next->prev = temp2;
        temp2->next = temp1->next;
        temp2->prev = temp1;
        temp1->next = temp2;
        return head;
    }
}
struct Node* LIST_INSERT_BEFORE(struct Node* head, int x, int y) {
    struct Node* prev = head;
    struct Node* ptr = head;
    struct Node* temp2 = CREATE_NODE(x);
    while (ptr != NULL) {
        if (ptr->data == y) {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == head) {
        head = LIST_INSERT_FRONT(head, x);
        return head;
    }
    ptr->prev->next = temp2;
    temp2->prev = ptr->prev;
    temp2->next = ptr;
    ptr->prev = temp2;
    return head;
}
struct Node* LIST_DELETE_FIRST(struct Node* head) {
    struct Node* ptr = head;
    if(ptr==NULL){
        printf("-1\n");
        return head;
    }
    printf("%d\n", ptr->data);
    head = ptr->next;
    ptr->next->prev = NULL;
    ptr->next = NULL;
    return head;
}
struct Node* LIST_DELETE_LAST(struct Node* head) {
    struct Node* ptr = head;
    if(ptr==NULL){
        printf("-1\n");
        return head;
    }
    if(ptr->next==NULL){
       printf("%d\n", ptr->data); 
       return head;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("%d\n", ptr->data);
    ptr->prev->next = NULL;
    ptr->next = NULL;

    return head;
}
struct Node* LIST_DELETE(struct Node* head, int x) {
    struct Node* ptr = head;
    struct Node* bef = head;
    struct Node* temp = LIST_SEARCH(head, x);
    if(temp==NULL){
        printf("-1");
        return head;
    }
    if(temp==head){
        head=LIST_DELETE_FIRST(head);
        return head;
    }
    while (ptr!=NULL&&ptr->data != x) {
        bef = ptr;
        ptr = bef->next;
    }
    if (ptr->next == NULL) {
        head = LIST_DELETE_LAST(head);
        return head;
    }
    if (ptr->prev == NULL) {
        head = LIST_DELETE_FIRST(head);
        return head;
    }
    bef->next = ptr->next;
    ptr->next->prev = bef;

    printf("%d\n", x);
    return head;
}

struct Node* LIST_DISPLAY(struct Node* head) {
    struct Node* trv = head;
    while (trv != NULL) {
        printf("%d ", trv->data);
        trv = trv->next;
    }
    printf("\n");
    return head;
}
struct Node* LIST_REVERSE_NEGATIVE(struct Node* head) {

    struct Node* left = head;
    struct Node* right = head;
    while (right->next != NULL) {
        right = right->next;
    }
    while (left != NULL && right != NULL && left->prev != right && left != right ) {
        while (left != NULL && left->data >=0 ) {
            left = left->next;
        }
        while (right != NULL && right->data >=0 ) {
            right = right->prev;
        }
        if (left != NULL && right != NULL && left != right && left->prev != right  ) {
            int temp = right->data;
            right->data = left->data;
            left->data = temp;
            left = left->next;
            right = right->prev;
        }
    }
    return head;
}
int main(int argc, char const *argv[])
{
    char ch;
    int x, y;
    struct Node* head = NULL;
    while (1) {
        scanf("%c", &ch);
        if (ch == 'e') {
            break;
        }
        if (ch == 'f') {
            int a;
            scanf(" %d", &a);
            head = LIST_INSERT_FRONT(head, a);
        }
        if (ch == 't') {
            int a;
            scanf(" %d", &a);
            head = LIST_INSERT_TAIL(head, a);
        }
        if (ch == 'a') {
            int a, b;
            scanf("%d %d", &a, &b);
            head = LIST_INSERT_AFTER(head, a, b);
        }
        if (ch == 'b') {
            int a, b;
            scanf("%d %d", &a, &b);
            head = LIST_INSERT_BEFORE(head, a, b);
        }
        if (ch == 'd') {
            char ch1;
            scanf("%c", &ch1);
            if (ch1 == 's') {
                head = LIST_DISPLAY(head);
            }
            else {
                int a;
                scanf("%d", &a);
                head = LIST_DELETE(head, a);
            }
        }
        if (ch == 'i') {
            head = LIST_DELETE_FIRST(head);
        }
        if (ch == 'l') {
            head = LIST_DELETE_LAST(head);
        }
        if (ch == 's') {
            int a;
            scanf(" %d", &a);
            struct Node* temp;
            temp = LIST_SEARCH(head, a);
            if (temp == NULL) {
                printf("-1\n");
            }
            else {
                printf("1\n");
            }
        }
        if (ch == 'r') {
            head = LIST_REVERSE_NEGATIVE(head);
            head = LIST_DISPLAY(head);
        }
    }
    return 0;
}



