#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
ull n,k,a[1000005],l=0,r=1e19,mid,i;
bool t1,t2,t3;
bool f(ull x){
    ull c = 0;
    for (i = 0; i < n; i++){
        c += (ull) x/a[i];
        if (c >= k) return 1;
    }
    return 0;
}
int main(){
    scanf("%llu%llu",&n,&k);
    for (i = 0; i < n; i++) scanf("%llu",&a[i]);
    sort(a,a+n);
    while (l <= r){
        mid = (l + r)>>1LL;
        t1 = f(mid-1), t2 = f(mid);
        if (!t1 && t2) {
            printf("%llu",mid);
            return 0;
        }
        else if (t1 && t2) r = mid-1;
        else l = mid+1;
    }
}