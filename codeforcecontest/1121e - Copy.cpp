#include <bits/stdc++.h>
using namespace std;
int n,i,j,cnt;
void f(char x, char y){
    int c = y-x;
    if (c <= 5 || c <= -5){
        cnt += c;
        a[i] = ((a[i]-'0')%10)+c+'0';
        a[i+1] = ((a[i+1]-'0')%10)+c+'0';
    }
    else{
        cnt += 10-c;
        a[i] = ((a[i]-'0')%10)-10+c+'0';
        a[i+1] = ((a[i+1]-'0')%10)-10+c+'0';
    }
}
string a,b;
map<string,int> m;
map<string,pair<int,int>> track;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for (i = 0; i < n-1; i++){
        if (a[i] != b[i]){
            if ()
        }
    }
}
