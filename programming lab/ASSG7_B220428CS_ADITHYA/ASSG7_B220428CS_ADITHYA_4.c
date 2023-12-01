#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
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
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int prior(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void intoPost(char* infix, char* pf) {
    char stack[1000];
    int top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                pf[j++] = infix[i++];
            }
            pf[j++] = ' ';
            i--;
        } else if (isOperator(infix[i])) {
            while (top >= 0 && prior(stack[top]) >= prior(infix[i])) {
                pf[j++] = stack[top--];
                pf[j++] = ' ';
            }
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                pf[j++] = stack[top--];
                pf[j++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        }
    }

    while (top >= 0) {
        pf[j++] = stack[top--];
        pf[j++] = ' ';
    }

    pf[j] = '\0';
}

double evalpost(char* pf) {
    double stack[1000];
    int top = -1;
    for (int i = 0; pf[i] != '\0'; i++) {
        if (isdigit(pf[i])) {
            double operand = 0;
            while (isdigit(pf[i])) {
                operand = operand * 10 + (pf[i] - '0');
                i++;
            }
            stack[++top] = operand;
        } else if (pf[i] != ' ') {
            double num2 = stack[top--];
            double num1 = stack[top--];
            if (pf[i] == '+')
                stack[++top] = num1 + num2;
            else if (pf[i] == '-')
                stack[++top] = num1 - num2;
            else if (pf[i] == '*')
                stack[++top] = num1 * num2;
            else if (pf[i] == '/') {
                if (num2 == 0) {
                    return INT_MAX;
                }
                stack[++top] = num1 / num2;
            }
        }
    }
    return stack[top];
}
struct Node* ExpressionTree(char* pf) {
    struct Node* stack[1000];
    int top = -1;
    int i = 0;
    while (pf[i] != '\0') {

        if (isdigit(pf[i])) {
            int val = 0;
            while (pf[i] != ' ') {
                val = val * 10 + (pf[i] - '0');
                i++;
            }
            struct Node* newNode = createNode(val);
            stack[++top] = newNode;
        }
        else if (pf[i] == ' ') {
            i++;
        }
        else if (isOperator(pf[i])) {
            struct Node* newop = createNode(pf[i]);
            newop->right = stack[top--];
            newop->left = stack[top--];
            stack[++top] = newop;
            i++;
        }

    }

    return stack[0];
}
int Height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int MinLength(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftLength = MinLength(root->left);
    int rightLength = MinLength(root->right);
    return (leftLength < rightLength ? leftLength : rightLength) + 1;
}
int main() {
    char infix[1000];
    fgets(infix, 1000, stdin);
    char pf[1000];
    intoPost(infix, pf);
    printf("%s\n", pf);
    double result = evalpost(pf);
    if (result == INT_MAX) {
        printf("N\n");
    }
    else {
        printf("%.2lf\n", result);
    }
    struct Node* expressionTree = ExpressionTree(pf);
    int height = Height(expressionTree);
    int minLength = MinLength(expressionTree);
    printf("%d\n", height - 1);
    printf("%d\n", minLength - 1);
    return 0;
}