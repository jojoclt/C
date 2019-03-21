#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y,w;
};
int m,n,sx,sy,ex,ey,cnt,ans;
int i,j;
int tx[] = {1,0,-1,0};
int ty[] = {0,1,0,-1};

int visited[150][150][2];
bool a[150][150];
bool k[150][150];
queue <node> q;
void bfs(){
    while (!q.empty()){
        node t = q.front(); q.pop();
        if (t.x == ex && t.y == ey){
            ans = visited[t.x][t.y][t.w]+1;
            while(!q.empty()) q.pop();
            break;
        }
        for (int i = 0; i < 4; i++){
            int X = t.x+tx[i], Y = t.y+ty[i];
            if (X == sx && Y == sy) continue;
            if (a[X][Y] && !visited[X][Y][t.w]){
                visited[X][Y][t.w] = visited[t.x][t.y][t.w] + 1;
                q.push({X,Y,t.w});
            }
            else if (!t.w && !visited[X][Y][!t.w]){
                visited[X][Y][!t.w] = visited[t.x][t.y][t.w] + 1;
                q.push({X,Y,!t.w});
            }
        }
    }
}

void check(){
    for (int i = 0; i < 4; i++){
        int X = ex+tx[i], Y = ey+ty[i];
        if (visited[X][Y][0]) q.push({X,Y,0});
        else if (visited[X][Y][1]) q.push({X,Y,1});
    }

    while (!q.empty()){
        node t = q.front(); q.pop();
        //cout << t.x <<" "<< t.y <<endl;
        //if (t.x == sx && t.y == sy) cnt++;
        for (int i = 0; i < 4; i++){
            int X = t.x+tx[i], Y = t.y+ty[i];
            if (visited[t.x][t.y][t.w]-1 == visited[X][Y][t.w]) q.push({X,Y,t.w});
            else if (visited[t.x][t.y][t.w]-1 == visited[X][Y][!t.w]){
                if (!k[X][Y]){
                    printf("%d %d\n",X,Y);
                    cnt++;
                    k[X][Y] = true;
                    //q.push({X,Y,!t.w});
                }
            }
        }
    }
}

int main(){
    cin >> m >> n >> sx >> sy >> ex >> ey;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    q.push({sx,sy,0});
    bfs();
    check();
    printf("%d\n%d\n",cnt,ans);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++) printf("%d ",visited[i][j][0]);
        cout<<endl;
    }
    cout<<endl;
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++) printf("%d ",visited[i][j][1]);
        cout<<endl;
    }
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1

6 8
1 4
2 7
0 0 1 1 0 0 0 0
1 0 1 1 0 0 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
0 1 0 1 1 1 1 1
*/
