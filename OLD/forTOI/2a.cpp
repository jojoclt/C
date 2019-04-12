#include <bits/stdc++.h>
using namespace std;
string t1; int t2;
int n,i,high=-1e9;
struct st{
    string s;
    int x;
};
map <string,int> m,s;
vector <st> k;

int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        cin >> t1 >> t2;
        m[t1] += t2;
        k.push_back({t1,t2});
    }
    for (auto f : m) high = max(high,f.second);

    for (i = 0; i < k.size(); i++){
        if (m[k[i].s] == high){
            s[k[i].s] += k[i].x;
            if (s[k[i].s] >= high){
                cout << k[i].s;
                return 0;
            }
        }
    }

}
