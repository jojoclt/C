#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 3e5+1;
int n,a[2][N];
ll s[2],fr[2][N],bk[2][N];
int i,j,c = 1;
int main(){
    scanf("%d",&n);
    for (i = 0; i < 2; i++)
        for (j = 0; j < n; j++)
            scanf("%d",&a[i][j]), s[i] += a[i][j];
    
}
