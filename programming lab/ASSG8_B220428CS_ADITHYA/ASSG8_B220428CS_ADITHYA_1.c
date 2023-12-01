#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* CreateNode(int k, struct Node* parent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->val = k;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = parent;
    }
    return newNode;
}

void Insert(struct Node** T, int k, struct Node* parent) {
    if (*T == NULL) {
        *T = CreateNode(k, parent);
    } else if (k > (*T)->val) {
        Insert(&((*T)->left), k, *T);
    } else if (k < (*T)->val) {
        Insert(&((*T)->right), k, *T);
    }
}

struct Node* Search(struct Node* T, int k) {
    if (T == NULL || T->val == k) {
        return T;
    }
    if (k > T->val) {
        return Search(T->left, k);
    }
    return Search(T->right, k);
}

int FindMin(struct Node* T) {
    if (T == NULL) {
        return -1; 
    }
    while (T->right != NULL) {
        T = T->right;
    }
    return T->val;
}

int FindMax(struct Node* T) {
    if (T == NULL) {
        return -1; 
    }
    while (T->left != NULL) {
        T = T->left;
    }
    return T->val;
}

void Inorder(struct Node* T, int*a) {
    if (T == NULL) {
        return;
    }
    *a = 1;
    if (T->left != NULL) Inorder(T->left, a);
    printf("%d ", T->val);
    if (T->right != NULL) Inorder(T->right, a);
}

void Preorder(struct Node* T, int*a) {
    if (T == NULL) {
        return;
    }
    *a = 1;
    printf("%d ", T->val);
    if (T->left != NULL) Preorder(T->left, a);
    if (T->right != NULL) Preorder(T->right, a);
}

void Postorder(struct Node* T, int*a) {
    if (T == NULL) {
        return;
    }
    *a = 1;
    if (T->left != NULL) Postorder(T->left, a);
    if (T->right != NULL) Postorder(T->right, a);
    printf("%d ", T->val);
}

int main() {
    struct Node* root = NULL;

    char ch;
    int value;
    int f = 1;
    while (1) {
        scanf(" %c", &ch);
        if (ch == 'e') {
            break;
        }
        if (ch == 'a') {
            scanf("%d", &value);
            f = 0;
            Insert(&root, value, NULL);
        } else if (ch == 's') {
            scanf("%d", &value);
            struct Node* result = Search(root, value);
            if (result == NULL && f != 1) {
                printf("N\n");
            } else if (result != NULL) {
                printf("F\n");
            }
        } else if (ch == 'x') {
            int maxVal = FindMax(root);
            if (maxVal != -1) {
                printf("%d\n", maxVal);
            }
        } else if (ch == 'n') {
            int minVal = FindMin(root);
            if (minVal != -1) {
                printf("%d\n", minVal);
            }
        } else if (ch == 'i') {
            int a = 0;
            Inorder(root, &a);
            if (a != 0) {
                printf("\n");
            }
        } else if (ch == 'p') {
            int a = 0;
            Preorder(root, &a);
            if (a != 0) {
                printf("\n");
            }
        } else if (ch == 't') {
            int a = 0;
            Postorder(root, &a);
            if (a != 0) {
                printf("\n");
            }
        }
    }
    return 0;
}
