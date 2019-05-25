#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int i,t,c;
int n;
int a[100005],a2[100005],arr[100005];
int rnk[100005];ll s[100005];
ll sum;
unordered_map <int,int> m;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++){
        if (a[i] >= t){
            arr[c++] = a[i];
            t = a[i];
        }
        else {
            int c1 = upper_bound(arr,arr+c,a[i]) - arr;
            arr[c1] = a[i];
        }
    }
    printf("%d %lld",c,sum);
}