#include<stdio.h>
#include<math.h>
gcd(int a,int b){
    if (b==0)return a;
    else return gcd(b,a%b);
}
lcm(int gcd,int prd){
    return prd/gcd;
}
main(){
    int a,b,p;
    printf("Enter number: ");scanf("%d",&a);
    printf("Enter number: ");scanf("%d",&b);
    p=lcm(gcd(a,b),a*b);
    printf("LCM = %d",p);
}
