#include<stdio.h>
#include<stdbool.h>
bool isPossible(int mid,int arr[],int n,int m){
    int time_sum=0,count=1;
    for(int i=0;i<m;i++){
        time_sum+=arr[i];
        if(time_sum<=mid){
            continue;
        }
        else{
            count++;
            time_sum=arr[i];
            if(count>n||arr[i]>mid){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int arr[m];
    int sum_time=0;
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
        sum_time+=arr[i];
    }
    int low=0,high=sum_time,mid,ans;
    while(low<=high){
       mid=low+high>>1;
       if(isPossible(mid,arr,n,m)){
          ans=mid;
          high=mid-1;
       } 
       else{
          low=mid+1;
       }
    }
    printf("%d",ans);
    return 1;
}