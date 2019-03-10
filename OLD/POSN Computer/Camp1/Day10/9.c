#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    int n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("|");
        for(k=0;k<n-i-1;k++)printf(" ");
        for(k=0;k<2*i+1;k++)printf("*");
        for(k=0;k<n-i-1;k++)printf(" ");
        printf("|");
        printf("\n");
    }
}

