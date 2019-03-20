#include <bits/stdc++.h>
// B O N U
using namespace std;
int n,i;
char c[1000];
int mem[1005][1005];
int f(int l, int r){
    int cnt;
    if (l >= r) return 0;
    if (mem[l][r]) return mem[l][r];
    cnt = f(l+1,r);
    for (int k = l+1; k <= r; k++){
        if (c[l] == c[k])
        cnt = max(cnt,f(l+1,k)+f(k+1,r)+1);
    }
    return mem[l][r] = cnt;
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&c[i]);
    cout << f(0,n-1);
}