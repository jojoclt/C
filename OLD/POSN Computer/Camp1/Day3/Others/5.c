#include<stdio.h>
main(){
    int ID, X, n=1;
    char name[1005];
    printf("Enter ID, name, score:\n");
    while(1){
        scanf("%d %c %d",&ID,&name,&X);
        if (ID==9) break;
        else n++;
    }
    printf("There were %d students.",n);
}
