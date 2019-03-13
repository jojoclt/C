#include <iostream>
using namespace std;
using ll = long long;
ll n,c;
ll k,l,r,mid;
int main(){
    scanf("%lld%lld",&n,&k);
    if (k%2){
        printf("1");
        return 0;
    }
    else{
        ll c = 1ll << n;
        l = 1, r = c-1;
        while (l <= r){
            mid = l+r>>1ll;
            if (mid == k){
                printf("%lld",n);
                return 0;
            }
            else if (mid > k) r = mid-1,n--;
            else l = mid+1,n--;
        }
    }
}