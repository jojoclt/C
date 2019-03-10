#include <iostream>
using namespace std;
int n,k;
int i,j,l,r;
int mem[1005][305],a[1005];
int sum(int x, int y){
    return a[y] - a[x-1];
}

int f(int x, int c){
    if (x == n+1 && c == k+1) return 0;
    if (x > n+1 || c > k+1) return 1e9;
    if (mem[x][c]) return mem[x][c];
    mem[x][c] = 1e9;
    for (int i = x; i <= n-(k-c); i++){
        mem[x][c] = min(mem[x][c],max(f(i+1,c+1),sum(x,i)));
    }
    return mem[x][c];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    cout << f(1,1);

}
