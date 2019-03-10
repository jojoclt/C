#include<stdio.h>
int fact(int a){
    int i,x=1;
    for (i=1;i<=a;i++){
        x*=i;
    }
    return x;
}
main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for (j=0;j<n-i;j++)printf(" ");
        for(j=0;j<i+1;j++){
            printf("%d ",fact(i)/(fact(i-j)*fact(j)));
        }
        printf("\n");
    }
    return 0;
}
