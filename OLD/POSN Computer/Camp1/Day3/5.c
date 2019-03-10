#include<stdio.h>
main(){
    int n,x=500;
    n=0;
    while(1){
        x*=1.03;
        if (x>20000)break;
        n++;
    }
    printf("%d years",n);
}
