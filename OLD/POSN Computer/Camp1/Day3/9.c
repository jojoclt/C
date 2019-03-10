#include<stdio.h>
main(){
    int i,j,n;
    scanf("%d",&n);
    if (n<0||n>24)printf("Error");
    else {
        for(i=1;i<=n;i++){
            for(j=1;j<=2*n;j++){
                if (j<=i||j>=2*n-i+1)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        for(;i<=2*n;i++){
            for(j=1;j<=2*n;j++){
                if(j<=2*n-i||j>i)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
}

