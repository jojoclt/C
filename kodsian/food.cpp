#include <bits/stdc++.h>
using namespace std;
int n,m,t,i,j;
vector <int> v;
bool a[10];
int main(){
    scanf("%d%d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d",&t);
        a[t] = true;
    }
    for (i = 1; i <= n; i++){
        if (!a[i]){
            for (j = 1; j <= n; j++) if (i != j) v.push_back(j);
            do {
                printf("%d ",i);
                for (auto c : v) printf("%d ",c);
                printf("\n");
            } while (next_permutation(v.begin(),v.end()));
            
            v.clear();
        }
    }
}