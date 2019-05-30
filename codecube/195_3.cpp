#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[700005];
int sum[700005];
int i,t;
int func(int k){
    int l = 1, r = n, mid;
    while (l <= r){
        mid = (l+r)>>1;
        if (sum[mid] >= k) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main(){
    scanf("%d%d",&n,&q);
    for (i = 1; i <= n; i++) scanf("%d",a+i);
    sort(a+1,a+n+1);
    for (i = 1; i <= n; i++) sum[i] = sum[i-1] + (a[i]-a[i-1]-1);
    // for (i = 1; i <= n; i++) printf("%d ",sum[i]);
    // return 0;
    while (q--){
        scanf("%d",&t);
        printf("%d ",t+func(t)-1);
    }
}