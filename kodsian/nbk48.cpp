#include <bits/stdc++.h>
using namespace std;
struct node{
    long long x;
    int pos;
    bool operator < (node t) const{
        if (x != t.x) return x < t.x;
        return pos < t.pos;
    }
};
int n,q,t;
long long c;
vector <node> v;
int i;
int search(int x){
    int l = 0, r = n, mid;
    while (l <= r){
        mid = l+r>>1;
        if (v[mid].x >= x){
            r = mid-1;
        }
        else l = mid+1;
    }
    if (v[mid].x < x) return v[mid].pos+1;
    return v[mid].pos;
}
int main(){
    scanf("%d%d",&n,&q);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        c += t;
        v.push_back({c,i});
    }
    sort(v.begin(),v.end());
    for (i = 0; i < q; i++){
        scanf("%d",&t);
        printf("%d\n",search(t));
    }
}