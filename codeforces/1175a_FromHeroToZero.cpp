#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int T;
ll t;
ll n,k;
int main(){
    scanf("%d",&T);
    while (T--){
        ll cnt = 0;
        scanf("%lld%lld",&n,&k);
        while (n){
            t = n%k;
            if (t){
                n -= t;
                cnt += t;
            }
            else {
                n /= k;
                ++cnt;
            }
        }
        printf("%lld\n",cnt);
    }    
}