#include <bits/stdc++.h>
using namespace std;
int mem[1005][3005],a[1005];
int n,i,j,t;
int tasty(int x, int y){
//    cout << x << " " <<val<<endl;
    if (mem[x][y]) return mem[x][y];
    if (x == n) return 0;
    if (y > 3000) return mem[x][y] = 1e9;
    else {
        mem[x][y] = tasty(x+1,y+1) + 1;
        if (a[x] > y) mem[x][y] = min(mem[x][y],tasty(x+1,a[x]));
    }
    return mem[x][y];

}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    cout << tasty(0,0);

}
