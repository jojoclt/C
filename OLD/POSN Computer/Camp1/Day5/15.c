#include<stdio.h>
#include<stdlib.h>

main(){
int m,n,i,j;
    printf("Rows: ");scanf("%d",&n);
    printf("Columns: ");scanf("%d",&m);
    int a[m][n];
    printf("Enter matrix A: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix 2A: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]*2);
        }
        printf("\n");
    }

}
