#include<stdio.h>
float a,b,pi=3.14159265359;
void circ(){
    printf("Enter the radius: ");
    scanf("%f",&a);
    printf("Area = %.3f",a*a*pi);
}
void tri(){
    printf("Enter the base: ");
    scanf("%f",&b);
    printf("Enter the height: ");
    scanf("%f",&a);
    printf("Area = %.3f",a*b*0.5);
}
void rect(){
    printf("Enter the width: ");
    scanf("%f",&b);
    printf("Enter the height: ");
    scanf("%f",&a);
    printf("Area = %.3f",a*b);
}
main(){
    printf("1.Circle\n2.Triangle\n3.Rectangle\nPlease select a shape to calculate its area: ");
    scanf("%f",&a);
    if (a==1) circ();
    else if (a==2) tri();
    else if (a==3) rect();
    else printf("Error");
}
