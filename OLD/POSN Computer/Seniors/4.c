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
    int n,q,a,b,i,j,c,r,k=0;
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
    int s[n],p[q];
    for(i=0;i<n;i++)s[i]=0;
    for(a=0;a<q;a++){
        scanf("%d",&b);
        if(b==1){
            scanf(" %d %d %d",&i,&j,&c);
            if(i<=j){
                for(b=i;b<=j;b++)
                    s[b-1]+=c;
            }
            else{
                for(b=j;b<=i;b++)
                    s[b-1]+=c;
            }
        }
        else if(b==2){
            r=0;
            scanf(" %d %d",&i,&j);
            if(i>j){
                r=i;
                i=j;
                j=r;
                r=0;
            }
            if(j-i>n/2){
                for(b=j;b<=n;b++)
                    r+=s[b-1];
                for(b=1;b<=i;b++)
                    r+=s[b-1];
            }
            else for(b=i;b<=j;b++)
                r+=s[b-1];
            p[k++]=r;
        }
        else{
            printf("Error\n");
            a--;
        }
    }
    printf("\n");
    for(i=0;i<k;i++)
        printf("%d\n",p[i]);
}
