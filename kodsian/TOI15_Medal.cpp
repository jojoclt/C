/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
/*
TASK: medal.cpp
LANG: C++
AUTHOR: chalanthorn c
CENTER: SSWB
*/
#include <bits/stdc++.h>
using namespace std;
int n,t,i;
vector <int> h,w;
vector <int> ans;
long long k;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        h.push_back(t);
    }
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        w.push_back(t);
    }
    sort(h.begin(),h.end());
    sort(w.rbegin(),w.rend());
//    for (auto c : h) cout << c << " ";
//    for (auto c : w) cout << c << " ";
    for (i = 0; i < n; i++){
        ans.push_back(h[i]+w[i]);
    }
    sort(ans.begin(),ans.end());
    for (i = 1; i < n; i++){
        k += ans[i] - ans[i-1];
    }
    printf("%lld",k);
}
