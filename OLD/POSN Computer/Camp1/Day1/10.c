#include<stdio.h>
#include<conio.h>
main(){
    int i,T,R;
    T=2;
    for(i=1;i<=12;i++){
        R=i*T;
        printf("%dx%d=%d\n",i,T,R);
    }
    getch();
}
