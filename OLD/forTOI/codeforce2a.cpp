#include <bits/stdc++.h>
using namespace std;
string t1;
int n,t2,i,val=-1e9;
struct st{
    string s;
    int x;
};
map <string,int> m;
vector <st> k;
st v = {"",-10000};
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        cin >> t1 >> t2;
        m[t1] += t2;
        k.push_back({t1,t2});
    }
    for (auto f : m) val = max(val,f.second);
    m.clear();

    for (i = 0; i < n; i++){
        m[k[i].s] += k[i].x;
        if (v.x < m[k[i].s]){
            v.x = m[k[i].s];
            if (v.s != k[i].s)
                v.s = k[i].s;
        }
        else if (v.x > m[k[i].s] && v.s == k[i].s){
            v.x = m[k[i].s];
        }
    }
    cout << v.s;

}
