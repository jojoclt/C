#include <bits/stdc++.h>
using namespace std;
int i,j;
int a[55];
int solve(int x, int zz){
    map<int,bool>mp1;
    map<int,int> mp2;S
    int num = 0;
    for (int i = 0; i < n; i++){
        int z = sum[i]-x;
        if (mp1[z]){
            if(zz)
                printf("%d %d\n",mp2[z]+1,i);
            num++;
            mp1.clear();
        }
        mp1[sum[i]] = true;
        if(zz)
            mp2[sum[i]]=i;
    }
    return num;
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]), a[i] += a[i-1];
    int ans = 0,x,y;
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            int zz = solve(sum[j]-sum[i-1],0);
            if (ans < zz) {
                ans = zz;
                x = i, y = j;
            }
        }
    }
    printf("%d\n",ans);
    ans = solve(sum[y]-sum[i-1],1);
}