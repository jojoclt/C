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
        printf("\n");
        // cout << k <<endl;
        lis[k+1] = a[i];
        sum[k+1] = sum[k] + a[i];
        len = max(len,k+1);
        // for (int i = 0; i < len; i++) printf("%d ",lis[i]);
    }
    printf("%d %lld\n",len,sum[len]);
    
}

// 7
// 2 3 5 5 4 4 1