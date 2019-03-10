#include<stdio.h>
#include<math.h>

main(){
    int b,k,i,j;
    while(1){
        scanf("%d",&b);
        if(b<1||b>5)printf("Error\n");
        else break;
    }
    while(1){
        scanf("%d",&k);
        if(k<1||k>20)printf("Error\n");
        else break;
    }
    for(i=0;i<b+4*k;i++){
        for(j=0;j<b+2*k;j++){
            if(i>=k&&i<b+k){
                printf("*");
            }
            else{
                if(j>=k&&j<b+k){
                    printf("*");
                }
                else printf(" ");
            }
        }
        printf("\n");
    }
}
