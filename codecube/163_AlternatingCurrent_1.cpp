#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n,k,t;
int a[100005];
int i,low = inf,high = -inf;
int cnt;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        a[t]++;
        high = max(high,t);
        low = min(low,t);
    }
    while (high - low > k){
        if (!a[high]) high--;
        else if (!a[low]) low++;
        else{
            if (a[high] == a[low]){
                cnt += a[high];
                a[high-1] += a[high]; a[high] = 0;
                a[low+1] += a[low]; a[low] = 0;
                high--; low++;
            }
            else if (a[high] > a[low]){
                cnt += a[low];
                a[high] -= a[low];
                a[high-1] += a[low];
                a[low+1] += a[low]; a[low] = 0;
                low++;
            }
            else if (a[high] < a[low]){
                cnt += a[high];
                a[low] -= a[high];
                a[low+1] += a[high];
                a[high-1] += a[high]; a[high] = 0;
                high--;
            }
        }

    }
    printf("%d",cnt);
}
