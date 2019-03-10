#include<stdio.h>
#include<conio.h>
#include<math.h>
int t(int a){
    a%=3;

return a;
}
main(){
    int i,j,m[3][3],d[3][2],det=0;
    printf("Enter a matrix (3 x 3): \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            scanf("%d",&m[i][j]);
    }for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d",m[i][j]);
        }
            printf("\n");
    }
    for(i=0;i<3;i++){
            int a,b,c;
            a=t(i);b=t(i+1);c=t(i+2);
            d[i][1]=(m[a][0])*(m[b][1])*(m[c][2]);

            d[i][2]=(m[c][0])*(m[b][1])*(m[a][2]);

            det+=d[i][1];
            det-=d[i][2];
    }
    printf("det = %d",det);
}

