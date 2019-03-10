#include <bits/stdc++.h>
using namespace std;
unordered_map <int,vector<int>> v;
int n,q;
int i,j,t1,t2,t3;
int main(){
    scanf("%d%d",&n,&q);
    for (i = 1; i <= n; i++){
        scanf("%d",&t1);
        v[t1].push_back(i);
    }
    for (i = 1; i <= q; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        auto x = lower_bound(v[t3].begin(),v[t3].end(),t1);
        auto y = upper_bound(v[t3].begin(),v[t3].end(),t2)-1;
        printf("%d\n",(int)(y-x+1));
    }
}
