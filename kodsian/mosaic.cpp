#include <bits/stdc++.h>
using namespace std;
int tmax(int x, int y, int z) {return max(x,max(y,z));}
int n,k;
int i,j,t,t1,t2;
int dist[2005];
int N,high = 0,low=1e9;
unordered_map <int,vector<int>> v;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < k; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        N = tmax(N,t1,t2);
    }
    for (i = 1; i <= 2000; i++) sort(v[i].begin(),v[i].end());
    for (i = 1; i <= N; i++){
        high = 0,low = 1e9;
        for (j = 0; j < v[i].size(); j++){
            high = max(high,dist[v[i][j]]);
            low = min(low,dist[v[i][j]]);
        }
        if (v[i].size()){
            dist[i] = low+1;
            for (j = 0; j < v[i].size(); j++){
                if (low + 1 == dist[v[i][j]]){
                    dist[i] = high+1;
                    break;
                }
            }
        }
    }
    for (i = 1; i <= N; i++) if (dist[i]) printf("%d\n",dist[i]);
}