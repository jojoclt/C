#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005];
int l(int x,int y){
    int c=0;
    while(1){
        c++;
        x--;
        if(x==n-1&&y==n-1)
            return c;
        if(x<0||a[x][y]==1)
            break;
    }
    int m=1e9;
    if(m>r(x,y))m=r(x,y);
    if(m>u(x,y))m=u(x,y);
    if(m>d(x,y))m=d(x,y);
    return m+c;
}
int r(int x,int y){
    int c=0;
    while(1){
        c++;
        x++;
        if(x>=n||a[x][y]==1)
            break;
    }
    int m=1e9;
    if(m>l(x,y))m=l(x,y);
    if(m>u(x,y))m=u(x,y);
    if(m>d(x,y))m=d(x,y);
    return m+c;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int m=1e9;
    if(m>l(0,0))m=l(0,0);
    if(m>r(0,0))m=r(0,0);
    if(m>u(0,0))m=u(0,0);
    if(m>d(0,0))m=d(0,0);


    return 0;
}
