#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define m 300000
main(){
    int i,j;
    long long s;
    printf("2");
    for(i=3;i<=m;i++){
        for(j=2;j<i;j++){
            if ((i%j)==0)break;
        }
        if(j==i){printf(" %d",i);s+=i;}
    }
    printf("\n%lld",s);
}

