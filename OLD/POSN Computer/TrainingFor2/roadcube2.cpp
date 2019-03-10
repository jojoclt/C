#include<bits/stdc++.h>
using namespace std;
int mem[100][10000];
int n,m,k,ans,mx2;
int a[100][10000];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int c,d;
            c=j-k;d=j+k;
            if(c<0)c=0;if(d>m-1)d=m-1;
            int mx=0;
            for(int k=c;k<=d;k++){
                if(mx<a[i-1][k])mx=a[i-1][k];
            }
            a[i][j]+=mx;
            if(i==n-1&&mx2<a[i][j])mx2=a[i][j];
        }
    }
    printf("%d",mx2);
    return 0;
}
