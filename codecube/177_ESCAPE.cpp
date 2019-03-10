#include <bits/stdc++.h>
using namespace std;
struct axis{
    int x,y;
}t;
bool a[1005][1005];
int mem[1005][1005],X,Y;
axis T[] = {{0,1},{1,0}};
int m,n,i,j;

queue <axis> q;
int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
            a[i][j] = !a[i][j];
        }
    }
    q.push({1,1});
    mem[1][1] = 1;
    while(!q.empty()){
        t = q.front(); q.pop();
        for (i = 0; i < 2; i++){
            X = t.x+T[i].x, Y = t.y+T[i].y;
            if (a[X][Y]){
                if (!mem[X][Y]) q.push({X,Y});
                mem[X][Y] += mem[t.x][t.y]%1000000007;
            }
        }
    }
//    for (i = 1; i <= m; i++){
//        for (j = 1; j <= n; j++)
//            printf("%d ",mem[i][j]);
//        cout<<endl;
//    }
    printf("%d",mem[m][n]);
}
