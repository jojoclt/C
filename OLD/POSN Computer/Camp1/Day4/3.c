#include<stdio.h>
float a,b,c=3.14159265359;
void cone(){
    printf("Radius: ");scanf("%f",&a);
    printf("Slant Height: ");scanf("%f",&b);
    printf("S.Area = %f\n",(a+b)*c*a);
}
void prism(float a, float b){
    c=2*a*a+4*a*b;
    printf("S.Area = %f\n",c);
}
float pyra(float a, float b){
    return a*a+2*a*b;
}
main(){
    while (1){
        printf("1.Cone\n2.Square Prism\n3.Square Pyramid\nPlease select a shape to calculate its surface area: ");
        scanf("%f",&a);
        if (a==1) cone();
        else if (a==2) {
            printf("Side of Square: ");scanf("%f",&a);
            printf("Height: ");scanf("%f",&b);
            prism(a,b);
        }
        else if (a==3) {
            printf("Side of Square: ");scanf("%f",&a);
            printf("Slant Height: ");scanf("%f",&b);
            c=pyra(a,b);
            printf("S.Area = %f\n",c);
        }
        else if (a==0) break;
        else continue;
    }
}
