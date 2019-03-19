#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> m;
int n,i,sc,x,maxx;
string s;
int main(){
    scanf("%d",&n);
    while (n--){
        maxx = 0;
        cin >> x >> s;
        sc = s.size();
        m.clear();
        for (i = 0; i < sc-x+1; i++){
            maxx = max(maxx,++m[s.substr(i,x)]);
        }
        for (auto k : m){
            if (k.second == maxx){
                cout << k.first << endl;
                break;
            }
        }
    }
}