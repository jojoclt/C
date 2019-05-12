#include <bits/stdc++.h>
using namespace std;
int n,hitech,lim;
int i,j,k,t,p;
vector <int> tech[100005],v[100005];
bool visit[100005];
queue <int> q;
int _max,cnt;
int main(){
    scanf("%d%d%d",&n,&hitech,&lim);
    for (i = 1; i <= n; i++){
        scanf("%d",&t);
        tech[t].push_back(i);
        scanf("%d",&p);
        for (j = 0; j < p; j++){
            scanf("%d",&t);
            v[i].push_back(t);
        }
    }
    for (j = 1; j <= hitech; j++){
        // printf("%d\n",cnt);
        for (k = 0; k < (int)tech[j].size(); k++){
            if (visit[tech[j][k]]) continue;
            q.push(tech[j][k]);
        }
        while (!q.empty()){
            t = q.front(); q.pop();
           
            if (visit[t]) continue;
            visit[t] = true;
            if (++cnt > lim){
                printf("%d",j == 1 ? -1:j-1);
                return 0;
            }
            for (i = 0; i < (int)v[t].size(); i++){
                q.push(v[t][i]);
            }
        }
    }
    printf("%d",hitech);
}