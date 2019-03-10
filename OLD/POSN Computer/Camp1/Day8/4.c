#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
int n, *p;
long fact(int n){
    if (n==1) return n;
    else return n*=fact(n-1);
}
main(){
    while(1){
        printf("Enter n (n<20): ");
        scanf("%d",&n);
        if (n>=20||n<=0)printf("Invalid number. Try again.");
        else break;
    }
    p=&n;
    printf("n!=%ld",fact(*p));
}

