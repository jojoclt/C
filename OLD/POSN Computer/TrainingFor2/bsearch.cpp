#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(&a[0],&a[n]);
    int l=0;int r=n-1;
    int ans;
    while(l<=r){
        int k=l+r>>1;
        if(a[k]<m){
            ans=a[k];
            l=k+1;
        }
        else{
            r=k-1;
        }
    }
    printf("%d",ans);
    return 0;
}
