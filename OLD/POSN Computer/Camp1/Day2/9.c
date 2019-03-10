#include<stdio.h>
#include<math.h>
main(){
    char x;
    scanf(" %c",&x);
    if (x>=65&&x<=90) printf("%c",x);
    else if (x>=97&&x<=122) printf("%c",x-32);
    else printf("Error");

}
