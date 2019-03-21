#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
};
int m,n,sx,sy,ex,ey,cnt,low=1e9;
int i,j;
int tx[] = {1,0,-1,0};
int ty[] = {0,1,0,-1};

int visited[150][150];
int go[150][150];
bool a[150][150];
queue <node> q;
queue <node> b;

void bomb(){
    while (!b.empty()){
        node t = b.front(); b.pop();
//        printf("go[%d][%d] = %d\n",t.x,t.y,go[t.x][t.y]);
        if (t.x == ex && t.y == ey){
            low = min(low,go[t.x][t.y]);
            cnt++;
            memset(go,0,sizeof(go));
            return ;
        }
        for (int i = 0; i < 4; i++){
            int X = t.x+tx[i], Y = t.y+ty[i];
            if (X == sx && Y == sy || visited[X][Y]) continue;
            if (a[X][Y] && !go[X][Y]){
                go[X][Y] = go[t.x][t.y] + 1;
                b.push({X,Y});
            }
        }
    }
}
void bfs(){
    while (!q.empty()){
        node t = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int X = t.x+tx[i], Y = t.y+ty[i];
            if (visited[X][Y]) continue;
            if (a[X][Y]){
                visited[X][Y] = visited[t.x][t.y] + 1;
                q.push({X,Y});
            }
            else {
                go[X][Y] = visited[X][Y] = visited[t.x][t.y] + 2;
                b.push({X,Y});
                bomb();
            }
        }
    }
}


int main(){
    cin >> m >> n >> sx >> sy >> ex >> ey;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    q.push({sx,sy});
    bfs();
    printf("%d\n%d",cnt,low);
}
