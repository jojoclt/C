#include <bits/stdc++.h>
using namespace std;
int n,a[105][105];
int i,j,k,sum = -1e9,t;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
            a[i][j] += a[i][j-1];
        }
    }
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            for (k = 1; k <= n; k++){
                t += a[k][j] - a[k][i-1]; // like maxsum 1d
                sum = max(sum,t);
                if (t < 0) t = 0;
            }
            t = 0;
        }
    }
    printf("%d",sum);
}
