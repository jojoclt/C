#include<bits/stdc++.h>
using namespace std;
int a[200000],n,b[200000];
int d=0;
void f(int x){
    if(a[x]>b[d])
        b[++d]=a[x];
    else{
        int l=0;
        int r=d;
        int k,ans;
        while(l<=r){
            k=l+r>>1;
            if(b[k]>=a[x]){
                ans=k;
                r=k-1;
            }
            else
                l=k+1;
        }
        b[ans]=a[x];
    }
    if(x<n-1)f(x+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    b[0]=a[0];
    f(1);
    printf("%d",d+1);
    return 0;
}
/*
7
4 1 5 6 2 3 7
9
1 7 3 -4 2 6 0 10 -5
*/
