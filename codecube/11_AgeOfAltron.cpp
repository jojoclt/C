#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int i,j;
int seat[1005][1005],t;
int vac[1005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            scanf("%d",&t);
            seat[i][j] = 1;
            if (!t){
                seat[i][j] = 0;
                vac[i]++;
            }
            seat[i][j] += seat[i][j-1];
        }
    }
    for (i = n; i > 0; i--){
        vac[i] += vac[i+1];
        if (vac[i] >= k){
            for (j = k; j <= m; j++){

                //cout << seat[i][j]-seat[i][j-k]+vac[i]<<endl;
                if (seat[i][j]-seat[i][j-k]<=vac[i+1]){
                    printf("%d",i);
                    return 0;
                }
            }
        }
    }
}
