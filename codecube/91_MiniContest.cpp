#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct node{
    int x,y;
};
int a[] = {'B','W'};
int n,i,j,k,t;
string s;
vector <node> v;
bool c;
int main(){
    scanf("%d",&n);
    cin >> s;
    v.pb({-1,-1});
    for (i = 0; i < n; i++){
        if (s[i] == 'B') v.pb({i,0});
        if (s[i] == 'W') v.pb({i,1});
    }
    v.pb({n+1,-1});
    for (i = 1; i < v.size(); i++){
        if (v[i-1].y == -1)
            for (k = v[i].x-1,t = !v[i].y; k >= 0; k--, t = !t) s[k] = a[t];
        
        else if (v[i].y == -1)
            for (k = v[i-1].x+1,t = !v[i-1].y; k < n; k++, t = !t) s[k] = a[t];
            
        else{
            for (k = v[i-1].x+1,t = !v[i-1].y; k < v[i].x; k++, t = !t) s[k] = a[t];
            if (s[k-1] == s[k]) s[k-1] = 'G';
        }
    }
    cout << s;
}