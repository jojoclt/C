#include <bits/stdc++.h>
using namespace std;
int n,t,i,a[5],cnt,c;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&t),a[t]++;
    cnt += a[4];
    if (a[3]){
        a[1] -= a[3];
        if (a[1] < 0) a[1] = 0;
        cnt += a[3];
    }
    cnt += a[2]/2;
    a[2] %= 2;
    if (a[2]){
        if (a[1] - 2 >= 0) cnt++;
        a[1] -= 2;
    }
    cnt += a[1]/4;
    if (a[1]%4) cnt++;
    cout << cnt;
}