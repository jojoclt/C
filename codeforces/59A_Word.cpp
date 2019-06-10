#include <bits/stdc++.h>
using namespace std;
string s;
int n,i;
int cnt;
void fun(int x){
    for (i = 0; i < n; i++){
        if (x > 0) putchar(toupper(s[i]));
        else putchar(tolower(s[i]));
    }
}
int main(){
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++){
        if (s[i] >= 'a' && s[i] <= 'z') --cnt;
        else ++cnt;
    }
    fun(cnt);
}