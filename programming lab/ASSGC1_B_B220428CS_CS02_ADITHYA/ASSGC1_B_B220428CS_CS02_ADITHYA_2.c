#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* Create_Node(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int isDigit(char ch) {
    int a = ch - '0';
    return (a >= 0 && a <= 9);
}

void print_levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    int k = 0;
    int front = 0;
    struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    queue[k] = root;
    k++;
    while (1) {
        int size = k - front;
        if (size == 0) {
            break;
        }
        int* arr = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front];
            arr[i] = temp->data;
            front++;
            if (temp->left != NULL) {
                queue[k++] = temp->left;
            }
            if (temp->right != NULL) {
                queue[k++] = temp->right;
            }
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        free(arr);
    }
    free(queue);
}
int find_index(char ch[], int start, int end) {
    if (start > end) {
        return -1;
    }
    char stack[100];
    int top = -1;
    for (int i = start; i <= end; i++) {
        if (ch[i] == '(') {
            stack[++top] = ch[i];
        }
        else if (ch[i] == ')') {
            if (stack[top] == '(') {
                top--;
                if (top == -1) {
                    return i;
                }
            }
        }
    }
    return -1;
}
struct Node* Construct_Tree(char ch[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int num = 0;
    while (start <= end && ch[start] >= '0' && ch[start] <= '9') {
        num *= 10;
        num += (ch[start] - '0');
        start++;
    }
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root = Create_Node(num);
    int index = -1;
    if (start <= end && ch[start] == '(') {
        index = find_index(ch, start, end);
    }
    if (index != -1) {
        root->left = Construct_Tree(ch, start + 1, index - 1);
        root->right = Construct_Tree(ch, index + 2, end - 1);
    }
    return root;
}
void print_rightView(struct Node* root, int arr[], int level, int* size) {
    if (root == NULL) {
        return ;
    }
    if (level == *size) {
        arr[level] = root->data;
        (*size)++;
    }
    print_rightView(root->right, arr, level + 1, size);
    print_rightView(root->left, arr, level + 1, size);
}
bool validate(struct Node* root, int mini, int maxi) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= mini || root->data >= maxi) {
        return false;
    }
    return validate(root->left, mini, root->data) && validate(root->right, root->data, maxi);
}
int mx = 0;
int maxiBST(struct Node* root, int* mx) {
    if (root == NULL) {
        return 0;
    }
    int l = maxiBST(root->left, mx);
    int r = maxiBST(root->right, mx);
    if (validate(root, INT_MIN, INT_MAX)) {
        if (l + r + root->data > *mx) {
            *mx = l + r + root->data;
        }
        return l + r + root->data;
    }
    else {
        return 0;
    }


}
int main(int argc, char const* argv[]) {
    char ch[1000];
    scanf("%s", ch);
    struct Node* root = Construct_Tree(ch, 0, strlen(ch) - 1);
    for (int i = 0; i < 3; i++) {
        char op;
        getchar();
        scanf("%c", &op);
        if (op == 'l') {
            print_levelOrder(root);
            printf("\n");
        }
        else if (op == 'r') {
            int arr[1000];
            int size = 0;
            print_rightView(root, arr, 0, &size);
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (op == 'm') {
            //maximum sum BST
            int mx = 0;
            int ans = maxiBST(root, &mx);
            printf("%d\n", mx);
        }
    }
    return 0;
}
