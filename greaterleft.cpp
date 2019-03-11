#include <bits/stdc++.h>
using namespace std;
int q,i,n,t,cnt;
set <int> s;
int main(){
    ios::sync_with_stdio(0);
    cin >> q;
    while (q--){
        s.clear();
        cin >> n;
        for (i = 0; i < n; i++){
            cnt = 0;
            cin >> t;
            auto it1 = s.find(-t);
            if (it1 == s.end()) s.insert(-t);
            auto it2 = s.lower_bound(-t);
            for (auto it = s.begin(); it != it2; it++)cnt++;
            cout << cnt << " ";
            
        }
    }
}