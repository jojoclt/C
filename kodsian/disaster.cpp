#include <bits/stdc++.h>
using namespace std;
int n;
int i,t;
char t1,t2;
vector <int> v[200];
int c[200];
bool visit[200][200],OK;
int a1 = 1e9;
void f(char c, string s){
    if (OK) return;
    if (s.length() == n+1 && !OK){
        for (int i = 0; i < s.length(); i++) printf("%c ",s[i]);
        OK = true;
        return;
    }
    for (int i = 0; i < v[c].size(); i++){
        int cc = v[c][i];
        if (visit[c][cc]) continue;
        visit[c][cc] = visit[cc][c] = true;
        f(cc,s+(string(1,cc)));
        visit[c][cc] = visit[cc][c] = false;
    }
    return ;
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf(" %c %c",&t1,&t2);
        c[t1]++; c[t2]++;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (i = 'A'; i <= 'Z'; i++){
        if (c[i] % 2) if (a1 > c[i]) a1 = c[i], t1 = i;
    }
    f(t1,string(1,t1));
}
/*
6
AB
AE
BD
BC
CE
DE
*/