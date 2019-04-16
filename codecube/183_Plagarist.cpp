#include <iostream>
using namespace std;
int n,i,t;
int tree[200005],a[200005];
void update(int k){
    for ( ; k <= n; k += k&-k) tree[k]--;
}
int sum(int k){
    int sum = 0;
    for (; k > 0; k -= k&-k) sum += tree[k];
    return sum;
}
int query(int k){
    int l = 1, r = n,mid;
    while (l < r){
        mid = l+r>>1;
        if (sum(mid) >= k) r = mid;
        else l = mid+1;
    }
    return l;
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]), tree[i] = i&-i;
    for (i = 1; i <= n; i++){
        scanf("%d",&t);
        t = query(t);
        printf("%d\n",a[t]);
        update(t);
    }
}