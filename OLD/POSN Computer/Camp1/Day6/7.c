#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
main(){
    char s[1005];
    int i;
    scanf(" %s",s);
    for(i=0;i<strlen(s);i++){
        if (s[i]!=s[i-1]){
            printf("%c",s[i]);
        }
    }
}

