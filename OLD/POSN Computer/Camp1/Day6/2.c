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
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++)printf(" ");
        for(j=0;j<i+1;j++){
            printf(" %lld",fact(i)/(fact(i-j)*fact(j)));
        }
        printf("\n");
    }
    return 0;
}
