#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char *p,c[1005];
int i,n=0;
int vowel(char* c){
    p=c;
    for(i=0;i<strlen(c);i++){
        if (*p=='a'||
            *p=='A'||
            *p=='e'||
            *p=='E'||
            *p=='i'||
            *p=='O'||
            *p=='o'||
            *p=='I'||
            *p=='U'||
            *p=='u'){n++;p++;}
        else p++;
    }
    return n;
}
main(){
    scanf("%s",&c);
    printf("%d",vowel(c));
}

