#include<stdio.h>
#include<math.h>

main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            if(i<n){
                if(j==i||j==2*n-2-i)
                    printf("%d",i+1);
                else printf(" ");
            }
            else{
                if(j==i||j==2*n-2-i)
                    printf("%d",2*n-1-i);
                else printf(" ");
            }
        }
        printf("\n");
    }
}
