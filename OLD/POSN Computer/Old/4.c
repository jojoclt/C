#include<stdio.h>
#include<math.h>

main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<2*(n-1);i++){
        for(j=0;j<2*n;j++){
            if(j==0||j==2*n-1)
                printf("|");
            else if(j==i+1)
                printf("\\");
            else if(j==2*n-2-i)
                    printf("/");
            else printf(" ");
        }
        printf("\n");
    }
}
