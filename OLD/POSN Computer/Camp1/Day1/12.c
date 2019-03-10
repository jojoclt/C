#include<stdio.h>
#include<conio.h>
main(){
    char name[1005], school[1005], tel[1005];
    int age;
    printf("Enter your name:\n");
    gets(name);
    printf("Enter your age:\n");
    scanf("%d",&age);
    printf("Enter your school:\n");
    scanf(" %s", &school);
    printf("Enter your telephone number:\n");
    scanf(" %s", &tel);
    printf("Your name is %s.\n", name);
    printf("You are %d years old.\n", age);
    printf("The school you attend is %s.\n", school);
    printf("Your telephone number is %s.\n", tel);
    getch();
}
