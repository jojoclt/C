#include<stdio.h>
void main(){
    int y,b1000,b500,b100/*,b50,b20,b10,b5,b1*/;
    b1000=b500=b100/*=b50=b20=b10=b5=b1*/=0;
    scanf("%d",&y);

    for(b1000=0;;b1000++){
        y-=1000;
        if(y>=0) continue;
        else {
            y+=1000;
            break;
        }
    }
    for(b500=0;;b500++){
        y-=500;
        if(y>=0) continue;
        else {
            y+=500;
            break;
        }
    }
    for(b100=0;;b100++){
        y-=100;
        if(y>=0) continue;
        else {
            y+=100;
            break;
        }
    }
    /*for(b50=0;;b50++){
        y-=50;
        if(y>=0) continue;
        else {
            y+=50;
            break;
        }
    }
    for(b20=0;;b20++){
        y-=20;
        if(y>=0) continue;
        else {
            y+=20;
            break;
        }
    }
    for(b10=0;;b10++){
        y-=10;
        if(y>=0) continue;
        else {
            y+=10;
            break;
        }
    }
    for(b5=0;;b5++){
        y-=5;
        if(y>=0) continue;
        else {
            y+=5;
            break;
        }
    }
    for(b1=0;;b1++){
        y-=1;
        if(y>=0) continue;
        else {
            y+=1;
            break;
        }
    }*/
    printf("B1000=%d\n B500=%d\n B100=%d\n"
           /*B50=%d\n B20=%d\n B10=%d\n B5=%d\n B1=%d\n"*/,b1000,b500,b100
           /*,b50,b20,b10,b5,b1*/);
    getch();
}
