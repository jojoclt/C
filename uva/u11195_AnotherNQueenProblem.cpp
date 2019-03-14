#include <bits/stdc++.h>
using namespace std;
int cnt,n,i,j;
bool col[16],diag1[16],diag2[16];
bool wall[16][16];
char c;
void search(int y){
    if (y == n){
        cnt++;
        return;
    }
    for (int x = 0; x < n; x++){
        if (col[x] || diag1[x+y] || diag2[x-y+n-1] || wall[x][y]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            scanf(" %c",&c);
            if (c == '*') wall[i][j] = true;
        }
    search(0);
    cout << cnt;
}