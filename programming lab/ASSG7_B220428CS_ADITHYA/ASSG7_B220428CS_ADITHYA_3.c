#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int evalute(int a,int b,char c){
    if(c=='+'){
        return a+b;
    }
    else if(c=='-'){
        return b-a;
    }
    else if(c=='*'){
        return a*b;
    }
    else if(c=='/'){
        return b/a;
    }
}
int main(int argc, char const *argv[])
{
    int* stack=(int*)malloc(1000*sizeof(int));
    char* arr=(char*)malloc(1000*sizeof(char));
    gets(arr);
    int top=-1;
    int n=strlen(arr);
    int i=0;
    while(i<=n){
        if(arr[i]>='0'&&arr[i]<='9'){
            int val=0;
            while(arr[i]!=' '&&arr[i]!='\0'){
                val=10*val+(arr[i]-'0');
                i++;
            }
            stack[++top]=val;
        }
        else if(arr[i]=='\0'){
            break;
        }
        else if(arr[i]==' '){
            i++;
            continue;
        }
        else{
            if(top==-1||top==0){
                printf("-1");
                return 0;
            }
            int a=stack[top];top--;
            int b=stack[top];top--;
            stack[++top]=evalute(a,b,arr[i]);
        }
        i++;
    }
    if(top!=0){
        printf("-1");
        return 0;
    }
    printf("%d",stack[top]);
    return 0;
}