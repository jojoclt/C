#include<bits/stdc++.h>
using namespace std;
int a[1005];
int mem[1005];
int track[1005];
int n,m;
int f(int x){
    int t=1e9;
    if(x>n)return 1e9;
    if(x==n)return 0;
    else if(mem[x]==0){
        for(int i=0;i<m;i++){
            if(t>f(x+a[i])+1)
            {
                t = f(x+a[i])+1;
                track[x] = i;
            }
            mem[x]=t;
        }
        return mem[x];
    }
    else return mem[x];
}
int main(){
    int k=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    printf("%d\n",f(0));
    while(k!=n){
        printf("%d ",a[track[k]]);
        k+=a[track[k]];
    }
    return 0;
}
/*
7 4
1 3 4 5
*/
