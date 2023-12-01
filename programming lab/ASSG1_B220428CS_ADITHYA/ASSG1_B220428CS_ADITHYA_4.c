#include<stdio.h>

int main(){
    char ch[1000];
    int arr[52]={0};
    scanf("%s",&ch);
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]<=90){
            arr[ch[i]-65]+=(i+1);
        }
        if(ch[i]>=97){
            arr[ch[i]-71]+=(i+1);
        }
    }
    int maxi=0;
    char req;
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]<=90&&arr[ch[i]-65]>maxi){
                maxi=arr[ch[i]-65];
                req=ch[i];
        }
        if(ch[i]>=97&&arr[ch[i]-71]>maxi){
                maxi=arr[ch[i]-71];
                req=ch[i];
        }
    }
    printf("%c",req);
    return 0;
}