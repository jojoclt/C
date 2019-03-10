#include<stdio.h>
#include<math.h>
gcd(int a,int b){
    if (b==0)return a;
    else return gcd(b,a%b);
}
main(){
    int a,b,p;
    printf("Enter number: ");scanf("%d",&a);
    printf("Enter number: ");scanf("%d",&b);
    p=gcd(a,b);
    printf("GCD = %d",p);
}
