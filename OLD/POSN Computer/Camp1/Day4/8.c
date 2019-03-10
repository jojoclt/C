#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int check (int a,int x, int y){
    if (a==x*y) return 1;
    else return 0;
}
main(){
    int y,x,a,b,i;
    srand(time(NULL));
    y=rand()%10;
    x=rand()%10;
    printf("%d %d\nWhat is %d x %d?\n",x,y,x,y);
    for(i=0;i<3;i++){
        scanf("%d",&a);
        if(check(a,x,y)==1)break;
        else printf("Wrong, try again\n");
    }
    if (check(a,x,y)==0)printf("Game Over");
    else printf("You are correct!");
}
