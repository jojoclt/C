#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}t;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int m,n,cnt,amo;
int i,j;
int way[2005][2005];
int mem[2005][2005];
char c;
queue <node> q;
int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&c);
            if (c == 'E') way[i][j] = 1;
            else if (c == 'A') way[i][j] = 2;
            else if (c == 'X') q.push({i,j});
        }
    }
    while (!q.empty()){
        t = q.front(); q.pop();
        if (way[t.x][t.y] == 2){
            amo++;
            cnt += mem[t.x][t.y];
        }
        for (i = 0; i < 4; i++){
            int X = t.x+x[i], Y = t.y+y[i];
            if (!mem[X][Y] && way[X][Y]){
                mem[X][Y] = mem[t.x][t.y]+1;
                q.push({X,Y});
                // printf("%d %d\n",X,Y);
            }
        }
    }
    
    printf("%d %d",amo,cnt*2);
}