#include<stdio.h>
#include<stdlib.h>
int ischar(char ch) {
    return (ch == '+' || ch == '-'||ch == '*' || ch == '/'||ch=='%'||ch=='^'||ch=='#');
}
int prior(char ch) {
    if (ch == '+' || ch == '-')
        return 9;
    else if (ch == '*' || ch == '/')
        return 7;
    else if(ch=='%' || ch=='#')
        return 10;
    else if(ch=='^')
    	return 6;
}
int main(int argc, char const *argv[])
{  
    char infix[1000];
    fgets(infix, 1000, stdin);
    char* stack=(char*)malloc(1000*sizeof(char));
    char* ans=(char*)malloc(1000*sizeof(char));
    int j=0;
    int top=-1;
    for(int i = 0; infix[i] != '\n'; i++){
        if(infix[i]==' '){
           continue;
       }
       else if(!ischar(infix[i])){ 
            ans[j]=infix[i];
            j++;
       } 
       else{
            if(top==-1){
                stack[++top]=infix[i];
            }
            else if(infix[i]=='('){
                 stack[++top]=infix[i];
            }
            else if(infix[i]==')'){
                while(stack[top]!='('){
                    ans[j]=stack[top];
                    j++;top--;
                }
                top--;
            }
            else if(prior(stack[top])<prior(infix[i])){
                stack[++top]=infix[i];
            }
            else{
                while(prior(stack[top])>=prior(infix[i])){
                    ans[j]=stack[top];
                    j++;top--;
                }
                stack[++top]=infix[i];
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
    return 0;
}

