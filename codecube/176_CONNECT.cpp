#include <bits/stdc++.h>
using namespace std;
int n,k,q,head[100005];
int i,t1,t2;
int c(int x){
    if (head[x] != x) return head[x] = c(head[x]);
    return x;
}
bool isSame(int x, int y){
    return c(x) == c(y);
}
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for (i = 1; i <= n; i++) head[i] = i;
    for (i = 0; i < k; i++){
        scanf("%d%d",&t1,&t2);
        if (c(t1) != c(t2)){
            head[c(t1)] = c(t2);
        }
    }
//    for (i = 1; i <= n; i++) cout << i << "=" <<head[i]<<endl;

    for (i = 0; i < q; i++){
        scanf("%d%d",&t1,&t2);
        if (isSame(t1,t2)) printf("yes\n");
        else printf("no\n");
    }
}
