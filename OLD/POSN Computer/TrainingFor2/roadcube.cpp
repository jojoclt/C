#include<bits/stdc++.h>
using namespace std;
int mem[100][10000];
int n,m,k,ans;
int a[100][10000];
void f(int x,int y){
    if(x>0){
        int c,d;
        c=y-k;d=y+k;
        if(c<0)c=0;if(d>m-1)d=m-1;
        //printf("%d %d\n",c,d);
        for(int i=c;i<=d;i++){
            if(mem[x-1][i]<mem[x][y]+a[x-1][i]){
                //printf("%d+%d\n",mem[x][y],a[x-1][i]);
                mem[x-1][i]=mem[x][y]+a[x-1][i];
                f(x-1,i);
            }
        }
    }
    else if(mem[x][y]>ans)ans=mem[x][y];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        mem[n-1][i]=a[n-1][i];
        f(n-1,i);
    }
    printf("%d",ans);
    return 0;
}
