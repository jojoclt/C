#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x,y;
    bool operator < (node t) const{
        return x < t.x || (x == t.x) && y < t.y;
    }
}t;
int q,i,j,t1,t2;
int n,r,d;
node v[100001];
set<node>s;
bool ClosestPair(){
    ll dist = 1e18;
    int j = 0;
    for (int i = 0; i < n; i++){
        int dd = ceil(sqrt(dist));
        while (abs(v[i].x - v[j].x) >= dist){
            s.erase({v[j].y,v[j].x});
            ++j;
        }
        auto it1 = s.lower_bound({v[i].y - dd, v[i].x});
        auto it2 = s.upper_bound({v[i].y + dd, v[i].x});

        for (auto it = it1; it != it2; ++it){
            int dx = v[i].x - it->y;
            int dy = v[i].y - it->x;
            dist = min(dist, 1LL * dx * dx + 1LL * dy * dy);
        }
        s.insert({v[i].y,v[i].x});
    }
    // printf("%lf",sqrt(dist) - 2 * r);
    if (sqrt(dist) - 2 * r < d) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--){
        cin >> n >> r >> d;
        for (i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
        sort(v,v+n);
        printf(ClosestPair() == 1 ? "Y\n":"N\n");
        s.clear();
    }
}