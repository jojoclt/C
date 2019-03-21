#include <bits/stdc++.h>
using namespace std;
int l,n;
int i,j;
int A[55];
int mem[55][55];
int cut(int left, int right){
    if (left+1 == right) return 0;
    int ans = 2e9;
    for (int i = left+1; i < right; i++){
        // cout << left << " " << right << " "<< A[right]-A[left]<<" "<<ans<<endl;
        ans = min(ans,cut(left,i) + cut(i,right) + (A[right]-A[left]));
    }
    return ans;

}
int main(){
    while(scanf("%d",&l), l){
        scanf("%d",&n);
        A[0] = 0;
        for (i = 1; i <= n; i++) scanf("%d",&A[i]);
        A[n+1] = l;

        memset(mem,-1,sizeof(mem));
        printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }
}
