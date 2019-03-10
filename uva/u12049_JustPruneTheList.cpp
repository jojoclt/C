#include <bits/stdc++.h>
using namespace std;
int ans;
set <int> s;
multiset <int> s1,s2;
void Clear(){
    s.clear();
    s1.clear();s2.clear();
    ans = 0;
}
int a,b;
int T,i,t;
int main(){
//    freopen("12049o.txt","w",stdout);
    scanf("%d",&T);
    while (T--){
        Clear();
        scanf("%d%d",&a,&b);
        for (i = 0; i < a; i++){
            scanf("%d",&t);
            s1.insert(t);
            s.insert(t);
        }
        for (i = 0; i < b; i++){
            scanf("%d",&t);
            s2.insert(t);
            s.insert(t);
        }
        for (auto c : s){
            int it1 = s1.count(c);
            int it2 = s2.count(c);
            ans += abs(it1-it2);
        }
        printf("%d\n",ans);
    }
}
