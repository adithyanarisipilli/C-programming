#include<stdio.h>
void countsort(int arr[],int n,int place){
    int count[10]={0};
    for(int i=0;i<n;i++)count[(arr[i]/place)%10]++;
    for(int i=1;i<10;i++)count[i]=count[i]+count[i-1];
    int rel[n];
    for(int i=n-1;i>=0;i--){
        rel[count[(arr[i]/place)%10]-1]=arr[i];
        count[(arr[i]/place)%10]--;
    }
    for(int i=0;i<n;i++)arr[i]=rel[i];
}
void radixsort(int arr[],int n){
    
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        if(maxi<arr[i])maxi=arr[i];
    }
    for(int place=1;maxi/place>0;place*=10){
        countsort(arr,n,place);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i]);
    }
    radixsort(arr,n);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}
