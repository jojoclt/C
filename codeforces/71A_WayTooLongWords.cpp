#include <bits/stdc++.h>
using namespace std;
int T,n;
string s;
int main(){
    scanf("%d",&T);
    while (T--){
        cin >> s;
        n = s.length();
        if (n <= 10) cout << s <<endl;
        else cout << s[0] << n-2 << s[n-1]<<endl;
    }
}