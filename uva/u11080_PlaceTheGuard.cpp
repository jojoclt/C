#include<bits/stdc++.h>
using namespace std;
bool found,k;
int g[2],guard[200];
int ans;
int T,V,E;
int t,t1,t2,i,j;
vector <int> v[200];
queue <int> q;
int main(){
//    freopen("11080input.txt","r",stdin);
   // freopen("11080output.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        for (i = 0; i < 200; i++) v[i].clear();
        while (!q.empty()) q.pop();
        fill(guard,guard+200,-1);
        found = false;
        ans = 0;
        scanf("%d%d",&V,&E);
        for (i = 0; i < E; i++){
            scanf("%d%d",&t1,&t2);
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        for (j = 0; j < V; j++){
            if (guard[j] == -1)
            {
                g[0] = 0; g[1] = 1;
                q.push(j);
                guard[j] = 1;
                while (!q.empty()){
                    t = q.front(); q.pop();
                    k = guard[t];
                    for (i = 0; i < v[t].size(); i++){
                        if (guard[v[t][i]]!=-1 && guard[v[t][i]]==k){
                            found = true;
                            break;
                        }
                        if (guard[v[t][i]] != -1) continue;
                        guard[v[t][i]] = !k;
                        g[!k]++;
                        q.push(v[t][i]);
                    }
                    if (found) break;
                }
                if (found) break;
                if (v[j].empty()) ans+= 1;
                else ans += min(g[0],g[1]);
            }
        }
//        for (i = 0; i < V; i++){
//            printf("mem[%d] = %d\n",i,mem[i]);
//        }
        if (found) printf("-1\n");
        else printf("%d\n",ans);
    }
}
