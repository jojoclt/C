#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return x < t.x;
    }
}a[1005];
int x,y,val;
int i,n;
int mem[1005][1005];
int h[1005];
int fun(int x, int y){
    if (x > n || y > n) return 0;
    if (mem[x][y]) return mem[x][y];
    if (x >= y) mem[x][y] = max(mem[x][y],fun(x,y+1));
    if (x <= y) mem[x][y] = max(mem[x][y],fun(x+1,y));
    if (x > y){
        mem[x][y] = max(mem[x][y],a[y].val+fun(x,h[y]));
    }
    if (x < y){
        mem[x][y] = max(mem[x][y],a[x].val+fun(h[x],y));
    }
    return mem[x][y];
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d%d%d",&x,&y,&val);
        a[i] = {x,y,val};
    }
    sort(a,a+n);
    int l,r,mid,key;
    for (i = 0; i < n; i++){
        key = a[i].y;
        l = i, r = n-1;
        while (l <= r){
            mid = (l+r)>>1;
            if (a[mid].x >= key) r = mid-1;
            else l = mid+1;
        }
        h[i] = l;
    }
  //  h[n] = n+1;
    printf("%d",fun(0,0));
    // for (i = 0; i < n; i++) printf("h[%d] = %d\n",i,h[i]);
}