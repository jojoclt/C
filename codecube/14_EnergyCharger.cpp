#include <bits/stdc++.h>
using namespace std;
int n,key,a[1000005];
int i,c,val,mid,high;
int ans1,ans2;
int l = -1e9, r = 1e9;
int bsearch(int mid){
    c = val = 0;
    for (i = 0; i < n; i++){
        if (mid < a[i]) return 0;
        if (val < a[i]){
            val = mid;
            c++;
        }
        if (val >= a[i]){
            val -= a[i];
        }
    }
    return c;
}
int main(){
    scanf("%d%d",&n,&key);
    if (key == 1){
        printf("-1");
        return 0;
    }
    for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
        high = max(high,a[i]);
    }
    l = high, r = 1e9;
    while (l <= r){
        mid = l+r>>1;
        if (bsearch(mid) > key) l = mid+1;
        else if (bsearch(mid) == key && bsearch(mid-1) == key) r = mid-1;
        else if (bsearch(mid) < key) r = mid-1;
        else break;
    }
    ans1 = mid;
    l = high, r = 1e9;

    while (l <= r){
        mid = l+r>>1;
        if (bsearch(mid) > key) l = mid+1;
        else if (bsearch(mid) == key && bsearch(mid+1) == key) l = mid+1;
        else if (bsearch(mid) < key) r = mid-1;
        else break;
    }
    ans2 = mid;
    printf("%d",ans2-ans1+1);
}
