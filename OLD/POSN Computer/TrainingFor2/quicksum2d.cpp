#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1005][1005];
int x1[1005],y10[1005],x2[1005],y2[1005];
int mem[1005][1005];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<q;i++){
        scanf("%d",&x1[i]);
        scanf("%d",&y10[i]);
        scanf("%d",&x2[i]);
        scanf("%d",&y2[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mem[i][j]=mem[i-1][j]+mem[i][j-1]-mem[i-1][j-1]+a[i][j];
    for(int i=0;i<q;i++){
        int a1=max(x1[i],x2[i]);
        int a2=min(x1[i],x2[i]);
        int b1=max(y10[i],y2[i]);
        int b2=min(y10[i],y2[i]);
        //printf("%d-%d-%d+%d=",mem[b1-1][a1-1],mem[b2-2][m-1],mem[n-1][a2-2],mem[a2-2][b2-2]);
        printf("%d\n",mem[b1-1][a1-1]-mem[b2-2][a1-1]-mem[b1-1][a2-2]+mem[a2-2][b2-2]);
    }
    return 0;
}
/*
4 4 3
2 3 5 6
1 9 2 4
0 5 7 3
1 2 3 4

3 1 2 4
4 4 1 1
1 2 3 4
*/
