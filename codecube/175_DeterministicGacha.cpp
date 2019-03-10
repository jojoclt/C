#include <bits/stdc++.h>
using namespace std;
int n,k;
int i;
string s;
int a[100005],c;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++){
        cin >> s;
        if (s == "UR") a[i]++;
    }
    for (i = 1; i <= n; i++) a[i] += a[i-1];
    for (i = k; i <= n; i++) c = max(c,a[i]-a[i-k]);
    cout << c;
}
