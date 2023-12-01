#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(int k) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->val = k;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void Insert(struct Node** T, int k) {
    if (*T == NULL) {
        *T = CreateNode(k);
    } else if (k < (*T)->val) {
        Insert(&((*T)->left), k);
    } else if (k > (*T)->val) {
        Insert(&((*T)->right), k);
    }
}

void Print(struct Node* T) {
    if (T == NULL) {
        printf("( ) ");
        return;
    }

    printf("( %d ", T->val);
    Print(T->left);
    Print(T->right);
    printf(") ");
}

int main() {
    struct Node* root = NULL;

    char ch;
    int value;

    while (1) {
        scanf(" %c", &ch);
        if (ch == 'e') {
            break;
        }
        if (ch == 'i') {
            scanf("%d", &value);
            Insert(&root, value);
        } else if (ch == 'p') {
            if (root == NULL) {
                printf("( )\n");
            } else {
                Print(root);
                printf("\n");
            }
        }
    }

    return 0;
}
