#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
int i,j,t,low;
long long cnt;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        a[t%k]++;
    }
    cnt += a[0]/2*2;
    for (i = 1; i < k; i++){
        if (i < k-i) cnt += min(a[i],a[k-i])*2;
        else if (i == k-i) cnt += a[i]/2*2;
    }
    printf("%d",cnt);
}