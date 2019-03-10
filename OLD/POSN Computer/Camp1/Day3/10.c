#include<stdio.h>
main(){
    int i,j,n;
    scanf("%d",&n);
    if (n<0||n>26)printf("Error");
    else {
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                printf("%c",'A'+j-1);
            }
            printf("\n");
        }
    }
}
