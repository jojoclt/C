#include<stdlib.h>
#include<string.h>
int main(){
    char m[4],n[4];
    int i;
    scanf("%s",m);


    for(i=0;i<4;i++){
        n[i]=m[3-i];
        n[i]+=5;
        if(n[i]>'9')n[i]-=10;
        printf("%d",(int)n[i]-'0');
    }
    return 0;
}
