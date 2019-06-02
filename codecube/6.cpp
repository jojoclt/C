#include <bits/stdc++.h>
using namespace std;
int i;
int p0[500005],p1[500005];
int n,t;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        if (i%2) scanf("%d",&p1[(i>>1)+1]);
        else scanf("%d",&p0[i>>1])
    }
}