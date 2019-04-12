#include <bits/stdc++.h>
using namespace std;
int i,j;
int n,m;
int a[1005][2],mem[1005][1005];
int val = 1e9;
int f(int x, int y, int v){
    if (x == n+1 && y == n+1) return 0;
    if (x > n+1 || y > n+1) return 1e9;
    if (mem[x][y]) return mem[x][y];
    mem[x][y] = min(f(x+1,y,a[x][0]),f(x,y+1,a[y][1]))+1;
    //mem[x][y] =
    return mem[x][y];
}
int main(){
    scanf("%d%d",&m,&n);
    for (i = 0; i < 2; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&a[j][i]);
        }
    }
    cout << f(1,1,0);
}