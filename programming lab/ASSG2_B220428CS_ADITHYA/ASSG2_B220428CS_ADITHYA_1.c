#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int low=0,high=n-1;
    int mis_nums,mid;
    while(low<=high){
        mid=low+high>>1;
        mis_nums=arr[mid]-(mid+1);
        
        if(mis_nums<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(low+k>arr[n-1]){
        printf("-1");
        return 1;
    }
    printf("%d",low+k);
    return 1;
}