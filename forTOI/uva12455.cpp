#include <bits/stdc++.h>
using namespace std;
int t,w,n;
int i,j;
int p;

int main(){
    cin >> t;
    while (t--){
        cin >> w >> n;
        int dp[1005] = {};
        dp[0] = 1;
        for (i = 0; i < n; i++){
            cin >> p;
            for (j = w-p; j >= 0; j--){
                if (dp[j] && !dp[j+p])
                    dp[j+p] = 1;
            }
        }
//        for (i = 0; i <= 25; i++) printf("dp[%d]=%d\n",i,dp[i]);

        if (dp[w]) cout << "YES\n";
        else cout << "NO\n";
    }
}
