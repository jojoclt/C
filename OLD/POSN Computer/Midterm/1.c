#include<stdio.h>
#include<conio.h>

main(){
    int x,y;
    int sum=0;
    char ch;
    for(y=0;y<10;y++){
        for(x=0;x<=10;x++){
            sum+=x+y;
            if((x*y)%3==0)
                sum-=1;
        }
        if ((y%3)==0){
            sum%=26;
            ch='A'+sum;
            printf("%c\n",ch);
        }
    }
}
