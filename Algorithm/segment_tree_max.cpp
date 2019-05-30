#include <bits/stdc++.h>
using namespace std;
int n,i,t;
int tree[100];
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
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        add(i,t);
    }
    cout << query(0,2);
    // for (i = 1; i < 2*n; i++) printf("%d ",tree[i]);
}

/*
4
-1 2 4 0
*/