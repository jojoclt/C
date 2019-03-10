#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int n,i,j,k;
    char c='A';
    scanf("%d",&n);
    if(n==1)printf("A");
    for(i=0;i<n;i++){
            if(i%2==0){
                c+=i;
                if(c>'Z')c-=26;
            }
        for(j=0;j<2*(n-1);j++){
            if(i%2==0){

                if(j==n){
                    printf("%c ",c);
                    c+=i+1;
                    if (c>'Z')c-=26;
                }
                else if(j>=n-i&&j<n){
                    printf("%c ",c);
                    c--;
                    if (c<'A')c+=26;
                }
                else printf("  ",c);
            }
            if(i%2!=0){
                if(j>=n&&j<=n+i){
                    printf("%c ",c);
                    c++;
                    if (c>'Z')c-=26;
                }
                else printf("  ");
            }
        }
        printf("\n");
    }

}

