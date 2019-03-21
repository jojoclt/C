#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,w;
};
int m,n,sx,sy,ex,ey;
int i,j,cnt;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int mem[151][151][2];
bool a[151][151];
queue <node> q;
bool visit[151][151];
bool mark[151][151];
void dfs(int ax, int ay){
    if (mark[ax][ay]) return;
    if (visit[ax][ay]) return;
//    cout << ax << " " <<ay<<endl;
    if (ax == ex && ay == ey){
        cnt++;
        return;
    }
    visit[ax][ay] = true;
    for (int i = 0; i < 4; i++){
        if (a[ax+x[i]][ay+y[i]])
            dfs(ax+x[i],ay+y[i]);
    }
}

int main(){
    cin >> m >> n >> sx >> sy >> ex >> ey;
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    q.push({sx,sy,0});
    while (!q.empty()){
        node t = q.front(); q.pop();
        if (t.x == ex && t.y == ey){
            printf("%d\n%d\n",cnt,mem[t.x][t.y][t.w]);
            //return 0;
        }
        for (i = 0; i < 4; i++){
            int tx = t.x+x[i], ty = t.y+y[i];
            if (a[tx][ty] && !mem[tx][ty][t.w]){
                if (tx == sx && ty == sy) continue;
                mem[tx][ty][t.w] = mem[t.x][t.y][t.w] + 1;
                q.push({tx,ty,t.w});
            }
            else if (!a[tx][ty] && !mem[tx][ty][t.w]){
                if (t.w) continue;
                memset(visit,false,sizeof(visit));
                dfs(tx,ty);
                mark[tx][ty] = true;
//                cout<<endl;
                mem[tx][ty][1] = mem[t.x][t.y][0] + 2;
                q.push({tx,ty,1});
            }
        }
    }
//    for (i = 1; i <= m; i++){
//        for (j = 1; j <= n; j++)
//            printf("%d ",mem[i][j][0]);
//        printf("\n");
//    }
//    printf("\n");
//    for (i = 1; i <= m; i++){
//        for (j = 1; j <= n; j++)
//            printf("%d ",mem[i][j][1]);
//        printf("\n");
//    }
}
