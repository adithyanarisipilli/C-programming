#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isnum(char ch) {
    return ch >= '0' && ch <= '9';
}
int main(int argc, char const *argv[]) {
    char *arr = (char *)malloc(1000 * sizeof(char));
    char **stack = (char **)malloc(1000 * sizeof(char *));
    scanf("%s", arr);
    int n = strlen(arr);
    int top = -1;
    char *ans = NULL;

    for (int i = 0; i < n; i++) {
        if (isnum(arr[i])) {
            char *num = (char *)malloc(2 * sizeof(char));
            num[0] = arr[i];
            num[1] = '\0';
            stack[++top] = num;
        } else {
            char *a = stack[top];
            top--;
            char *b = stack[top];
            top--;
            ans = (char *)malloc((strlen(a) + strlen(b) + 4) * sizeof(char)); 
            strcpy(ans, "(");
            strcat(ans, b);
            int k = strlen(ans);
            ans[k] = arr[i];
            ans[k + 1] = '\0';
            strcat(ans, a);
            strcat(ans, ")");
            stack[++top] = ans;
            free(a);
            free(b);
        }
    }
    int ansLength = strlen(ans);
    if (ansLength >= 2 && ans[0] == '(' && ans[ansLength - 1] == ')') {
        ans[ansLength - 1] = '\0'; 
        ans++;
    }
    printf("%s", ans);
    return 0;
}