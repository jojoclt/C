#include <bits/stdc++.h>
using namespace std;
int mem[1003][1003];
int t1,t2,k;
int xx1,xx2,yy1,yy2;
int n,m;
int i,j;
int main(){
    scanf("%d%d",&n,&m);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        mem[++t1][++t2]++;
    }
    for (i = 1; i < 1003; i++){
        for (j = 1; j < 1003; j++){
            mem[i][j] += mem[i-1][j] + mem[i][j-1] - mem[i-1][j-1];
        }
    }
    //return 0;
    for (i = 0; i < m; i++){
        scanf("%d%d%d",&t1,&t2,&k);
        t1++;t2++;
        xx1 = (t1-k-1>=0)?t1-k-1:0;
        xx2 = (t1+k<=1001)?t1+k:1001;
        yy1 = (t2-k-1>=0)?t2-k-1:0;
        yy2 = (t2+k<=1001)?t2+k:1001;
        printf("%d\n",mem[xx2][yy2]-mem[xx2][yy1]-mem[xx1][yy2]+mem[xx1][yy1]);
    }
}
