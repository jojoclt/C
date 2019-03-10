#include<stdio.h>
#include<math.h>

main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            if(i==n-1){
                if(j==i)printf("X");
                else printf(" ");
            }
            else {
                if(j==i)
                    printf("\\");
                else if(j==2*n-2-i)
                    printf("/");
                else printf(" ");
            }
        }
        printf("\n");
    }
}
