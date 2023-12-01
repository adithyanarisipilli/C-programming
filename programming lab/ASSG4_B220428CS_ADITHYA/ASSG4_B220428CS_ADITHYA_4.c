#include<stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void replacemax(int arr[],int i,int n,int* ene){
    int maxi=i;
    for(int j=i;j<n;j++){
        if(arr[maxi]<arr[j])maxi=j;
    }
    if(arr[maxi]!=arr[i]){
        swap(&arr[maxi],&arr[i]);
        (*ene)--;
    }
}
void replacemin(int arr[],int i,int n,int* ene){
    int mini=i;
    for(int j=i;j<n;j++){
        if(arr[mini]>arr[j])mini=j;
    }
    if(arr[mini]!=arr[i]){
        swap(&arr[mini],&arr[i]);
        (*ene)--;
    }
}
int main(int argc, char const *argv[])
{
    int n,ene;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i]);
    }
    scanf("%d",&ene);
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(ene>0){
               replacemin(arr,i,n,&ene); 
            }     
        }
        else{
            if(ene>0){
               replacemax(arr,i,n,&ene);   
            }
        }
        if(ene==0)break;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
