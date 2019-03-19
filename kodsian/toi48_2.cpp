#include<bits/stdc++.h>
using namespace std;
int n,k,i,j;
int p[5005],w[5005];
int dp[1880];
int main(){
    scanf("%d%d",&n,&k);
    k /= 8;
    for (i = 0; i < n; i++) scanf("%d",&p[i]);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);
    dp[0] = 0;
    for (i = 0; i < n; i++){
        for (j = k; j >= 0; j--){
            if (j - w[i] < 0) continue;
            dp[j] = max(dp[j],dp[j-w[i]]+p[i]);
        }
    }
    cout << dp[k];
}