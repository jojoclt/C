#include <bits/stdc++.h>
using namespace std;
int N,S;
int i;
string t;
vector <string> s;
unordered_map <string,bool> m;
unordered_map <string,bool> visit;
bool k;
int T,ll;
int main(){
    scanf("%d%d",&N,&S);
    for (i = 0; i < N; i++){
        cin >> t;
        s.push_back(t);
    }
    scanf("%d",&T);
    while (T--){
        m.clear();
        k = false;
        scanf("%d",&ll);
        cin >> t;
        if (visit[t]) continue;
        visit[t] = true;
        for (i = 0; i < ll-S+1; i++){
            m[t.substr(i,S)] = true;
        }
        for (i = 0; i < N; i++){
            if (m[s[i]]){
                printf("%d ",i+1);
                k = true;
            }
        }
        if (!k) printf("OK");
        printf("\n");
    }
}