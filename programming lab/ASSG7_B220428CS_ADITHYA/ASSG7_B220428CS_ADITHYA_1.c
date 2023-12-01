#include<stdio.h>
#include<stdlib.h>
int ischar(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}
int prior(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/'||ch=='%')
        return 2;
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    int size;
    scanf("%d",&size);
    getchar();
    char* arr=(char*)malloc(size*sizeof(char));
    int i;
    for(i=0;i<size;i++){
        scanf(" %c",&arr[i]);
    }
    char* stack=(char*)malloc(size*sizeof(char));
    char* ans=(char*)malloc(size*sizeof(char));
    int j=0;
    int top=-1;
    for(int i=0;i<size;i++){
       if(ischar(arr[i])){ 
            ans[j]=arr[i];
            j++;
       } 
       else{
            if(top==-1){
                stack[++top]=arr[i];
            }
            else if(arr[i]=='('){
                 stack[++top]=arr[i];
            }
            else if(arr[i]==')'){
                while(stack[top]!='('){
                    ans[j]=stack[top];
                    j++;top--;
                }
                top--;
            }
            else if(prior(stack[top])<prior(arr[i])){
                stack[++top]=arr[i];
            }
            else{
                while(prior(stack[top])>=prior(arr[i])){
                    ans[j]=stack[top];
                    j++;top--;
                }
                stack[++top]=arr[i];
            }
       }
    }
    while(top>=0){
        ans[j]=stack[top];
        j++;top--;
    }
    for(int i=0;i<j;i++){
        printf("%c ",ans[i]);
    }
    free(stack);
    free(arr);
    free(ans);
    return 0;
}