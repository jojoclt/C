#include<stdio.h>
float a,b;
void add(float a,float b){
    printf("The sum is %f",a+b);
}
void dif(float a,float b){
    printf("The difference is %f",a-b);
}
void mul(float a,float b){
    printf("The product is %f",a*b);
}
void div(float a,float b){
    printf("The quotient is %f",a/b);
}
main(){
    int x;
    printf("Enter a number: ");
    scanf("%f",&a);
    printf("Enter another number: ");
    scanf("%f",&b);
    printf("1.Addition\n2.Difference\n3.Multiply\n4.Division\nPlease select an option: ");
    scanf("%d",&x);
    if (x==1) add(a,b);
    else if (x==2) dif(a,b);
    else if (x==3) mul(a,b);
    else if (x==4) div(a,b);
    else printf("Error");
}
