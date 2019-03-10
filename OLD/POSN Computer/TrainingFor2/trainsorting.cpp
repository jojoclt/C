#include<bits/stdc++.h>
using namespace std;
int n,x,y,c;
int a[2000];
int mem1[2000][50000];
int mem2[2000][50000];
f1(int x,int y){
    if(x==n)return 0;
    if(!mem1[x][y]){
        mem1[x][y]=f1(x+1,y);
        if(a[x]>y)mem1[x][y]=max(mem1[x][y],f1(x+1,a[x])+1);
    }
    return mem1[x][y];
}
f2(int x,int y){
    if(x==n)return 0;
    if(!mem2[x][y]){
        mem2[x][y]=f2(x+1,y);
        if(a[x]<y)mem2[x][y]=max(mem2[x][y],f2(x+1,a[x])+1);
    }
    return mem2[x][y];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("%d",f1(0,a[0])+f2(0,a[0])+1);
    return 0;
}
