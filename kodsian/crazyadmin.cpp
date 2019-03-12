#include <bits/stdc++.h>
using namespace std;
int amo,n,mx;
int a[105];
int mem[105][25];
int f(int x, int y){
    if (x == n && y <= amo) return 0;
    if (y > amo) return 1e9;
    if (mem[x][y]) return mem[x][y];
    mem[x][y] = 1e9;
    int cnt = 0;
    for (int i = x; i < n; i++){
        cnt += a[i];
        mem[x][y] = min(mem[x][y],max(cnt,f(i+1,y+1)));
    }
    return mem[x][y];
}
int main(){
    cin >> amo >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (amo >= n){
        for (int i = 0; i < n; i++) mx = max(mx,a[i]);
        cout << mx;
        return 0;
    }
    cout << f(0,0);
}