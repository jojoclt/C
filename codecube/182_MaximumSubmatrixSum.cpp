#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int i,j;
ll a[100005];
int n,w,h;
ll ans = 0,t = 0;
ll sum(int x, int y){
    return a[y]-a[x-1];
}
int main(){
    scanf("%d%d%d",&n,&w,&h);
    for (j = 0; j < 2; j++){
        t = 0;
        for (i = 1; i <= n; i++) scanf("%lld",&a[i]), a[i]+=a[i-1];
        for (i = 1; i <= n; i++){
            if (!j && i+w-1 <= n) t = max(t,1ll*h*sum(i,i+w-1));
            else if (j && i+h-1 <= n) t = max(t,1ll*w*sum(i,i+h-1));
            else break;
        }
        ans += t;
    }
    printf("%lld",ans);
}
/*
8 2 4
1 9 8 3 4 5 6 4
9 5 2 5 1 8 8 2
*/