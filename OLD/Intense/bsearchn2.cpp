#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,n,a[1000],key,mid;
    scanf("%d%d",&n,&key);
    int l = 0, r = n-1,ans;

    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(&a[0],&a[n]);
    while(l <= r){
        mid = l+r >> 1;
        if (a[mid] < key){
            ans = a[mid];
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d",ans);
}
