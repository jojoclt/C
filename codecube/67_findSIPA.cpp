#include <bits/stdc++.h>
using namespace std;
string s;
int n,i,cnt;
void convert(int k){
    string x;
    if ((s[k] == 's' || s[k] == 'S')
    && (s[k+1] == 'i' || s[k+1] == 'I')
    && (s[k+2] == 'p' || s[k+2] == 'P')
    && (s[k+3] == 'a' || s[k+3] == 'A')) {
        i += 4;
        cout << "\"";
        cout << s.substr(k,4);
        cout << "\"";
        cnt++;
    }
    else{
        i += 1;
        cout << s.substr(k,1);
    }
}
int main(){
    getline(cin,s);
    n = s.length();
    if (n < 4){
        cout << s;
        return 0;
    }
    while (i < n){
        convert(i);
    }
    printf("\n%d",cnt);
}