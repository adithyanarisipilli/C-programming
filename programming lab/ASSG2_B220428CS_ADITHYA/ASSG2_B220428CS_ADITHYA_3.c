#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0,high=n-1,mid,ans;
    while(low<=high){
        mid=low+high>>1;
        if(mid==0||mid==n-1){
            ans=arr[mid];
            break;
        }
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
            ans=arr[mid];
            break;
        }
        else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    printf("%d",ans);
    return 1;
}