#include <bits/stdc++.h>
using namespace std;
string s,t;
unordered_map <string,int> m;
int t1,t2,i;
int main(){
    scanf("%d%d",&t1,&t2);
    cin >> s >> t;
    for (i = 0; i < t1-t2+1; i++) m[s.substr(i,t2)]++;
    printf("%d",m[t]);
}