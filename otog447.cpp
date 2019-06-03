#include <bits/stdc++.h>
using namespace std;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};
int a[56][56];
int i,j;
int n,sx,sy,ex,ey;
struct node{
    int x,y,val;
    bool l;
    bool operator < (node t) const{
        return t.val < val;
    }
}t;
int visit[56][56][2];
priority_queue<node> pq;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    pq.push({sx,sy,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == ex && t.y == ey && t.l){
            printf("%d",t.val);
            return 0;
        }
        if (visit[t.x][t.y][t.l]) continue;
        visit[t.x][t.y][t.l] = true;
        for (i = 0; i < 4; i++){
            int X = t.x+x[i], Y = t.y+y[i];
            if (a[X][Y] > 0) pq.push({X,Y,t.val+a[X][Y],t.l});
            else if (a[X][Y] < 0) pq.push({X,Y,t.val-a[X][Y],!t.l});
        }
    }
}