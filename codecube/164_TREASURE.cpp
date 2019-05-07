#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum = 1e17,mid,_left,_right,t1,t2;
int a[123458],l,r;
ll arr[123458];
int n,i,j;
ll rng(int x, int y) {return arr[y]-arr[x-1];}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        arr[i] = a[i] + arr[i-1];
        mid += a[i];
    }
    if (n <= 100){
        for (i = 1; i < n; i++){
            for (j = i+2; j <= n; j++){
                sum = min(sum, max({rng(1,i),rng(i+1,j-1),rng(j,n)}) - min({rng(1,i),rng(i+1,j-1),rng(j,n)}));
            }
        }
        printf("%lld",sum);
        return 0;
    }
    l = 1, r = n;
    _left = a[l], _right = a[r];
    mid -= a[l++] + a[r--];
    while (l <= r){
        sum = min(sum, max({mid,_left,_right}) - min({mid,_left,_right}));
        if (_left + a[l] < _right + a[r]){
            mid -= a[l];
            _left += a[l++];
        }
        else{
            mid -= a[r];
            _right += a[r--];
        }
    }
    printf("%lld",sum);
}

// 7 1 3 8 6 2 3 1