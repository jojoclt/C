#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator < (node t) const{
        if (x != t.x) return x > t.x;
        return y < t.y;
    }
}a[1000001];
int i,j,n,val = 0;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+n);
    for (i = 0; i < n; i++){
        if (val <= a[i].y){
            printf("%d %d\n",a[i].x,a[i].y);
            val = a[i].y;
        }
    }
}