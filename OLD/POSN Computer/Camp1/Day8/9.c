#include <stdio.h>
#include <string.h>
char* word(char* s,int i){
    char* digit[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    return digit[*(s+i)-'0'];
}
int main(){
    char s[10005];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        printf("%s ",word(s,i));
    }
    printf("\n");
    return 0;
}
