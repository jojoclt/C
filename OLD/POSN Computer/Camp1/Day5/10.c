#include<stdio.h>
#include<stdlib.h>
int toInt(char c){
    return (int)c-'0';
}
main(){
    int i,j=0,tmp;
    char n[19],x[16];
    printf("Enter your credit card number (xxxx-xxxx-xxxx-xxxx) (must include -) :\n");
    for(i=0;i<19;i++){
        scanf(" %c",&n[i]);
        if(n[i]!='-'){x[j]=n[i];j++;}
    }
    x[16]='\0';
    j=0;
    for(i=0;i<16;i++){
        if(i%2==0){
            tmp=toInt(x[i])*2;
            if (tmp>=10)tmp-=9;
            j+=tmp;
        }
        else {
            j+=toInt(x[i]);
        }
    }
    if(j%10==0)printf("This credit card is real");
    else printf("This credit card is fake");

}
