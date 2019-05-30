#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,l,r;
};
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
int i,j,X,Y,cnt;

char T;
int m,n,sx,sy,ll,rr;
bool a[2005][2005],visit[2005][2005];
int l[2005][2005],r[2005][2005];
queue <node> q;
int main(){
    scanf("%d%d%d%d%d%d",&m,&n,&sx,&sy,&ll,&rr);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&T);
            if (T == '.') a[i][j] = true;
        }
    }
    q.push({sx,sy,0,0});
    while(!q.empty()){
        node t = q.front(); q.pop();
        l[t.x][t.y] = t.l, r[t.x][t.y] = t.r;
        // printf("%d %d %d %d\n",t.x,t.y,t.l,t.r);
        for (i = 0; i < 4; i++){
            X = t.x+x[i], Y = t.y+y[i];
            if (X == sx && Y == sy) continue;
            if (a[X][Y]){
                if (visit[X][Y]) continue;
                visit[X][Y] = true;
                if (i == 0) q.push({X,Y,t.l,t.r+1});
                else if (i == 1) q.push({X,Y,t.l+1,t.r});
                else q.push({X,Y,t.l,t.r});
                
            }
        }
    }
   for (i = 1; i <= m; i++){
       for (j = 1;j <= n; j++){
        //    printf("a[%d][%d] = %d %d\n",i,j,l[i][j],r[i][j]);
           if (l[i][j] <= ll && r[i][j] <= rr && visit[i][j]){
            //    printf("%d %d\n",i,j);
               cnt++;
           }
       }
   }
   
    printf("%d",cnt+1);
}
