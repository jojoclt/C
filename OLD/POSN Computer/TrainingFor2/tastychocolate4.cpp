#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000],mem[1000][3000];
int f(int x,int y){
    if(x==n)return 0;
    if(y>3000)return mem[x][y]=1e9;
    if(!mem[x][y]){
        mem[x][y]=f(x+1,y+1)+1;
        if(a[x]>y)mem[x][y]=min(mem[x][y],f(x+1,a[x]));
        return mem[x][y];
    }
}
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",f(0,0));
}
/*
6
3 1 5 5 10 9
7
5 2 4 4 5 7 7
12
135 132 3 68 46 13 6 135 132 465 468 135
*/
