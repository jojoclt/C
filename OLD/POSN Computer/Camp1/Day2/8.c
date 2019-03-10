#include<stdio.h>
#include<math.h>
main(){
    int a,b,c;
    double x1,x2;
    printf("In ax^2+bx+c=0, enter a, b, c:");
    scanf("%d%d%d",&a,&b,&c);
    x1=(-b+sqrt(b*b-4*a*c))/2*a;
    x2=(-b-sqrt(b*b-4*a*c))/2*a;
    if(x1!=x2)printf("x1=%lf, x2=%lf",x1,x2);
    else printf("x=%lf",x1);
    }

