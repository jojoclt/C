#include<stdio.h>
#include<math.h>
#include<conio.h>
//3 3 10
void n();
main(){
    int x,y,z,i,j,h,w,f;
    while(1){
        scanf("%d",&x);
        if(x<1||x>10){n();return 0;}
        else break;
    }
    while(1){
        scanf("%d",&y);
        if(y<3||y>10){n();return 0;}
        else break;
    }
    while(1){
        scanf("%d",&z);
        if(z<2||z>32){n();return 0;}
        else break;
    }
    if(z-2*(x-1)<=0){n();return 0;}
    w=z+8;
    for(i=0;i<x+1;i++)printf(" ");
    for(i=0;i<z-2*(x-3);i++)printf("_");
    for(i=0;i<x+1;i++)printf(" ");
    printf("\n");
    for(f=x;f>=1;f--){
        for(i=1;i<=y;i++){
            for(j=1;j<=w;j++){
                if(i==1){
                    if(j==f+1||j==f+4)printf("/");
                    else if(j==w-f||j==w-f-3)printf("\\");
                    else printf(" ");
                }
                else if(i==y&&f==1){
                    if(j==f+3||j==w-f-2)printf("|");
                    else if((j>f+3&&j<w-f-2))printf("_");
                    else printf(" ");
                }
                else if(i==y){
                    if(j==f||j==f+3||j==w-f+1||j==w-f-2)printf("|");
                    else if((j>f&&j<w-f+1))printf("_");
                    else printf(" ");
                }
                else{
                    if(j==f+3||j==w-f-2)printf("|");
                    else printf(" ");
                }
            }
            printf("\n");
        }
    }
}
void n(){
    int i,k;
    char a[6]="NANI!?";
    printf("Omae wa mou shindeiru\n");
    for(k=0;k<6;k++)
        for(i=0;i<=1<<29-1;i++)
            if(i==1<<29-1)printf("%c\n",a[k]);
}
