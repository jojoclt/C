#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void toBase(int d, int b){
        int i,m=0;
    int tmp=d;
    while(1){
        tmp-=pow(b,m);
        if (tmp<0)break;
        else {tmp+=pow(b,m);m++;}
    }
    m--;
    int a[m];
    for(i=0;i<=m;i++)
        a[i]=0;
    for(i=m;i>=0;i--){

        while(1){
            d-=pow(b,i);
            if(d<0){d+=pow(b,i);break;}
            else a[i]++;
        }
        printf("%d",a[i]);
    }
}
int toDec(int d,int b){
    int i,sum,m;
    int tmp=d;
    sum=m=0;
    while(1){
        tmp-=pow(10,m);
        if (tmp<0)break;
        else {tmp+=pow(10,m);m++;}
    }
    m-=1;
    int a[m];
    for(i=0;i<=m;i++)
        a[i]=0;
    for(i=m;i>=0;i--){
        while(1){
            d-=pow(10,i);
            if(d<0){d+=pow(10,i);break;}
            else a[i]++;
        }
        sum+=pow(b,i)*a[i];
    }
    return sum;
}

main(){
    int b,n1,n2,d1,d2;
    while(1){
        printf("The numbers will be base (<10): ");scanf("%d",&b);
        if (b>10)printf("The number is too large. Please try again.\n");
        else break;
    }
    printf("Number 1: ");scanf("%d",&n1);
    printf("Number 2: ");scanf("%d",&n2);
    d1=toDec(n1,b);d2=toDec(n2,b);
    toBase(d1+d2,b);

}
