#include<stdio.h>
main(){
    int n,n1,n2,i,j,k;
    printf("N = ");scanf("%d",&n);
    printf("n1 = ");scanf("%d",&n1);
    printf("n2 = ");scanf("%d",&n2);
    j=n1;
    for (i=1;i<n;i++){
        j=j%n2;
        for(k=1;k<n1;k++){
            if(j==k)j=n1+k-1;
        }
            if (j==0)j=n2;
        printf("%d,",j);
        j++;
    }
    printf("%d",j);
}
