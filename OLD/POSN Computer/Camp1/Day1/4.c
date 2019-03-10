#include<stdio.h>
#include<conio.h>
main(){
    float r, C, pi;
    pi = 3.1415926;
    printf("Enter radius:");
    scanf("%f", &r);
    C = 2*pi*r;
    printf("Circumference = %f", C);
    getch();
}
