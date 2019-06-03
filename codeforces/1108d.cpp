#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[] = {'R','G','B'};
int i,j;
int cnt;
int main(){
    cin >> n >> s;
    for (i = 1; i < n; i++){
        if (s[i] == s[i-1]){
            ++cnt;
            for (j = 0; j < 3; j++) if (a[j] != s[i-1] && a[j] != s[i+1]) s[i] = a[j];
        } 
    }
    cout << cnt << "\n"<<s;
}