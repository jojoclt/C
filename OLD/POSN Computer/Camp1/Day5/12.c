#include<stdio.h>
#include<stdlib.h>

main(){
    int a[2][2],b[2][2],i,j;
    printf("Enter matrix A(2x2): \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter matrix B(2x2): \n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                scanf("%d",&b[i][j]);
            }
        }
    printf("Matrix A+B: \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }

}
