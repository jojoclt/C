#include <bits/stdc++.h>
using namespace std;
int n;
int i,t,t1,t2;
int elo=1e9,epos,olo=1e9,opos;
char c1,c2;
int a[26];
int visit[26];
unordered_map <int,vector<int>> v;
queue <int> q;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf(" %c %c",&c1,&c2);
        t1 = c1-'A'; t2 = c2-'A';
        a[t1]++,a[t2]++;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (i = 0; i < 26; i++){
        if (a[i]%2 && olo > a[i]) olo = a[i], opos = i;
        else if (!(a[i]%2) && elo > a[i]) elo = a[i], epos = i;
    }
    if (olo == 1e9) q.push(epos);
    else if (elo == 1e9) q.push(opos);
    else q.push(olo>elo?opos:epos);
    while (!q.empty()){
        t = q.front(); q.pop();
    }
}