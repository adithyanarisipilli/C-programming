#include<stdio.h>
int main(){
    char ch[1000];
    gets(ch);
    char given_ch;
    scanf("%c",&given_ch);
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]<=90){
            ch[i]=ch[i]+32;
        }
        if(ch[i]==given_ch||ch[i]==(given_ch+32)){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}