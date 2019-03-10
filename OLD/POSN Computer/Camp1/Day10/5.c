#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    float f;
    char x,y;
    scanf("%f",&f);
    scanf(" %c",&x);
    scanf(" 0 30ew
          %c",&y);
    if(x=='K'&&y=='C'){
        f-=273.15;
    }
    else if(x=='K'&&y=='F'){
        f=f*1.8-459.67;
    }
    else if(x=='C'&&y=='K'){
        f+=273.15;
    }
    else if(x=='C'&&y=='F'){
        f=f*1.8+32;
    }
    else if(x=='F'&&y=='C'){
        f=(f-32)*5/9;
    }
    else if(x=='F'&&y=='K'){
        f=(f+459.67)*5/9;
    }
    else if(x==y)f=f;
    printf("%.3f",f);
}

