#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,w,c;
}t;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int i,j,X,Y;
queue <node> q;
int m,n,ex,ey,cnt;
bool a[30][30],k;
int mem[30][30][5][5];
char cc;
int main(){
//    freopen("i10047.txt","r",stdin);
//    freopen("o10047.txt","w",stdout);
    while(cin >> m >> n){
        if (m && n && cnt) printf("\n");
        if (!m && !n) return 0;
        memset(mem,0,sizeof(mem));
        memset(a,false,sizeof(a));
        while (!q.empty())q.pop();
        k = false;

        printf("Case #%d\n",++cnt);
        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                scanf(" %c",&cc);
                if (cc == 'S'){
                    a[i][j] = 1;
                    q.push({i,j,0,0});
                }
                else if (cc == 'T'){
                    a[i][j] = 1;
                    ex = i; ey = j;
                }
                else a[i][j] = (cc == '#')?0:1;
            }
        }

        while(!q.empty()){
            t = q.front(); q.pop();
//            printf("mem[%d][%d][%d][%d] = %d\n",t.x,t.y,t.w,t.c,mem[t.x][t.y][t.w][t.c]);
            if (t.x == ex && t.y == ey && !t.c){
                k = true;
                printf("minimum time = %d sec\n",mem[t.x][t.y][t.w][t.c]);
                break;
            }
            X = t.x+x[t.w]; Y = t.y+y[t.w];
            if (a[X][Y] && !mem[X][Y][t.w][(t.c+1)%5]){
                mem[X][Y][t.w][(t.c+1)%5] = mem[t.x][t.y][t.w][t.c]+1;
                q.push({X,Y,t.w,(t.c+1)%5});
            }
            if (!mem[t.x][t.y][(t.w+3)%4][t.c]){
                mem[t.x][t.y][(t.w+3)%4][t.c] = mem[t.x][t.y][t.w][t.c]+1;
                q.push({t.x,t.y,(t.w+3)%4,t.c});
            }
            if (!mem[t.x][t.y][(t.w+1)%4][t.c]){
                mem[t.x][t.y][(t.w+1)%4][t.c] = mem[t.x][t.y][t.w][t.c]+1;
                q.push({t.x,t.y,(t.w+1)%4,t.c});
            }
        }
        if (!k) printf("destination not reachable\n");
    }
}
