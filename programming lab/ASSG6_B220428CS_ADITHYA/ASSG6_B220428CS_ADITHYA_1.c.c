#include<stdio.h>
#include<stdlib.h>
struct stack {
    int top;
    char* array;
};
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    struct stack stk;
    stk.array = (char*)malloc(n * sizeof(char));
    stk.top = 0;
    while (1) {
        char ch;
        scanf("%c", &ch);
        if (ch == 'i') {
            char ch1;
            scanf(" %c", &ch1);
            if (stk.top == n) {
                printf("-1\n");
            }
            else {
                stk.array[stk.top++] = ch1;
            }
        }
        if (ch == 'd') {
            if (stk.top == 0) {
                printf("-1\n");
            }
            else {
                printf("%c\n", stk.array[stk.top - 1]);
                stk.top--;
            }
        }
        if (ch == 't') {
            break;
        }
        if (ch == 'p') {
            if (stk.top == 0) {
                printf("-1\n");
            }
            else {
                printf("%c\n", stk.array[stk.top - 1]);
            }
        }
    }
    return 0;
}
