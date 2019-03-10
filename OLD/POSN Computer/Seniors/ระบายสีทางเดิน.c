#include<stdio.h>
#include<math.h>
/*
7 5
1 1 4 5
1 6 3 2
2 7 2
2 3 5
1 5 1 20
*/
main(){
    int n,q,a,b,i,j,c,r;
    while(1){
        scanf("%d",&n);
        if(n<1||n>5000)printf("Error\n");
        else break;
    }
    while(1){
        scanf("%d",&q);
        if(q<1||q>5000)printf("Error\n");
        else break;
    }
    int s[n];
    for(i=0;i<n;i++)s[i]=0;
    for(a=0;a<q;a++){
        scanf("%d",&b);
        if(b==1){
            scanf("%d%d%d",&i,&j,&c);
            for(a=i;a<=j;a++){
                s[a]+=c;
            }
        }
        else if(b==2){
            r=0;
            scanf("%d%d",&i,&j);
            if(i<=j){
                for(a=i;a<=j;a++)
                    r+=s[a];
            }
            else{
                for(a=j;a<n;a++)
                    r+=s[a];
                for(a=0;a<=i;a++)
                    r+=s[a];
            }
            printf("%d\n",r);
        }
        else{
            printf("Error\n");
            a--;
        }
    }
}
