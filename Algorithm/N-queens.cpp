#include <bits/stdc++.h>
using namespace std;
int cnt,n;
bool col[10],diag1[10],diag2[10];
void search(int y){
    if (y == n){
        cnt++;
        return;
    }
    for (int x = 0; x < n; x++){
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = true;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}
int main(){
    n = 4;
    search(0);
    cout << cnt;
}