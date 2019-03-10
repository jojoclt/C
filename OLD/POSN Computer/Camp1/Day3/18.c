#include<stdio.h>
#include <string.h>
main(){
    char a[1005],b[1005];
    int i;
        scanf(" %s",&a);
    for(i=strlen(a)-1;i>=0;i--){
        printf("%c",a[i]);
    }
}
