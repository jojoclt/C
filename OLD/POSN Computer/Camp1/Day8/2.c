#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
int i;
char a[1005],b[1005];
void c(char *pa,char *pb){
    for(i=0;i<1005;i++)
        *(pb++)=*(pa++);
}
main(){
    gets(a);
    c(&a,&b);
    printf("%s",b);
}

