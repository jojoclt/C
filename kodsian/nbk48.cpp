#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
    bool operator < (node t) const{
        return x < t.x || ((x == t.x) && (y < t.y));
    }
};
node a[100000];
int tree[400000];
int n,q,MIN = 1e9;
int i,t,tmp;
void add(int k, int x){
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = max(tree[2*k],tree[2*k+1]);
    }
}
int query(int l, int r){
    l += n; r += n;
    int s = INT_MIN;
    while (l <= r){
        if (l % 2 == 1) s = max(s,tree[l++]);
        if (r % 2 == 0) s = max(s,tree[r--]);
        l /= 2; r /= 2;
    }
    return s;
}
int search(int key){
    int l = 0,r = n-1,mid,t;
    while (l <= r){
        mid = (l+r)>>1;
        // cout << a[mid].x << "x\n";
        if (a[mid].x == key) return mid;
        else if (a[mid].x >= key) r = mid-1;
        else l = mid+1, t = l; //OR NO T BUT RETURN AS L OR R+1
    }
    return t-1;
}
int main(){
    scanf("%d%d",&n,&q);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        tmp += t;
        MIN = min(MIN,tmp);
        a[i].x = tmp;
        a[i].y = i+1;
    }
    sort(a,a+n);
    
    for (i = 0; i < n; i++){
        // printf("%d %d\n",a[i].x,a[i].y);
        add(i,a[i].y);
    }
    // while (scanf("%d",&t),t){
    //     printf("%d\n",query(0,search(t)));
    // }
    for (i = 0; i < q; i++){
        scanf("%d",&t);
        // cout << a[search(t)].x<<endl;
        // continue;
        if (t < MIN) printf("0\n");
        else printf("%d\n",query(0,search(t)));
    }
}