#include <bits/stdc++.h>
// B O N U
using namespace std;
int n,i;
char c[1000];
int mem[1005][1005];
int magic(int l, int r){
    int cnt;
    if (l >= r) return 0;
    if (mem[l][r]) return mem[l][r];
    cnt = max(magic(l,r-1),magic(l+1,r));
    if (c[l] == c[r]){
        cnt = max(cnt,magic(l+1,r-1)+1);
        cout << l << " " << r << " " << cnt <<endl;
    }
    return mem[l][r] = cnt;
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&c[i]);
    cout << magic(0,n-1);
}