#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int left=low,right=mid+1;
    int temp[high-low+1];
    int i=0;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp[i]=arr[left];i++;left++;
        }
        else{
            temp[i]=arr[right];i++;right++;
        }
    }
    while(left<=mid){
        temp[i]=arr[left];i++;left++;
    }
    while(right<=high){
        temp[i]=arr[right];i++;right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    if(low>=high)return ;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
