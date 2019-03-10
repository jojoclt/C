#include<stdio.h>
#include<conio.h>

main(){
    int x,y,m,z=20;
    int sum=0;
    for(y=0;y<6;y++){
        for(x=0;x<=5;x++){
            m=z-y;
            m%=10;
            sum+=m;
        }
        sum+=1;
    }
    printf(" %d\n",sum);
    return 0;
}
