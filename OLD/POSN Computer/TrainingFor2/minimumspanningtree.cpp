#include<bits/stdc++.h>
using namespace std;
struct edge{
    int x,y,v;
};
bool cmp(edge a,edge b)
{
    return a.v<b.v;
}
int b[100001];
int findhead(int x)
{
    if(b[x]==x)return x;
    else return findhead(b[x]);
}
edge a[100001];
int n,m,sum;
int main(){
    scanf("%d %d",&n,&m);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[i].x = x;
        a[i].y = y;
        a[i].v = v;
    }
    sort(&a[0],&a[m],cmp);
    /*for(int i=0;i<m;i++){
        printf("%d %d %d\n",a[i].a,a[i].b,a[i].v);
        //check sort
    }*/
    for(int i=1;i<=n;i++){
        b[i]=i;
    }
    for(int i=0;i<m;i++){
        x=a[i].x;
        y=a[i].y;
        v=a[i].v;
        if(findhead(x)!=findhead(y))
        {
            b[findhead(x)] = findhead(y);
            sum += v;
        }
    }
    printf("%d",sum);
    return 0;
}
/*
9 12
1 2 1
2 3 2
1 4 3
2 4 2
2 7 5
3 8 2
4 7 4
7 8 7
4 5 3
7 6 2
8 9 5
6 9 1
*/
