#include<stdio.h>
void sort(float arr[]){
    float temp;
    for(int i=1;arr[i]!=0;i++){
        temp=arr[i];
        int j=i-1;
        while(temp<arr[j]&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    float arr[n];
    for(int i=0;i<n;i++){
        scanf(" %f",&arr[i]);
    }
    float bucket[10][10]={0};
    int j=0;
    for(int i=0;i<n;i++){
        if(bucket[(int)(arr[i]*10)][j]==0){
           bucket[(int)(arr[i]*10)][j]=arr[i];
           j=0;
        }
        else{
            j++;i--;
        }
    }
    for(int i=0;i<10;i++){
        sort(bucket[i]);
    }
    int k=0;
    for(int i=0;i<10;){
        if(bucket[i][k]==0){
            i++;
            k=0;
        }
        else{
            printf("%.2f ",bucket[i][k]);
            k++;
        }
    }
    return 0;
}
