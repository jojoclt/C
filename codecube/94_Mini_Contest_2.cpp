#include<bits/stdc++.h>
using namespace std;
bool found;
int i,n;
string s;
int main(){
    scanf("%d",&n);
    cin >> s;
    for(i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]) found = true;
        if(found) break;
    }
    if(found) printf("Wrong Answer");
    else printf("Accepted");
}