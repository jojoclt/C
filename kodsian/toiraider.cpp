#include <bits/stdc++.h>
using namespace std;
int x[] = {-1,-1,1,1,0,0};
int y[][6] = {{0,1,0,1,1,-1},
            {-1,0,-1,0,-1,1}};
struct node{
    int x,y,val;
}t;
int i,j,p,X,Y,V;
int m,n;
int a[105][105];
bool K;
bool check(int x, int y){
    if (x >= 0 && y >= 1 && x <= m-1 && y <= n) return 1;
    return 0;
}
bool divis(int x, int y){
    if (x%y) return 0;
    return 1;
}
void god(){
    printf("a[%d][%d] = %d val = %d\n",X,Y,a[X][Y],t.val+1);
}
queue <node> q;
int main(){
    scanf("%d%d",&m,&n);
    for (i = 0; i < m; i++)
        for (j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
    p = (m-1)/2;
    q.push({p,0,0});
    while (!q.empty()){
        t = q.front(); q.pop();
        // printf("x = %d y = %d val = %d\n",t.x,t.y,t.val);
        if (t.x == p && t.y == n){
            printf("%d",t.val);
            return 0;
        }
        K = false; V = t.val+1;
        if (a[t.x][t.y] == 1){
            for (i = 0; i < 6; i++){
                X = t.x+x[i], Y = t.y+y[(t.x+1)%2][i];
                if (check(X,Y) && a[X][Y] > 1 && divis(V,a[X][Y])){
                    K = true;
                    god();
                    q.push({X,Y,V});
                }
            }
            if (K) continue;
        }
        for (i = 0; i < 6; i++){
            X = t.x+x[i], Y = t.y+y[(t.x+1)%2][i];
            if (check(X,Y) && a[X][Y] && divis(V,a[X][Y])){
                god();
                q.push({X,Y,V});
            }
        }
    }
}
