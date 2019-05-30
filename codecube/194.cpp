#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int i,n,len;
int a[N],lis[N];
long long sum[N];
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (i = n; i > 0; --i){
        int k = upper_bound(lis+1,lis+len+1,a[i],greater<int>())-1 - lis;
        // cout << k <<endl;
        lis[k+1] = a[i];
        sum[k+1] = sum[k] + a[i];
        len = max(len,k+1);
    }
    printf("%d %lld\n",len,sum[len]);
    
}