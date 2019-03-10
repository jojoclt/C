#include<stdio.h>
#include<math.h>
calcDays(int a,int b){
    if (b==1)b=0;
    else if (b==2)b=31;
    else if (b==3)b=59;
    else if (b==4)b=90;
    else if (b==5)b=120;
    else if (b==6)b=151;
    else if (b==7)b=181;
    else if (b==8)b=212;
    else if (b==9)b=243;
    else if (b==10)b=273;
    else if (b==11)b=304;
    else if (b==12)b=334;
    return a+b;
}
main(){
    int a,b,c,d,x,y,z;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    x=calcDays(a,b);
    y=calcDays(c,d);
    z=y-x+1;
    if (z<0)z+=365;
    printf("%d",z);
}
