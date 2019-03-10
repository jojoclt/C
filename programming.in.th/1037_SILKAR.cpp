#include <bits/stdc++.h>
using namespace std;
int m,n,ex,ey;
struct node{
    int x,y;
}t;
int i,j,X,Y;
char tt;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
bool wall[55][55];
int water[55][55];
int go[55][55];
bool check(int x,int y){
    if (x >= 1 && x <= m && y >= 1 && y <= n) return 1;
    return 0;
}
queue <node> q,w;

int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&tt);
            if (tt == 'D'){
                ex = i;
                ey = j;
            }
            else if (tt == 'S') q.push({i,j});
            else if (tt == '*') w.push({i,j});
            else if (tt == 'X') wall[i][j] = true;
        }
    }
    while (!w.empty()){
        t = w.front(); w.pop();
        for (i = 0; i < 4; i++){
            X = t.x+x[i], Y = t.y+y[i];
            if (X == ex && Y == ey) continue;
            if (check(X,Y) && !wall[X][Y]&& !water[X][Y]){
                water[X][Y] = water[t.x][t.y]+1;
                w.push({X,Y});
            }
        }
    }
//    for (i = 1; i <= m; i++){
//        for (j = 1; j <= n; j++){
//            printf("%d ",water[i][j]);
//        }cout<<endl;
//    }
    while (!q.empty()){
        t = q.front(); q.pop();
         for (i = 0; i < 4; i++){
            X = t.x+x[i], Y = t.y+y[i];
            if (check(X,Y) && !wall[X][Y] && !go[X][Y]){
                go[X][Y] = go[t.x][t.y]+1;
                if (go[X][Y] < water[X][Y] || !water[X][Y]) q.push({X,Y});
            }
        }
    }
//    for (i = 1; i <= m; i++){
//        for (j = 1; j <= n; j++){
//            printf("%d ",go[i][j]);
//        }cout<<endl;
//    }
    if(go[ex][ey]){
        printf("%d",go[ex][ey]);
        return 0;
    }
    printf("KAKTUS");
}
