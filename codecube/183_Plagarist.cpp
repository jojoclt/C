#include <bits/stdc++.h>
using namespace std;
int n,i,t;
int tree[200005],a[200005];
void update(int k, int x){
    while (k <= n){
        tree[k] += x;
        k += k&-k;
    }
}
int query(int k){
    int sum = 0;
    while (k > 0){
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
        
    for (i = 1; i <= n; i++){
        scanf("%d",&t);
        printf("%d\n",a[t+query(t)]);
        update(t,1);
    }
}