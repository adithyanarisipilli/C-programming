#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int low=0,high=n-1,mid,ans=-1;
    while(low<=high){
        mid=low+high>>1;
        if(arr[mid]==k){
            ans=mid;
            break;
        }
        if(arr[low]<arr[mid]){
            if(arr[low]<=k&&k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k&&k<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    printf("%d",ans);
    return 1;
}