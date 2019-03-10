#include <bits/stdc++.h>
using namespace std;
int i,j,t,n,high,cnt;
string s;
unordered_map <string,int> m;
int main(){
    for (i = 0; i < 5; i++){
        m.clear();
        cnt = 0;
        cin >> s;
        n = s.length();
        for (j = 1; j <= n; j++){
            if (n%j) continue;
            while (t < n){
                m[s.substr(t,j)]++;
                t += j;
            }
            if (m[s.substr(0,j)]*j==n) cnt++;
            t = 0;
        }
        printf("%d\n",cnt);
    }
}