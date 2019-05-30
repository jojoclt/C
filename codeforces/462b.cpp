#include <bits/stdc++.h>
using namespace std;
int n,k,i;
char t;
int a[26];
int sum,ans;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf(" %c",&t);
        ++a[t-'A'];
    }
    sort(a,a+26);
    for (i = 25; i >= 0; i--){
        if (sum + a[i] <= k){
            sum += a[i];
            ans += a[i]*a[i];
        }
        else {
            ans += a[i] * (k-sum);
        }
    }
    printf("%d",ans);
}