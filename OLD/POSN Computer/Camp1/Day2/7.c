#include<stdio.h>
#include<math.h>
main(){
    int x,y;
    float score;
    printf("Enter your midterm exam score:");
    scanf("%d",&x);
    printf("Enter your final exam score:");
    scanf("%d",&y);
    score=(x+y)/2;
    printf("Your grade is %f. ",score);
    switch((int)score/10){
        case 10:
        case 9:
        case 8:
            printf("'G' (Good).");
            break;
        case 7:
        case 6:
        case 5:
            printf("'P' (Pass)");
            break;
        default:
            printf("'F' (Fail)");
    }
}
