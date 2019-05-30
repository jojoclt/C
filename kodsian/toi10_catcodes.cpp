#include <bits/stdc++.h>
using namespace std;
int k,m,q;
int i,j,c;
unordered_map <int,int> mp;
set <int> s,s1;
string t;
int main(){
    scanf("%d%d",&k,&m);
    for (i = 0; i < k; i++){
        c = 0;
        cin >> t;
        for (j = 0; j < m; j++){
            if (t[j] == '1') c |= 1 << (m-j-1); 
        }
        mp[c] = i+1;
        s1.insert(c);
    }
    scanf("%d",&q);
    for (i = 0; i < q; i++){
        c = 0;
        scanf("%d",&k);
        cin >> t;
        for (j = 0; j < m; j++)
            if (t[j] == '1') c |= 1 << (m-j-1);
        
        for ( ; j <= k; j++){
            if (s1.find(c) != s1.end()) s.insert(mp[c]);
            if (j == k) continue;
            c = ((c<<1)&((1ll<<m)-1)) | (t[j]=='1');
        }

        if (s.empty()) printf("OK\n");
        else{
            for (auto cs : s) printf("%d ",cs);
            printf("\n");
            s.clear();
        }
    }
}