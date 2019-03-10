#include <bits/stdc++.h>
#define b(x,i) cout << bitset<i>(x) << "\n"
using ll = long long;
using namespace std;

const int N = 1e5;
int a[N];
int mem[N][100];
int n,k;
int i;
void check(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            printf("mem[%d][%d] = %d\n",i,j,mem[i][j]);
        }

        printf("\n");
    }
}
int f(int x, int y){
    if (x == n){
        if (y == k) return 0;
        return -1;
    }
    if (mem[x][y]) return mem[x][y];
    ll t1 = a[x] | f(x+1,y), t2 = f(x+1,y+1);
    b(t1,4); b(t2,4); cout << endl;
    if (t1 != -1 && mem[x][y] < t1) mem[x][y] = t1;
    if (t2 != -1 && mem[x][y] < t2) mem[x][y] = t2;
    return mem[x][y];
}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) cin >> a[i];
    cout << f(0,0) << "\n";
    // check();

}