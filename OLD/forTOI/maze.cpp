#include <bits/stdc++.h>
using namespace std;
int m,n,sx,sy,ex,ey,cnt,low=1e9;
int i,j;
int tx[] = {1,0,-1,0};
int ty[] = {0,1,0,-1};
int visited[150][150];
int go[150][150];
bool a[150][150];
void afterbomb(int x, int y){
    printf("go[%d][%d] = %d\n",x,y,go[x][y]);
    //cout << x << " " << y<<endl;
    if (x == ex && y == ey){
        low = min(low,go[x][y]);
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++){
        int X = x+tx[i], Y = y+ty[i];
        if (X == sx && Y == sy || visited[x][y]) continue;
        if (a[X][Y] && !go[X][Y]){
            go[X][Y] = go[x][y] + 1;
            afterbomb(X,Y);
        }
    }
}
void dfs(int x, int y){
    for (int i = 0; i < 4; i++){
        int X = x+tx[i], Y = y+ty[i];
        if (visited[X][Y]) continue;
        if (a[X][Y]){
            visited[X][Y] = visited[x][y] + 1;
            dfs(X,Y);
        }
        else if (!a[X][Y]){
            cout<<9;
            go[X][Y] = visited[x][y]+2;
            afterbomb(X,Y);
            visited[X][Y] = -1;
            memset(go,0,sizeof(go));
        }
    }
}
int main(){
    cin >> m >> n >> sx >> sy >> ex >> ey;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    dfs(sx,sy);
    printf("%d\n%d",cnt,low);
}
