#include<stdio.h>
#include<string.h>
main(){
    char n[1005],surn[1005],g[1005];
    printf("Name: ");scanf(" %s",&n);
    printf("Surname: ");scanf(" %s",&surn);
    while(1){
        printf("Gender (male or female): ");
        scanf(" %s",&g);
        if(strcmp(g,"male")==0){
            printf("Mr. %s %s",n,surn);
            break;
        }
        else if(strcmp(g,"female")==0){
            printf("Mrs. %s %s",n,surn);
            break;
        }
        else{
            printf("That is not a gender.\n");
        }
    }
}
