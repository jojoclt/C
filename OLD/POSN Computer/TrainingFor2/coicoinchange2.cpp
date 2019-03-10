#include<bits/stdc++.h>
using namespace std;
//incomplete af
int p,m,k,chng,c1;
int a[10],b[10],c[10],d[10];
//a=coin types,b=holding current # of coins,c=holding optimal # of coins
int mem[10000];
int f(int x){
    if(!mem[x]){
        if(x<p){
            mem[x]=1e9;
            for(int i=0;i<k;i++){
                b[i]++;
                if(f(x+a[i])+1<mem[x]){
                    mem[x]=f(a[x]+x)+1;
                }
                mem[x]=min(f(x+a[i])+1,mem[x]);
                b[i]--;
            }
        }
        else{
            if(x>m)
                return 9e8;
            else{
                for(int i=0;i<k;i++)
                    c[i]=b[i];
                return 0;
            }
        }
    }
    //printf("mem[%d]=%d\n",x,mem[x]);
    return mem[x];
}
int f2(int x){

}
void f2(int x,int y){
/*    if(!mem2[x][y]){
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
    }
    mem2[x][y]=1;*/
}
main(){
    scanf("%d%d%d",&p,&m,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    printf("\nf(0)=%d\n",f(0));
    c1=mem[0];
    for(int i=0;i<k;i++)
        chng+=a[i]*c[i];
    chng-=p;
    p=chng;
    for(int i=0;i<k;i++)
        f2(0,i);
    for(int i=0;i<k;i++)
        printf("%d ",c[i]);
    printf("\n");
    for(int i=0;i<k;i++)
        printf("%d ",d[i]);
}
