#include <bits/stdc++.h>
using namespace std;
int n,i,j,t,a[55];
int maxSize = 0, maxVal = 0;
unordered_map <int,int> m;
unordered_map <int,vector<pair<int,int>>> l;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (i = 1; i <= n; i++){
        t = 0;
        for (j = i; j <= n; j++){
            t += a[j];
            m[t]++;
            l[t].push_back({i,j});
        }
    }
    for (auto c : l){
        if (maxSize < m[c.first]) {
            
        }
    }

}