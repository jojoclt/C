#include <bits/stdc++.h>
using namespace std;
int cost[3],m,n,mem[105][105][4];
int tree[105][105];
struct node{
    int x,y,w,val;
    bool operator < (node p) const{
        return val > p.val;
    }
}t;
bool check(int x, int y){
    if (x >= 1 && x <= m && y >= 1 && y <= n) return 1;
    if (x == m && y == n+1) return 1;
    return 0;
}
priority_queue<node> pq;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int i,j,X,Y,V;
char tt;
int main(){
    fill(&mem[0][0][0],&mem[104][104][3],1e9);
    for (i = 0; i < 3; i++)
        scanf("%d",&cost[i]);
    scanf("%d%d",&n,&m);
    for (i = m; i > 0; i--){
        for (j = 1; j <= n; j++){
            scanf(" %c",&tt);
            if (tt == 'X') tree[i][j] = cost[2];
        }
    }
    pq.push({1,0,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (i = 0; i < 4; i++){
            if (i == 2) continue;
            j = (t.w+i)%4;
            X = t.x+x[j];
            Y = t.y+y[j];
            V = t.val+cost[(i%2)]+tree[X][Y];
            if (check(X,Y) && V < mem[X][Y][j]){
                mem[X][Y][j] = V;
                pq.push({X,Y,j,V});
                //printf("X %d Y %d j %d V %d\n",X,Y,j,V);
            }
        }
    }
    printf("%d",mem[m][n+1][0]-cost[0]);
}
