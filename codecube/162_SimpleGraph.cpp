#include <bits/stdc++.h>
using namespace std;
int T,n,i,j,a[100005],cnt;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            cnt += a[i];
        }
        sort(a,a+n,cmp);
        // for (i = 0; i < n; i++) cout << a[i] << " ";
        for (i = 0; i < n-1; i++){
            for (j = i+1; j <= i+a[i]; j++)
                a[j]--;
            // a[i] = 0;

        }
        if (a[n-1] || (cnt%2) || cnt <= n) cout <<"No\n";
        else cout <<"Yes\n";
    }
}   