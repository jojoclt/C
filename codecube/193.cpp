#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using pii = pair<int,int>;
using ll = long long;

const int N = 1e5+1;
const ll INF = 1e18;
int i;
int n,k;
pii res[N];
ll x[N],c[N],dp[N];

int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%d%d",&res[i].x,&res[i].y);
    sort(res+1,res+n+1);
    for (i = 1; i <= n; i++) x[i] = res[i].x, c[i] = res[i].y;
}