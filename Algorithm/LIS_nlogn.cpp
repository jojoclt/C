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
            // cout<<"P";
            int c = upper_bound(a,a+pos,t)-a;
            a[c] = t;
        }
    }
    for (i = 0; i < pos; i++) printf("%d ",a[i]);
    // cout << n-pos;
}