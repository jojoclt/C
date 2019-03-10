#include<stdio.h>
#include<conio.h>
#include<math.h>

main(){
    int ha, hb, wa, wb,i,j,k;
    while(1){
        printf("Matrix A x B\nHeight A: ");scanf("%d",&ha);
        printf("Width A: ");scanf("%d",&wa);
        printf("Height B: ");scanf("%d",&hb);
        printf("Width B: ");scanf("%d",&wb);
        if (ha!=wb)printf("Width A is not equal to . Try again\n");
        else break;
    }
    int a[ha][wa], b[hb][wb],c[hb][wa];
    printf("Matrix A:\n");
    for(i=0;i<ha;i++){
        for(j=0;j<wa;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix B:\n");
    for(i=0;i<hb;i++){
        for(j=0;j<wb;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<hb;i++){
        for(j=0;j<wa;j++){
            c[i][j]=0;
        }
    }
    for(i=0;i<hb;i++){
        for(j=0;j<wa;j++){
            for(k=0;k<wb;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

