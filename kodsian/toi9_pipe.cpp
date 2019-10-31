#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,d;
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int n,m;
int i,j,tt;
bool bord(int x, int y){
    if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}
int c[305][305];
bool visit[305][305],path[305][305];
queue <node> q;
vector <node> v;
vector <int> ans;
void Clear(){
    for (auto u : v) visit[u.x][u.y] = false;
}
int bfs(int xx, int yy){
    tt = 0;
    q.push({xx,yy,-1});
    while (!q.empty()){
        t = q.front(); q.pop();
        if (visit[t.x][t.y] || !bord(t.x,t.y)) continue;
        ++tt;
        // printf("x = %d y = %d\n",t.x,t.y);
        if (path[t.x][t.y]){
            q.push({t.x+x[t.d],t.y+y[t.d],t.d});
            continue;
        }
        visit[t.x][t.y] = true;
        for (int i = 0; i < 4; i++){
            int X = t.x+x[i], Y = t.y+y[i];
            if (t.d >= 0 && (t.d+2)%4 == i) continue;
            if (bord(X,Y) && !visit[X][Y] && (c[X][Y] & 1 << (i+2)%4) && c[t.x][t.y] & 1 << i){
                q.push({X,Y,i});
                
            }
        }
    }
    return tt;
}
int main(){
    scanf("%d%d",&n,&m);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            scanf("%d",&tt);
            if (!tt) continue;
    
            if (tt == 11) c[i][j] = 1 << 0 | 1 << 3;
            else if (tt == 12) c[i][j] = 1 << 0 | 1 << 1;
            else if (tt == 13) c[i][j] = 1 << 2 | 1 << 3;
            else if (tt == 14) c[i][j] = 1 << 1 | 1 << 2;
            
            else if (tt == 21) c[i][j] = 1 << 0 | 1 << 2;
            else if (tt == 22) c[i][j] = 1 << 1 | 1 << 3;

            else if (tt == 31) c[i][j] = (1 << 4) - 1, path[i][j] = true,v.push_back({i,j});
        }
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if (path[i][j]) continue;
            if (c[i][j] && !visit[i][j]) ans.push_back(bfs(i,j)), Clear();
        }
    }
    printf("%d\n",(int)ans.size());
    for (auto u : ans) printf("%d ",u);
}