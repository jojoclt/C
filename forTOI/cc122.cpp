#include <bits/stdc++.h>
using namespace std;
int a,b,i,j,X,Y;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
char c[505][505];
int m[505][505][2][2][2];
struct node{
    int x,y,j,b,p;
};
queue <node> q;
bool check(int x, int y){
    if (x >= 0 && x < a && y >= 0 && y < b) return 1;
    return 0;
}
int ex,ey;
int main(){
    scanf("%d%d",&a,&b);
    for (i = 0; i < a; i++){
        for (j = 0; j < b; j++){
            scanf(" %c",&c[i][j]);
            if (c[i][j] == 'S') q.push({i,j,0,0,0});
            else if (c[i][j] == 'E'){
                ex = i; ey = j;
            }
        }
    }

    while (!q.empty()){
        node t = q.front(); q.pop();
        if (t.x == ex && t.y == ey){
            printf("%d",m[t.x][t.y][t.j][t.b][t.p]);
            return 0;
        }
        for (i = 0; i < 4; i++){
            X = t.x+x[i]; Y = t.y+y[i];
            if (check(X,Y) && !m[X][Y][t.j][t.b][t.p]){
                if (c[X][Y] == '.' || c[X][Y] == 'E' || c[X][Y] == 'S' ||
                    c[X][Y] == 'J' && t.j ||
                    c[X][Y] == 'B' && t.b ||
                    c[X][Y] == 'P' && t.p){
                    m[X][Y][t.j][t.b][t.p] = m[t.x][t.y][t.j][t.b][t.p]+1;
                    q.push({X,Y,t.j,t.b,t.p});
                }
                else if (c[X][Y] =='j' || c[X][Y] == 'b' || c[X][Y] == 'p'){
                    if (c[X][Y] =='j' && !t.j){
                        m[X][Y][1][t.b][t.p] = m[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,1,t.b,t.p});
                    }
                    else if (c[X][Y] == 'b' && !t.b){
                        m[X][Y][t.j][1][t.p] = m[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,1,t.p});
                    }
                    else if (c[X][Y] == 'p' && !t.p){
                        m[X][Y][t.j][t.b][1] = m[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,t.b,1});
                    }
                    else{
                        m[X][Y][t.j][t.b][t.p] = m[t.x][t.y][t.j][t.b][t.p]+1;
                        q.push({X,Y,t.j,t.b,t.p});
                    }
                }

            }
        }
        //printf("m[%d][%d][%d][%d][%d] = %d\n",t.x,t.y,t.j,t.b,t.p, m[t.x][t.y][t.j][t.b][t.p]);
    }
    printf("-1");
}
