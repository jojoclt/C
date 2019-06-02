#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
char c[1005];
int mem[1005][1005];
int ans[1005][1005];
vector <node> v;
int i,j,n;
int fun(int l, int r) {
    if (l >= r) return 0;
    if (mem[l][r]) return mem[l][r];
    mem[l][r] = max(fun(l+1,r),fun(l,r-1));
    if (c[l] == c[r]) mem[l][r] = max(mem[l][r],fun(l+1,r-1)+1);
    return mem[l][r];
}
int f(int x, int y){
    if (x == n) return 0;
    if (y == n) return -1e9;
    if (ans[x][y]) return ans[x][y];
    ans[x][y] = max(f(x,y+1),f(x+1,y));
    ans[x][y] = max(ans[x][y],mem[x][y] + f(y+1,y+1));
    return ans[x][y];

}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf(" %c",c+i);
    }
    fun(0,n-1);
    // for (i = 0; i < n; i++){
    //     for (j = 0; j < n; j++){
    //         if (mem[i][j]) printf("mem[%d][%d] = %d\n",i,j,mem[i][j]);
    //     }
    // }
    cout << f(0,0);
}