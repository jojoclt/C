#include<stdio.h>
#include<stdlib.h>

main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(k=0;k<i-1;k++)
            printf(" ");
        printf("%d",i);
        for(k=0;k<(n-1)*2-1-2*(i-1);k++)
            printf(" ");
        if(i!=n)printf("%d",i);
        printf("\n");
    }
    for(i=n-1;i>0;i--){
        for(k=0;k<i-1;k++)
            printf(" ");
        printf("%d",i);
        for(k=0;k<(n-1)*2-1-2*(i-1);k++)
            printf(" ");
        if(i!=n)printf("%d",i);
        printf("\n");
    }


}
