#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int n,t;
int cnt[N+2];
ll mem[N+2];
int main(){
    scanf("%d",&n);
    while (n--) scanf("%d",&t), ++cnt[t];
    mem[1] = cnt[1];
    for (ll i = 2; i <= N; i++) mem[i] = max(mem[i-1],mem[i-2]+cnt[i]*i);
    printf("%lld",mem[N]);
}