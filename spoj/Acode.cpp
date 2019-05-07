#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int i,n,t1,t2;
char s[5005];
ll dp[5005];
int main(){
    while (scanf("%s",s), s[0] != '0'){
        dp[0] = dp[1] = 1; n = strlen(s);
        for (i = 2; i <= n; i++){
            dp[i] = 0;
            t1 = s[i-2]-'0', t2 = s[i-1]-'0';
            if (t2) dp[i] = dp[i-1];
            if (t1 == 1 || (t1 == 2 && t2 <= 6)) dp[i] += dp[i-2];
        }
        printf("%lld\n",dp[n]);
    }
}