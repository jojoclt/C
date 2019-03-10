#include<stdio.h>
main(){
    int i,j,n;
    char c;
    c='A'-1;
    scanf("%d",&n);
    if (n<0||n>200)printf("Error");
    else {
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                c++;
                printf("%c",c);
            if(c>=90)c-=26;
            }
            printf("\n");
        }
    }
}
