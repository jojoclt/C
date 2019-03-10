#include<bits/stdc++.h>
using namespace std;
int p,m,k,mini,mini2,cn,divine;
int a[10],b[10];
int mem[1000000];
int f(int x){
        if(x>0){
            mem[x]=1e9;
            for(int i=0;i<k;i++)
                if(x-a[i]>=0)
                    mem[x]=min(f(x-a[i])+1,mem[x]);
        }
        else
            return 0;
    return mem[x];
}
void c(int x,int cn){
    if(divine==7)return;
    cn++;
    if(cn>mem[mini2])x=x;
    else{
        for(int j=0;j<k;j++){
            b[j]++;
            x-=a[j];
            if(x==0){
                divine=7;
                return;
            }
            else{
                c(x,cn);
                if(divine==7)return;
                x+=a[j];
                b[j]--;
            }
        }
    }
}
void c2(int x,int cn){
    if(divine==7)return;
    cn++;
    if(cn>mem[mini2-p])x=x;
    else{
        for(int j=0;j<k;j++){
            b[j]++;
            x-=a[j];
            if(x==0){
                divine=7;
                return;
            }
            else{
                c2(x,cn);
                if(divine==7)return;
                x+=a[j];
                b[j]--;
            }
        }
    }
}
main(){
    scanf("%d%d%d",&p,&m,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    mini=1e9;
    for(int i=p;i<=m;i++)
        if(mini>f(i)){mini=f(i);mini2=i;}
    printf("%d %d\n",mem[mini2],mem[mini2-p]);
    c(mini2,0);
    for(int i=0;i<k;i++)
        printf("%d ",b[i]);
    for(int i=0;i<k;i++){b[i]=0;}
    printf("\n");
    cn=divine=0;
    c2(mini2-p,0);
    for(int i=0;i<k;i++){
        printf("%d ",b[i]);
    }
}
/*
8 9 3
5 1 10

8 20 3
1 5 10
*/
