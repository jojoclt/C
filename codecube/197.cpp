#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,pos;
    bool operator < (node t) const{
        return x > t.x || ((x == t.x) && pos < t.pos);
    }
};
int n,k,cnt;
int i,j,l,r,mid,t1,t2;
int a[1505];
vector <node> v;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    if (k >= n) {
        printf("0");
        return 0;
    }
    l = 0, r = n-1;
    if (k > 1){
        for (i = 0; i < n-1; i++) v.push_back({abs(a[i+1]-a[i]),i});
        if (n-1) sort(v.begin(),v.end());
    }
    for (i = 0; i < k; i++){
        r = (i == k-1) ? n-1:v[i].pos;
        sort(a+l,a+r+1);
        t1 = r-l+1;
        t2 =(r+l)>>1;
        if (t1%2==0) mid = (a[t2]+a[t2+1])>>1;
        else mid = a[t2];
        for (j = l; j <= r; j++) cnt += abs(a[j]-mid);
        // printf("%d\n",cnt);
        l = r+1;
    }
    printf("%d",cnt);
}