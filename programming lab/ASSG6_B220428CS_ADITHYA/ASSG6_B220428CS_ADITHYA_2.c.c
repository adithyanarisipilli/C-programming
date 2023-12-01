#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int temp[n];
    int stack[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int top=0;
    for(int i=n-1;i>=0;i--){
        while(top!=0&&arr[i]>=stack[top-1]){
            top--;
        }
        if(top==0){
            temp[i]=-1;
        }
        else{
            temp[i]=stack[top-1];
        }
        stack[top]=arr[i];
        top++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",temp[i]);
    }
    
    return 0;
}
