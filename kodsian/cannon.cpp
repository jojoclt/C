#include <bits/stdc++.h>
using namespace std;
int n,m,k,l;
int a[1000005],t;
int L,R;
int i,j,cnt;
int search(int k){
    int l = 0,r = n-1,mid;
    while (l <= r){
        mid = (l+r)>>1;
        if (a[mid] > k) r = mid-1;
        else l = mid+1;
    }
    return r;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&l);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < k; i++){
        cnt = 0;
        L = R = INT_MIN;
        for (j = 0; j < m; j++){
            scanf("%d",&t);
            L = max(R,t-l-1);
            R = t+l;
            int t1 = search(L);
            int t2 = search(R);
            cnt += t2-t1;
        }
        printf("%d\n",cnt);
    }
}
/*

3 1 1 2
1 2 6
2 

2

3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001 

2
1
3
0
*/