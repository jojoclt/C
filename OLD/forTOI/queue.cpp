#include <bits/stdc++.h>
#define M 5
using namespace std;
struct axis{
    int x,y;
};
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
int m[M][M],i,X,Y;
int sx,sy;
queue <axis> q;
bool check(int x, int y){
    if (x < 0 || y < 0 || x > M || y > M) return 0;
    return 1;
}
int main(){
    cin >> sx >> sy;
    q.push({sx,sy});

    while (!q.empty()){
        axis t = q.front(); q.pop();
        for (i = 0; i < 4; i++){
            X = t.x+x[i], Y = t.y+y[i];
            if (check(X,Y) && !m[X][Y]){
                if (X == sx && Y == sy) continue;
                m[X][Y] = m[t.x][t.y]+1;
                q.push({X,Y});
            }
//            if (m[4][4]){
//                for (int a = 0; a < M; a++){
//                    for (int b = 0; b < M; b++){
//                        printf("%d ",m[a][b]);
//                    }cout <<endl;
//                }
//                return 0;
//            }
        }
    }

        for (int a = 0; a < M; a++){
            for (int b = 0; b < M; b++){
                printf("%d ",m[a][b]);
            }cout <<endl;
        }
}
