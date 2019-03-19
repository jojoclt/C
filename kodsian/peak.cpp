#include <bits/stdc++.h>
using namespace std;
int n,k,i;
vector <int> v;
int a[5000005];
unordered_map <int,bool> m;

int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    if (a[1] > a[2]) v.push_back(a[1]);
    if (a[n] > a[n-1]) v.push_back(a[n]);
    for (i = 2; i <= n-1; i++){
        if (a[i] > a[i-1] && a[i] > a[i+1]){
            v.push_back(a[i]);
            i++;
        }
    }
    if (v.size() == 0){ printf("-1"); return 0;}
    sort(v.rbegin(),v.rend());
    i = 0;
    while (k){
        if (!m[v[i]]){
            k--;
            m[v[i]] = true;

        }
    }
    printf("-1");
}