#include <bits/stdc++.h>
using namespace std;
int i,j,t1,t2,val;
int k,m,n;
vector <int> v[100005];
int mem[10005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> m >> n;
    for (i = 0; i < n; i++){
        cin >> t1 >> t2;
        v[t2].push_back(t1);
    }
    mem[1] = k;
    for (i = 1; i <= m; i++){
        for (j = 0; j < v[i].size(); j++){
            mem[i] = max(mem[i],mem[v[i][j]]-1);
            if (mem[i]>=0) val = max(val,i);
        }
    }
//    for (i = 1; i <= m; i++){
//        printf("mem[%d]=%d\n",i,mem[i]);
//    }
    cout << val;
}
