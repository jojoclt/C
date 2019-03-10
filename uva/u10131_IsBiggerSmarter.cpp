#include <bits/stdc++.h>
#define RECUR 1
using namespace std;
struct node {
    int x,y,i;
    bool operator < (node t) const{
        return x < t.x;
    }
};
vector <node> v;
stack <int> st;
int t1,t2,i,k,cnt,t,high;
int n,length[1005],track[1005];
int f(int x){
    int to;
    if (x == n+1) return 0;
    if (length[x]) return length[x];
    for (int i = x; i <= n; i++){
        if (v[i].y < v[x-1].y && v[i].x > v[x-1].x){
            to = f(i+1)+1;
            if (to > length[x]){
                length[x] = to;
                track[x] = i+1;
            }
        }
    }
    return length[x];
}

int main(){
    while (scanf("%d%d",&t1,&t2),t1 && t2) v.push_back({t1,t2,++cnt});
    v.push_back({-1,10005,0});
    sort(v.begin(),v.end());
    n=v.size()-1;
    if (RECUR){
        printf("%d\n",f(1));
        t = 1;
        for (i = 0; i < length[1]; i++){
            t = track[t];
            printf("%d\n",v[t-1].i);
        }
    }
    else{
        for (k = 0; k < n; k++){
            length[k] = 1;
            for (i = 0; i < k; i++){
                if (v[i].y > v[k].y && v[i].x < v[k].x){
                    t = length[i] + 1;
                    if (t > length[k]) length[k] = t, track[k] = i;
                }
            }
        }
        
        // for (i = 0; i < n; i++) printf("track[%d] = %d\n",i,track[i]);
        for (i = 0; i < n; i++){
            if (high < length[i]){
                high = length[i];
                t = i;
            }
        }
        printf("%d\n",high);
        for (i = t; i != 0; i = track[i]) st.push(v[i].i);
        while (!st.empty()) printf("%d\n",st.top()),st.pop();
    }

}