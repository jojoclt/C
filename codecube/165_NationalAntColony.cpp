#include <bits/stdc++.h>
using namespace std;
int V,E,C;
int ant[50005],v[70005][3],h[50005],visit[50005];
int i,j,t1,t2,t3,cnt;
int l,r,mid;
int head(int x){
    if (h[x] != x) return h[x] = head(h[x]);
    return x;
}
bool f(int x){
    cnt = 0;
    for (i = 1; i <= V; i++){
        h[i] = i;
        visit[i] = -1;
    }
    for (i = 0; i < E; i++){
        if (v[i][2] <= x) continue;
        h[head(v[i][0])] = head(v[i][1]);
    }
    for (i = 1; i <= V; i++){
        if (visit[ant[i]] == -1) visit[ant[i]] = head(i);
        else if (visit[ant[i]] != head(i)) cnt++;
    }
    if (cnt == 0) return 1;
    return 0;
}
int main(){
    scanf("%d%d%d",&V,&E,&C);
    for (i = 1; i <= V; i++) scanf("%d",&ant[i]);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[i][0] = t1;
        v[i][1] = t2;
        v[i][2] = t3;
    }
    l = 0; r = 10e9;
    while (l <= r){
        mid = l+r>>1;
        if (!f(mid)) r = mid-1;
        else if (f(mid) && f(mid+1)) l = mid+1;
        else break;
    }
    cnt = 0;
    for (i = 0; i < E; i++){
        if (v[i][2] <= mid) cnt++;
    }
    cout << cnt;
}
