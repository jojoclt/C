#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],i;
int main(){
    scanf("%d",&n);
    fill(&a[0],&a[n],1e9);
    a[1] = 500;
    a[0] = 0;
        for(i=2;i<=n;i++){
            a[i] = min(min((a[i-1]+500),a[i-2]+800),min(a[i-5]+1500,a[i-15]+3000));
        }
        cout << a[n];
}