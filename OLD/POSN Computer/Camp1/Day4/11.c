#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int check(int x, int n){
    if (x>1000||x<1)return 3;
    else if (x==n) return 0;
    else if (x<n) return 1;
    else if (x>n) return 2;
}
main(){
    int x,n;char c;
    srand(time(NULL));
    n=(rand()%1000)+1;
    printf("I have a number between 1 and 1000\nCan you guess my number?\nPlease type your selected number: ");
    while(1){
        scanf("%d",&x);
        if (check(x,n)==0){
            printf("Excellent! You are correct!\n Would you like to play again? (y or n)\n");
            while(1){
                scanf("%c",&c);
                if (c=='y'){
                    main();break;
                }
                else if (c=='n'){
                    printf("Bye!");break;
                }
            }
            break;
        }
        else if (check(x,n)==1)printf("The number is too low. Try again.\n");
        else if (check(x,n)==2)printf("The number is too high. Try again.\n");
        else if (check(x,n)==3)printf("Not a valid number. Try again.\n");
    }
}
