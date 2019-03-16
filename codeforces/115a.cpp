#include <bits/stdc++.h>
using namespace std;
int n,i,cnt,ans;
int a[2005];
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (i = 1; i <= n; i++){
        int x = a[i];
        cnt = 0;
        while (x != -1){
            x = a[x];
            cnt++;
        }
        ans = max(cnt,ans);
    }
    printf("%d",ans+1);
}