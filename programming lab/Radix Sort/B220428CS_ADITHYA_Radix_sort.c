// Online C compiler to run C program online
#include <stdio.h>
void countsort(int arr[],int n,int mul){
    int temp[10];
    for(int i=0;i<10;i++) temp[i]=0;
    for(int i=0;i<n;i++){
        temp[(arr[i]/mul)%10]++;
    }
    for(int i=1;i<10;i++)temp[i]=temp[i]+temp[i-1];
    int cngarr[n];
    for(int i=n-1;i>=0;i--){
        cngarr[temp[(arr[i]/mul)%10]-1]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=cngarr[i];
    }
}
void radixsort(int arr[],int n){
    int maxi=arr[0];
    for(int i=1;i<n;i++){
        if(maxi<arr[i]){
            maxi=arr[i];
        }
    }
    for(int i=1;(maxi/i)>0;i*=10)
    countsort(arr,n,i);
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
