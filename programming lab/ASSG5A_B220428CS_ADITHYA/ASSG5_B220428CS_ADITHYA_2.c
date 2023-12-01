#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int larindex=i;
    if(arr[left]>arr[larindex]&&left<n){
        larindex=left;
    }
    if(arr[right]>arr[larindex]&&right<n){
        larindex=right;
    }
    if(larindex!=i){
       swap(&arr[larindex],&arr[i]);
       heapify(arr,larindex,n);
    }
}
void heapsort(int arr[],int n){
    int target=n/2-1;
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,0,i);
    }

}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
