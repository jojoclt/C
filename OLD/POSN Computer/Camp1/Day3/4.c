#include<stdio.h>
main(){
    char x;
    int n=0;
    while(1){
        scanf("%c",&x);
        if (x=='a'||
            x=='A'||
            x=='e'||
            x=='E'||
            x=='i'||
            x=='O'||
            x=='o'||
            x=='I'||
            x=='U'||
            x=='u')n++;
        else if (x=='\n') break;
        else continue;
    }
    printf("The number of vowels is %d.",n);
}
