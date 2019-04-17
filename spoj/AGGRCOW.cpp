#include <bits/stdc++.h>
using namespace std;
int i,t;
int l,r,mid,last,cow,ans;
int T,n,k;
int v[100005];
bool fun(int x){
    last = v[0], cow = 1;
    for (i = 1; i < n; i++){
        if (v[i] - last >= x){
            if (++cow == k) return 1;
            last = v[i];
        }
    }
    return 0;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&k);
        for (i = 0; i < n; i++){
            scanf("%d",&v[i]);
        }
        sort(v,v+n);
        l = 0; r = v[n-1]-v[0];
        while (l <= r){
            mid = l + r >> 1;
            if (fun(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        printf("%d\n",ans);
    }
}