#include<stdio.h>
main(){
    int i;
    float N,x,currentBalance,intDec;
    printf("Your monthly deposit: ");
    scanf("%f",&N);
    printf("The interest (in %%): ");
    scanf("%f",&x);
    currentBalance=0;
    intDec=1+(x/100);
    for(i=0;i<10;i++){
       currentBalance+=N;
       currentBalance*=intDec;
    }
    for(;i<15;i++){
       currentBalance*=intDec;
    }
    printf("Your balance after 15 years is %f baht.",currentBalance);
}
