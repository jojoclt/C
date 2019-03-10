#include<stdio.h>
main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++){
            for(j=1;j<=2*n-1;j++){
                if(j>=n+i||j<=n-i||j>=3*n-i||j<=i-n)printf(" ");
                else if ((i+j)%2==0)printf("*");
                else printf("-");
            }
            printf("\n");
        }
}
