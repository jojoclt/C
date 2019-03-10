#include<stdio.h>
#include<stdlib.h>

main(){
int i,j,n,sum=0;
scanf("%d",&n);
for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        printf("%d",j);
        sum+=j;
    }
    printf("\n");
}
    sum=sum-n*(n+1)+2;
    if(n>3)printf("%d",sum);
    else printf("No Answer");
}
