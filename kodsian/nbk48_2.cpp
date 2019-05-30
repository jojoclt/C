#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
    bool operator < (node t) const{
        return x < t.x || ((x == t.x) && (y > t.y));
    }
};
node a[100000];
int _max[100000];
int n,q,MIN = 1e9;
int i,t,tmp;

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
    _max[i] = a[i].y;
    int curmax = a[i].y;
    for (i = 1; i < n; i++){
        curmax = max(curmax,a[i].y);
        _max[i] = max(_max[i-1],curmax);
    }
    
    for (i = 0; i < q; i++){
        scanf("%d",&t);
        
        if (t < MIN) printf("0\n");
        else printf("%d\n",_max[search(t)]);
    }
}