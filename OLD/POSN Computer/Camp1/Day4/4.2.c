#include<stdio.h>
#include<math.h>
/*Fahrenheit to Celsius*/
float x;
float fahr(float x){
    x=x*1.8+32;
    return x;
}
main(){
    scanf("%f",&x);
    x=fahr(x);
    printf("%f",x);
}
