#include <bits/stdc++.h>
using namespace std;
int mem[1005][1005];
char c[1005];
int n;
int i,j_max;
int fun(int l, int r){
    if (l >= r) return 0;
    if (mem[l][r]) return mem[l][r];
    if (c[l] == c[r]) mem[l][r] = max(mem[l][r],fun(l+1,r-1)+1);
    else for (int i = l; i < r-1; i++) mem[l][r] = max(mem[l][r],fun(l,i)+fun(i+1,r));
    return mem[l][r];
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf(" %c",&c[i]);
    // printf("%d",fun(1,n));
    for (i = 1; i <= n; i++){
        for (int l = 1; l <= n-i; l++){
            int r = l+i;
            if (c[l] == c[r]) mem[l][r] = max(mem[l][r],mem[l+1][r-1]+1);
            else for (int k = l; k <= r-1; k++) mem[l][r] = max(mem[l][r],mem[l][k]+mem[k+1][r]);
        }
    }
    printf("%d",mem[1][n]);
}