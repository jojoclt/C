#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(){
    int i;
    char s[1005];
    printf("Your string: ");scanf ("%[^\n]%*c", s);
    printf("Secret: ");
    for(i=0;i<strlen(s);i++){
        if (s[i]!=' ')printf("%c",s[i]+1);
        else printf(" ");
    }
    return 0;
}
