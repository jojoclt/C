#include <bits/stdc++.h>
using namespace std;
int n,i,high,pos,t;
int a[1000005];
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        if (high < t){
            a[pos++] = t;
            high = t;
        }
        else{
            int c = upper_bound(a,a+pos,t)-a;
            a[c] = t;
        }
    }
    cout << n-pos;
}