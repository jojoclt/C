#include <bits/stdc++.h>
using namespace std;
multiset <int> s[1001];
int n,q;
int i,j,inp,t1,t2,ans;
int main(){
    scanf("%d%d",&n,&q);
    for (i = 0; i < n; i++){
        ans = 0;
        scanf("%d",&inp);
        for (j = 0; j < inp-1; j++){
            scanf("%d%d",&t1,&t2);
            ans += (t1+t2)*(t1+t2);
        }
        s[inp].insert(ans);
    }
    for (i = 0; i < q; i++){
        ans = 0;
        scanf("%d",&inp);
        for (j = 0; j < inp-1; j++){
            scanf("%d%d",&t1,&t2);
            ans += (t1+t2)*(t1+t2);
        }
        printf("%d\n",s[inp].count(ans));
    }
}
// 1 2
// 2 3
// 3 4

// 1 3
// 2 4
// 2 3