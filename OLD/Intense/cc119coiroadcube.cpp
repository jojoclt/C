#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,c;
int a[105][10005];
int mem[105][10005];
int cube(int x, int y){
    if (mem[x][y]) return mem[x][y];
    if (x == 0) return 0;
    else{
        for (i = max(y-k,1); i <= min(y+k,m); i++){
            mem[x][y] = max(mem[x][y],cube(x-1,i)+a[x][y]);
        }
    }
    return mem[x][y];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);
    for (j = 1; j <= m; j++)
        c = max(c,cube(n,j));
    printf("%d\n",c);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
}

/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
