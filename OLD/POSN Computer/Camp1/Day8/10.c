#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
int a[4]={1,2,4,0};
int b[3]={7,9,5};
int *x,*y,i,s,t=0,sa,sb;
sa=sizeof(a);sb=sizeof(b);
int arP(int a[10], int b[10],int sa,int sb){
    x=a+(sa/sizeof(int))-1;
    y=b+(sb/sizeof(int))-1;
    if(sa>=sb)s=(sa/sizeof(int));
    else s=(sb/sizeof(int));
    for(i=0;i<s;i++){
        printf("%d %d\n",*x,*y);
        t+=(*x+*y)*pow(10,i);
        x--;y--;

    }
    return t;
}
main(){
    printf("%d",arP(a,b,sa,sb));
}

