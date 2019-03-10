#include <bits/stdc++.h>
using namespace std;
int n,t,i,l,r,mid,a[1000005],sum,high = -1e9,tmp1,tmp2;
int calc(int c){
    int x = 0,y = 0;
    for (i = 1; i <= n; i++){
        if (x < a[i]){
            x = c-a[i];
            y++;
        }
        else{
            x -= a[i];
        }
    }
    return y;
}
int main(){
    scanf("%d%d",&n,&t);
    for (i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    if (t == 1){
        printf("-1");
        return 0;
    }
    for (i = 1; i <= n; i++){
        sum += a[i];
        if (high < a[i])
            high = a[i];
    }
    l = high,r = 1e9;

    while (l <= r){
        mid = l + r >> 1;
        if (calc(mid) < t) r = mid-1;
        else if (calc(mid)==t && calc(mid-1)==t) r = mid-1;
        else if (calc(mid) > t) l = mid+1;
        else break;
    }
    tmp1 = mid;
    l = high, r = 1e9;
    while (l <= r){
        mid = l + r >> 1;
        if (calc(mid) > t) l = mid+1;
        else if (calc(mid)==t && calc(mid+1)==t) l = mid+1;
        else if (calc(mid) < t) r = mid-1;
        else bre  ak;
    }
    tmp2 = mid;
    printf("%d",tmp2-tmp1+1);
}
