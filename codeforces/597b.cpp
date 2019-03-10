#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator < (node t) const{
        return y < t.y;
    }
};
vector <node> v;
int n,t1,t2,ans,high,i;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v.push_back({t1,t2});
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n; i++){
        if (high < v[i].y && high < v[i].x){
            high = v[i].y; ans++;
        }
    }
    cout << ans;
}
