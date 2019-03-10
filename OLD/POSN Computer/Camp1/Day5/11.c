#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
    char s[1005];
    int j;
    printf("Your string: ");scanf ("%[^\n]%*c", s);
    char r[strlen(s)];
    for (j=strlen(s)-1;j>=0;j--)r[strlen(s)-1-j]=s[j];
    if(strcmp(s,r)==0)printf("%s is a palindrome",s);
    else printf("%s isn't a palindrome",s);
}
