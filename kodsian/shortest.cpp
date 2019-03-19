#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int a,b;
int i,j,k;
int n;
int mem[105][105],high;
float ans,cnt;
int main(){
    fill(&mem[0][0],&mem[102][102],1e9);
    while (scanf("%d%d",&a,&b),a&&b){
        mem[a][a] = mem[b][b] = 0;
        mem[a][b] = 1;
        high = max(high,max(a,b));
    }

    for (k = 1; k <= high; k++){
        for (i = 1; i <= high; i++){
            for (j = 1; j <= high; j++){
                mem[i][j] = min(mem[i][j],mem[i][k]+mem[k][j]);
            }
        }
    }
    for (i = 1; i <= high; i++){
        for (j = 1; j <= high; j++){
            if (mem[i][j] != 1e9 && mem[i][j]){
                cnt++;
                ans += mem[i][j];
            }
        }
    }
    cout << fixed << setprecision(3) << ans/cnt;
    return 0;
}