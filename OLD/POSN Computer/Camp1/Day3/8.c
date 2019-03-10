#include<stdio.h>
main(){
int i,j,n;
    scanf("%d",&n);
    if (n<0||n>4)printf("Error");
    else{
        for(i=1;i<=n;i++){
            for(j=1;j<=4;j++){
                if(j>=5-i)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
}
