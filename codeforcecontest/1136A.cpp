#include <bits/stdc++.h>
using namespace std;
int i,n,t1,t2,s;
vector <pair<int,int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> t1 >> t2;
        v.emplace_back(t1,t2);
    }
    cin >> s;
    for (i = 0; i < n; i++){
        if (s > v[i].first && s > v[i].second) continue;
        else {
            cout << n-i;
            return 0;
        }
    }
}