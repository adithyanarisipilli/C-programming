#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int ischar(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}
struct Node* ExpressionTree(char* pf) {
    struct Node* stack[1000];
    int top = -1;
    int i = 0;
    while (pf[i] != '\0') {
        if (ischar(pf[i])) {
            struct Node* newNode = createNode(pf[i]);
            stack[++top] = newNode;
        }
        else{
            struct Node* newop = createNode(pf[i]);
            newop->right = stack[top--];
            newop->left = stack[top--];
            stack[++top] = newop;
        }
        i++;
    }
    return stack[0];
}
void inorderTrav(struct Node* head){
    if(head==NULL){
        return ;
    }
    inorderTrav(head->left);
    printf("%c",head->data);
    inorderTrav(head->right);
}
int main(int argc, char const *argv[]) {
    char *arr = (char *)malloc(1000 * sizeof(char));
    char **stack = (char **)malloc(1000 * sizeof(char *));
    int size;
    scanf("%d",&size);
    getchar();
    scanf("%s", arr);
    struct Node* expressionTree = ExpressionTree(arr);
    inorderTrav(expressionTree);
    return 0;
}