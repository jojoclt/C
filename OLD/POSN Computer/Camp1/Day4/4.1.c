#include<stdio.h>
#include<math.h>
/*Celsius to Fahrenheit*/
float x;
float celc(float x){
    x=x*5/9-32;
    return x;
}
main(){
    scanf("%f",&x);
    x=celc(x);
    printf("%f",x);
}
