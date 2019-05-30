#include <bits/stdc++.h>
using namespace std;
string p = "codecube";
string s;
int i,j,cnt;
int main(){
    cin >> s;
    int n = s.length();
    while (i < n){
        if (j == 8) j = 0;
        if (s[i] == p[j]){
            i++, j++;
        }
        else j++,cnt++;
    }
    if (i == n){
        while (j++ < 8) ++cnt;
    }
    printf("%d",cnt);
}