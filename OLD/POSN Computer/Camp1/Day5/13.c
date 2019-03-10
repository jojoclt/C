#include<stdio.h>
#include<stdlib.h>

main(){
    int n,i,j,k=0;
    printf("Size of matrix (n x n): ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter matrix A(n x n): \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                if (a[i][j]==1)k++;
            }
            else if (a[i][j]==0)k++;
        }
    }
    if (k==n*n)printf("This is an identity matrix");
    else printf("This isn't an identity matrix");
}
