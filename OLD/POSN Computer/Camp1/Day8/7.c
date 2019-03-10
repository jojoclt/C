#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[1005],*p;
int i;
char cap(char c){
    if(c>='a'&&c<='z')
        return c-'a'+'A';
    else return c;
}
main(){
    scanf(" %s",s);
    p=s;
    for(i=0;i<strlen(s);i++){
        printf("%c",cap(*(p++)));
    }
}

