#include<stdio.h>
#include<conio.h>
main(){
    int ft, in;
    printf("Enter feet: ");
    scanf("%d", &ft);
    in = 12*ft;
    printf("%d feet = %d inches", ft, in);
    getch();
}
