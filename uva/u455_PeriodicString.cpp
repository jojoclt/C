#include <bits/stdc++.h>
using namespace std;
map <string,int> m;
string s;
int n,i,j,x;
bool k;
int main(){
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for (j = n-1; j >= 0; j--){
        if (j != n-1) printf("\n");
        k = false;
        i = 0;
        cin >> s;
        for (i = 1; i <= s.size(); i++){
            x = 0;
            m.clear();
            if (s.size()%i) continue;
            while(x < s.size()){
                m[s.substr(x,i)]++;
                x += i;
            }
            for (auto c: m){
                if (m[c.first]==(s.size()/i)){
                    printf("%d\n",i);
                    k = true;
                    if (k) break;
                }
                if (k) break;
            }
            if (k) break;
        }
    }
}
