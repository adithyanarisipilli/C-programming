#include<stdio.h>

int print_recur(int n,int i){
    if(n==i){
        printf("%d ",n);
        return 0;
    }
    printf("%d ",i);
    return print_recur(n,i+1);

}
int main(){
    int n,i=1;
    scanf("%d",&n);
    int arr[n];
    print_recur(n,i);
    
}