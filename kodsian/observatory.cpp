#include <bits/stdc++.h>
#define I first
#define II second
using namespace std;
using pii = pair<int,int>;
int m,n,k;
int i,j;
int a[2005][2005];
int sum[2005][2005];
int diag0[2005][2005],diag1[2005][2005]; // 0 '/' 1 '\'
int _max = INT_MIN;
int qsum(pii c1, pii c2) {
    if (c1.I > c2.I || c1.II > c2.II) return 0;
    return sum[c2.I][c2.II] - sum[c2.I][c1.II-1] - sum[c1.I-1][c2.II] + sum[c1.I-1][c1.II-1];
}
int diagsum(int x, int y, int c){
    if (c) return (y < n) ? diag1[x][y] : diag1[x][n];
    return (y > 0) ? diag0[x][y] : diag0[x][1];
}
int fun(int x, int y, int c) {
    if (c) return diag1[x][y] - qsum({x,1},{m,y-1}) - diagsum(x+k,y+k,1) + qsum({x+k,1},{m,y-1});
    return diag0[x][y] - qsum({x,y+1},{m,n}) - diagsum(x+k,y-k,0) + qsum({x+k,y+1},{m,n});
}
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
            sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for (i = m; i >= 1; i--){
        for (j = n; j >= 1; j--){ // 0 '/'
            if (j == 1) diag0[i][j] = a[i][j] + diag0[i][j+1];
            else if (j == n) diag0[i][j] = a[i][j] + diag0[i+1][j-1];
            else diag0[i][j] = a[i][j] + diag0[i][j+1] + diag0[i+1][j-1] - diag0[i+1][j];
        }
        for (j = 1; j <= n; j++){ // 1 '\'
            if (j == n) diag1[i][j] = a[i][j] + diag1[i][j-1];
            else if (j == 1) diag1[i][j] = a[i][j] + diag1[i+1][j+1];
            else diag1[i][j] = a[i][j] + diag1[i][j-1] + diag1[i+1][j+1] - diag1[i+1][j];
        }
    }

    for (i = 1; i <= m-k+1; i++){
        for (j = 1; j <= n-k+1; j++){ // '\'
            //  printf("%d ",fun(i,j,1));
             _max = max(_max,fun(i,j,1));
        }
        for (j = k; j <= n; j++) { // '/'
            // printf("%d ",fun(i,j,0));
            _max = max(_max,fun(i,j,0));
        }
        // cout << endl;
    }
    printf("%d",_max);
}