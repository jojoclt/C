#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int a[5][6]={{5,6,3,1,4,7},{6,1,3,8,9,4},{5,7,1,8,4,6},{1,2,9,1,3,4},{5,6,3,1,4,7}};
    int i,n[5],d;
    for(i=0;i<5;i++)scanf("%d",&n[i]);
    while(1){
        scanf("%d",&d);
        if(d<=0||d>6)printf("Invalid, try again");
        else break;
    }
    printf("%d ",a[0][d-1]);
    for(i=1;i<5;i++){
        if(i%2!=0){
            if (n[0]+n[i]>=d)
                printf("_ ");
            else printf("%d ",a[i][d-n[0]-n[i]-1]);
        }
        else {
            if (n[i]-n[0]>6-d)
                printf("_ ");
            else printf("%d ",a[i][n[i]-n[0]+d-1]);
        }
    }
}

