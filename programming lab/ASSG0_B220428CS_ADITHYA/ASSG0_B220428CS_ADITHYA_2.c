#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
        if(maxi<arr[i]){
            maxi=arr[i];
        }
    }
    printf("%d",maxi);
    return 0;
}