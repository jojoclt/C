#include <bits/stdc++.h>
using namespace std;
int n,i,j;
int mem[505][505];
string s;
int f(int l, int r){
    int cnt;
    if (l > r) return 0;
    if (l == r) return 1;
    if (mem[l][r]) return mem[l][r];
    cnt = f(l+1,r) + 1;
    for (int k = l+1; k <= r; k++){
        if (s[l] == s[k])
        cnt = min(cnt,f(l+1,k-1)+f(k,r));
    }
    return mem[l][r] = cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    cout << f(0,n-1);
}