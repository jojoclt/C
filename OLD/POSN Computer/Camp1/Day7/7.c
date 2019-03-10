#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int m,d;
    while(1){
        printf("Month: ");
        scanf("%d",&m);
        if(m<1||m>12)printf("Invalid, try again\n");
        else break;
    }
    while(1){
        printf("Day of the 1st (1=Sunday, 2=Monday and so on): ");
        scanf("%d",&d);
        if(d<1||d>7)printf("Invalid, try again\n");
        else break;
    }
    if(m==1||m==10)
        d+=6;
    else if(m==2||m==3||m==11)
        d+=3;
    else if(m==4||m==7)
        d+=0;
    else if(m==5)
        d+=5;
    else if(m==8)
        d+=4;
    else if(m==7||m==9)
        d+=1;
    else if(m==6||m==12)
        d+=2;
    d%=7;
    if(d==0)d=7;
    printf("%d",d);
}

