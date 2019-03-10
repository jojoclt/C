#include<bits/stdc++.h>
using namespace std;
int p,m,k,chng;
int mini=1e9;
int mini2=1e9;
int a[10],b[10],c[10],d[10];
//a=coin types,b=holding current # of coins,c=holding optimal # of coins
//int mem[10000][10],mem2[10000][10];
void f(int x,int y){
     //if(!mem[x][y]){
        if(x==0)
            for(int i=0;i<k;i++)
                b[i]=0;
        x+=a[y];
        b[y]++;
        if(x>=p){
            if(x>m){
                x=x;
            }
            else{
                int sum=0;
                for(int i=0;i<k;i++)
                    sum+=b[i];
                if(sum<mini){
                    mini=sum;
                    for(int i=0;i<k;i++)
                        c[i]=b[i];
                }
            }
        }
        else{
            for(int i=0;i<k;i++)f(x,i);
        }
        b[y]--;
    //}
    //mem[x][y]=1;
}
void f2(int x,int y){
    //if(!mem2[x][y]){
        if(x==0)
            for(int i=0;i<k;i++)
                b[i]=0;
        x+=a[y];
        b[y]++;
        if(x==p){
            int sum=0;
            for(int i=0;i<k;i++)
                sum+=b[i];
            if(sum<mini2){
                mini2=sum;
                for(int i=0;i<k;i++)
                    d[i]=b[i];
            }
        }
        else if(x>p)
            x=x;
        else{
            for(int i=0;i<k;i++)f2(x,i);
        }
        b[y]--;
    //}
    //mem2[x][y]=1;
}
main(){
    scanf("%d%d%d",&p,&m,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
        f(0,i);
    for(int i=0;i<k;i++)
        chng+=a[i]*c[i];
    chng-=p;
    p=chng;
    for(int i=0;i<k;i++)
        f2(0,i);
    if(mini2==1e9)mini2=0;
    printf("%d %d\n",mini,mini2);
    for(int i=0;i<k;i++)
        printf("%d ",c[i]);
    printf("\n");
    for(int i=0;i<k;i++)
        printf("%d ",d[i]);
}
