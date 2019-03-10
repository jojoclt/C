#include<stdio.h>
#include<conio.h>
main(){
    int i,j,T=5,L;
    for(i=1;i<=T;i++){
        for(j=0;j<T;j++){
            L=(i+j)%T;
            if(L==0) L=5;
            printf("%d",L);
        }
        printf("\n");
    }
    getch();
}
