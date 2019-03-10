#include<stdio.h>
main(){
    int n,n1,i,j=1;
    printf("N = ");scanf("%d",&n);
    printf("n1 = ");scanf("%d",&n1);
    for (i=1;i<n;i++){
        j=j%n1;
        if (j==0)j=n1;
        printf("%d,",j);
        j++;
    }
    printf("%d",j);
}
