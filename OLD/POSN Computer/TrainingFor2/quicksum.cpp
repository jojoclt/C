#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int b[1005];
int c[1005];
int mem[1005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++){scanf("%d",&b[i]);scanf("%d",&c[i]);}
    for(int i=0;i<=n;i++)
        mem[i]=mem[i-1]+a[i];
    for(int i=0;i<m;i++){
        printf("%d\n",mem[c[i]-1]-mem[b[i]-2]);
    }
    return 0;
}
/*
7 5
5 9 7 2 3 1 6
2 6
1 3
4 5
4 4
1 7
*/
