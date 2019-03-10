#include<stdio.h>
#include<math.h>
#include <string.h>
char s1[20000],s2[20000],*a,*b,*c,tmp;
    int d,*p,n,i,j;
int an(char s1[20000],char s2[20000]){
    a=s1;c=s2;
    for(i=0;i<strlen(s1);i++){
        b=s2+i;
        for(j=i;j<strlen(s2);j++){
            if(*a==*b){
                tmp=*b;
                *b=*c;
                *c=tmp;
                b++;c++;
                break;
            }
            else b++;
        }
        if(j==strlen(s2))return 0;
        else a++;
    }
    return 1;
}
main(){
    scanf(" %s",&s1);
    scanf(" %s",&s2);
    if(strlen(s1)!=strlen(s2))d=0;
    else d=an(s1,s2);
    p=&d;
    if(*p==1)printf("\nyes");
    else if (*p==0) printf("\nno");
}

