#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int fib(int n){
    if(n==1||n==0)return n;
    else return fib(n-1)+fib(n-2);
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Month%d=%d\n",i,fib(i));
    }
}

