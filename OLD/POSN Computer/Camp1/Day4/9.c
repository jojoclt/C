#include<stdio.h>
#include<math.h>
int a,b,c;
int QualityPoints(int a,int b, int c){
    int p;
    p=a+b+c;
    switch(p/10){
        case 10:
        case 9:
            return 4;
            break;
        case 8:
            return 3;
            break;
        case 7:
            return 2;
            break;
        case 6:
            return 1;
            break;
        default:
            return 0;
    }
}
main(){
    int p;
    printf("Your non-exam score: ");scanf("%d",&a);
    if(a>60||a<0)printf("Error");
    else{
        printf("Your midterm exam score: ");scanf("%d",&b);
        if(b>20||b<0)printf("Error");
        else {
                printf("Your final exam score: ");scanf("%d",&c);
                if(c>20||c<0)printf("Error");
                else p=QualityPoints(a,b,c);
        }
    }
    printf("Your grade is %d",p);
}
