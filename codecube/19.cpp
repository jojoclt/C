#include <bits/stdc++.h>
using namespace std;
int _min;
int n,k,t;
int a[1005];
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 0; i < k; i++){
        for (int j = 1; j <= n-i-1; j++){
            _min = min(a[j-1] == a[j] ? 10000000 : a[j],a[j+1]);
            a[j] = _min;
        }
    }
    for (int i = 1; i <= n-k; i++) printf("%d ",a[i]);
}