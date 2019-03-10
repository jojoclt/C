#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
main(){
    int n,m,i,j,t,c,a[10],d;
    for(i=0;i<10;i++)
        a[i]=0;
    printf("n=");scanf("%d",&n);
    printf("m=");scanf("%d",&m);
    for(i=n;i<=m;i++){
        c=i;t=0;
        while(1){
        c-=pow(10,t);
        if(c<0)break;
        else c+=pow(10,t++);
        }
        t--;
        c=i;
        for(j=t;j>=0;j--){
            d=0;
            while(1){
                c-=pow(10,j);
                if(c<0){c+=pow(10,j);a[d]++;break;}
                else d++;
            }
        }
    }
    for(i=0;i<10;i++)
        printf("%d %d\n",i,a[i]);
    return 0;
}

