#include<stdio.h>
void addTime(int h, int m, int p){
    int n=0;
    m+=p;
    while(1){
        m-=60;
        if (m<0){m+=60;break;}
        n++;
    }
    h+=n;
    h%=24;
    if(h<10)printf("0");printf("%d ",h);
    if(m<10)printf("0");printf("%d",m);
}
main(){
    int h,m,p;
    printf("The time (hour and minutes): ");scanf("%d%d",&h,&m);
    printf("Time from now (minutes): ");scanf("%d",&p);
    addTime(h,m,p);
}
