#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}t;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};
bool a[1005][1005];
int m,n;
int i,j;
int st,diag,tri;
char c;
queue <node> q;
bool check(int x, int y){
    if (x >= 0 && y >= 0 && x <= 1000 && y <= 1000) return 1;
    return 0;
}
int fun(int x){
    return x*x;
}
node fillst(int t1, int t2){
    node c = {100000,0,0};
    q.push({t1,t2});
    while (!q.empty()){
        t = q.front(); q.pop();
        c.x = min(c.x,t.x);
        c.y = max(c.y,t.x);
        if (a[t.x][t.y] == false) continue;
        a[t.x][t.y] = false;
        ++c.z;
        for (int i = 0; i < 4; i++){
            int X = t.x+x[i], Y = t.y+y[i];
            if (check(X,Y) && a[X][Y]) q.push({X,Y});
        }
    }
    return c;
}
int main(){
    scanf("%d%d",&n,&m);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf(" %c",&c);
            if (c == '1') a[i][j] = true;
            else a[i][j] = false;
        }
    }
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (a[i][j]){
                if (a[i+1][j] && a[i][j+1]){
                    // printf("1:%d %d\n",i,j);
                    ++st;
                    fillst(i,j);
                }
                else if (check(i+1,j-1) && check(i+1,j+1) && a[i+1][j-1] && a[i+1][j+1]){
                    t = fillst(i,j);
                    // printf("(%d)\n",t.z);
                    // printf("t.y = %d t.x = %d\n",t.y,t.x);
                    if (fun(t.y-t.x+1) == t.z){
                        ++tri;
                        // printf("3.2:%d %d\n",i,j);
                    }
                    else{
                        ++diag;
                        // printf("2:%d %d\n",i,j);
                    }
                }
                else{
                    // printf("3:%d %d\n",i,j);
                    ++tri;
                    fillst(i,j);
                }
            }
        }
    }
    printf("%d %d %d",st,diag,tri);
}