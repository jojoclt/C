#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,t,gem,c;
}t;
int x[] = {1,0,-1,0,0};
int y[] = {0,1,0,-1,0};
int m,n;
char c;
int i,j;
int a[205][205];
queue <node> q;
int mem[205][205][6][1<<8];
int cnt;
void f(int x){
    printf("Case %d\n",x);
}
int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i <= m; ++i){
        for (j = 1; j <= n; ++j){
            scanf(" %c",&c);
            if (c == '#') continue;
            else if (c == 'S') q.push({i,j,0,1,0}),a[i][j] = 10;
            else if (c == '.') a[i][j] = 10;
            else if (c == 'G') a[i][j] = --cnt;
            else a[i][j] = c-'0';
        }
    }
    while (!q.empty()){
        t = q.front(); q.pop();
        int t1 = (t.t%6), t2 = ((t.t+1)%6);
        // printf("mem[%d][%d][%d][%d] = %d\n",t.x,t.y,t1+1,t.c,mem[t.x][t.y][t1][t.gem]);
        if (t.c == 7){
            printf("%d",mem[t.x][t.y][t.t][t.gem]);
            return 0;
        }
        for (i = 0; i < 5; i++){
            int X = t.x+x[i], Y = t.y+y[i];
            if (!a[X][Y]) continue;
            if (a[X][Y] < 0){ //G
                // printf("X = %d Y = %d ",X,Y);
                int t31 = t.gem & (1 << -a[X][Y]);
                int t32 = t.gem | (1 << -a[X][Y]);
                if (t31 && !mem[X][Y][t2][t.gem]){
                    mem[X][Y][t2][t32] = mem[t.x][t.y][t1][t.gem] + 1;
                    q.push({X,Y,t2,t32,t.c});
                }
                else if (!mem[X][Y][t2][t32]){
                    mem[X][Y][t2][t32] = mem[t.x][t.y][t1][t.gem] + 1;
                    q.push({X,Y,t2,t32,t.c+1});
                }
            }
            else if (a[X][Y] == 10 && !mem[X][Y][t2][t.gem]){
                mem[X][Y][t2][t.gem] = mem[t.x][t.y][t1][t.gem] + 1;
                q.push({X,Y,t2,t.gem,t.c});
            }
            else{
                if ((t2 == a[X][Y]-1 || t.c == a[X][Y]) && !mem[X][Y][t2][t.gem]){
                    mem[X][Y][t2][t.gem] = mem[t.x][t.y][t1][t.gem] + 1;
                    q.push({X,Y,t2,t.gem,t.c});
                }
            }
        }
    }
    printf("-1");
}