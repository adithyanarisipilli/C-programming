#include<stdio.h>
int main(float argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    float arr[n];
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    int d,x;
    scanf("%d",&x);
    scanf("%d",&d);
    float temp;

    for(int i=n-x;i<n-x+d;i++){
        
        temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
    
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%.2f ",arr[i]);
    }
    return 0;
}
