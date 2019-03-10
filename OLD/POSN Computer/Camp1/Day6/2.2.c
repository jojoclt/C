#include<stdio.h>
long long fact(long long a){
    long long i,x=1;
    for (i=1;i<=a;i++){
        x*=i;
    }
    return x;
}
main(){
    long long i,j,n;
    scanf("%lld",&n);
    for(i=n;i>=0;i--){
        for(j=n-i-1;j>0;j--)printf(" ");
        for(j=i;j>=0;j--){
            printf(" %lld",fact(i)/(fact(i-j)*fact(j)));
        }
        printf("\n");
    }
    return 0;
}
