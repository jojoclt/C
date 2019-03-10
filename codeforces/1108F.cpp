#include <bits/stdc++.h>
using namespace std;
int i,j,t1,t2,t3,cnt;
int v,n;
int head[200005];
struct node{
    int x,y,w;
    bool operator < (node t) const{
        return w > t.w;
    }
};
int h(int x){
    if (head[x] == x) return x;
    return h(head[x]);
}
priority_queue <node> pq;
int main(){
    scanf("%d%d",&v,&n);
    for (i = 0; i < n; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        pq.push({t1,t2,t3});
    }
    for (i = 1; i <= v; i++) head[i] = i;

    while (!pq.empty()){
        node t = pq.top(); pq.pop();
//        printf("x = %d y = %d w = %d\n",t.x,t.y,t.w);
        if (h(t.x) != h(t.y)){
            head[h(t.x)] = h(t.y);
            t1 = t.x;
            t2 = t.y;
            t3 = t.w;
        }
        else if(t.w == t3 && (t1 == t.x || t2 == t.x || t1 == t.y || t2 == t.y)){
            cnt++;
        }

    }
    printf("%d",cnt);
}
