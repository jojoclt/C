#include<bits/stdc++.h>
using namespace std;
struct coor{
    int y,v;
    bool operator <(coor a)const{
        return a.v<v;
    }
};
priority_queue<coor>pq;
vector<coor>a[100001];
int b[100001];
int n,m,sum;
int main(){
    scanf("%d %d",&n,&m);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({y,v});
        a[y].push_back({x,v});
    }
    pq.push({1,0});
    while(!pq.empty()){
        int y=pq.top().y;
        int v=pq.top().v;
        pq.pop();
        if(!b[y]){
            //printf("%d %d\n",y,v);
            b[y]++;
            sum+=v;
            for(int i=0;i<a[y].size();i++){
                if(!b[a[y][i]])pq.push(a[y][i]);
            }
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
