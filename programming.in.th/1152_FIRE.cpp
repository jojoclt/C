#include <bits/stdc++.h>
using namespace std;
int i,j,t;
int n,cnt;
vector <int> v[2005];
priority_queue <int> pq;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d",&t);
            v[i+j].push_back(t);
        }
    }
    for (i = n*2; i > 2; i--){
        for (j = 0; j < v[i].size(); j++){
            pq.push(v[i][j]);
        }
        cnt += pq.top();
        pq.pop();
    }
    printf("%d",cnt);
}
