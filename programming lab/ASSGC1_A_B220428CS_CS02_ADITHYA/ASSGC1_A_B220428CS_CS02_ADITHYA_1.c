#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isoper(char ch) {
    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '^');
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char arr[n];
    scanf("%s", arr);
    char stack[10000];
    int top = -1;
    int dup = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] != ')') {
            stack[++top] = arr[i];
        }
        else {
            int count = 0;
            while (stack[top] != '(') {
                if (isoper(stack[top])) {
                    count++;
                }
                top--;
            }
            top--;
            if (count == 0) {
                dup = 1;
                break;
            }
        }
    }
    printf("%d", dup);
    return 0;
}
