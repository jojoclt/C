#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[1005],*x,*y;
int i,j=0;
int pal(char* s){
    x=s;y=s+strlen(s)-1;
    /*char r[strlen(s)];
    for (i=strlen(s)-1;i>=0;i--)r[strlen(s)-1-i]=s[j];*/
    for (i=0;i<strlen(s);i++){
        if(*x==*y){
            j++;x++;y--;
        }
    }
    /*if(strcmp(s,r)==0)return 1;
    else return 0;*/
    if(j==strlen(s))return 1;
    else return 0;
}
main(){
    scanf (" %s", s);
    if(pal(s)==1)printf("yes");
    else printf("no");
}
