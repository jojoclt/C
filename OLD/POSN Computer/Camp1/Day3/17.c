#include <stdio.h>
#include <string.h>
int main(){
    char a[1005],n[1005];
    int i,x=0;
    for(i=0;i<1005;i++)n[i] = 255;
    scanf("%s",&a);
    for(i=0;i<strlen(a);i++){
        if(a[i] == n[x]){printf("N");n[x]=n[x+1];}
        else n[x] = a[i];
        printf("%c",a[i]);
    }
}
