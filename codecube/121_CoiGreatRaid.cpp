#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator <(node t) const{
        return val > t.val;
    }
}t;
int n,e,a[100005],cnt;
int i,t1,t2,head[100005];
priority_queue <node> pq;
int h(int x){
    if (head[x] == x) return x;
    return head[x] = h(head[x]);
}
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        head[i] = i;
    }
    scanf("%d",&e);
    for (i = 0; i < e; i++){
        scanf("%d%d",&t1,&t2);
        pq.push({t1,t2,a[t1]+a[t2]});
    }
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (h(t.x) != h(t.y)){
            head[h(t.x)] = h(t.y);
            cnt += t.val;
        }
    }
    printf("%d",cnt);
}

/*
10
1 2 1 2 3 1 2 1 2 1
15
5 1
10 8
5 4
7 10
10 9
2 5
8 4
6 10
7 8
8 5
3 8
6 8
3 1
2 3
3 5

24
*/