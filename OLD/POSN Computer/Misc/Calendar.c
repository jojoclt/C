#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int m,d,n,e,i;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(1){
        printf("Initial Month: ");
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
    while(1){
        printf("Final Month: ");
        scanf("%d",&n);
        if(n<1||n>12)printf("Invalid, try again\n");
        else break;
    }
    while(1){
        printf("Date of Final Month: ");
        scanf("%d",&e);
        if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(e<1||e>31))printf("Invalid, try again\n");
        else if((m==4||m==6||m==9||m==11)&&(e<1||e>30))printf("Invalid, try again\n");
        else if((m==2)&&(e<1||e>28))printf("Invalid, try again\n");
        else break;
    }
    if(m<=n){
        for(i=m-1;i<n-1;i++){
            d+=a[i];
        }
    }
    else{
        for(i=0;i<n-1;i++){
            d+=a[i];
        }
        for(i=m-1;i<11;i++){
            d+=a[i];
        }
    }
    d+=e-1;
    printf("%d\n",d);
    d%=7;
    if(d==0)d=7;
    printf("%d",d);
}

