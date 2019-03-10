#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int n,m,c,d,e;
int mem[1005][1005];
f(int x,int y){
    if(x>=n||y>=m)return 0;
    if(mem[x][y]!=0)return mem[x][y];
    mem[x][y]=max(mem[x][y],f(x+1,y));
    mem[x][y]=max(mem[x][y],f(x,y+1));
    if(a[x]==b[y]){
        mem[x][y]=max(mem[x][y],1+f(x+1,y+1));
    }
    return mem[x][y];
}
int main(){
    scanf("%s",a);
    scanf("%s",b);
    n=strlen(a);
    m=strlen(b);
    printf("%d",f(0,0));
    return 0;
}
/*
helloworld
llow

*/
