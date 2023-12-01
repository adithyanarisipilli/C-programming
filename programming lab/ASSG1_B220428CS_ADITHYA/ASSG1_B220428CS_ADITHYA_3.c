#include<stdio.h>

double factorial(double n){
    double fact=1;
    for(double i=2;i<=n;i++){
        fact*=i;
    }
    return fact;
}
void main(){
    double n,x;
    scanf("%lf %lf",&x,&n);
    x=(x*(3.1415)/180);
    double sinx=0;
    double b=1;
    double a=x;
    for(double i=1;i<=(n+1)/2;i++){
        sinx+=(a/factorial(b));
        b+=2;
        a*=-(x*x);
    }
    printf("%.4lf",sinx);
    return 0;
}