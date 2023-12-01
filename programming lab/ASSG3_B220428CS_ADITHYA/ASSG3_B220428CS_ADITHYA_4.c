#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(int argc, char const *argv[])
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max;
    for(int i=0;i<n;i++){
         max=i;
        for(int j=i;j<n;j++){
            if(arr[max]<arr[j]){
                max=j;
            }
        }
        swap(&arr[i],&arr[max]);
    }
    for(int i=0;i<k;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
