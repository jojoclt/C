#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005],m[200005];
int i,j,c;
int high,val;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            c = a[i]+a[j];
            m[c]++;
            if (val < m[c]){
                val = max(val,m[c]);
            }
        }
    }
    cout << val;
}
