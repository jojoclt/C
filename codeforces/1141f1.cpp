#include <bits/stdc++.h>
using namespace std;
int i,j;
int a[55],n;
int solve(int x, int zz){
    map<int,bool>mp1;
    map<int,int> mp2;
    int num = 0;
    for (int i = 1; i <= n; i++){
        int z = a[i]-x;
        if (mp1[z]){
            if(zz)
                printf("%d %d\n",mp2[z]+1,i);
            num++;
            mp1.clear();
        }
        mp1[a[i]] = true;
        if(zz)
            mp2[a[i]]=i;
    }
    return num;
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]), a[i] += a[i-1];
    int ans = 0,x,y;
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            int zz = solve(a[j]-a[i-1],0);
            if (ans < zz) {
                ans = zz;
                x = i, y = j;
            }
        }
    }
    printf("%d\n",ans);
    ans = solve(a[y]-a[x-1],1);
}