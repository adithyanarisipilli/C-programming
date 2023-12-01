#include<stdio.h>
void swap(char* a,char* b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
int partition(char arr[],int low,int high){
    int i=low,j=high;
    char pivot=arr[low];
    while(i<j){
        while(arr[i]>=pivot&&i<high){
            i++;
        }
        while(arr[j]<pivot&&j>low){
            j--;
        }
        if(i<j)swap(&arr[i],&arr[j]);
    }
    
    swap(&arr[low],&arr[j]);
    return j;
}
void qs(char arr[],int low,int high){
    if(low>=high)return;
    int pindex=partition(arr,low,high);
    qs(arr,low,pindex-1);
    qs(arr,pindex+1,high);
}
int main(){
    int n;
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    qs(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%c ",arr[i]);
    }
}