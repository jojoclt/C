#include<bits/stdc++.h>
using namespace std;
struct lane{
    int x,d;
    bool operator<(lane a)const{
        return a.d>d;
    }
};
priority_queue<int>q;
int n,m,k;
int a[100][10000];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        priority_queue<lane>pq;
        for(int j=0;j<k;j++){
            pq.push({j,a[i-1][j]});
        }
        for(int j=0;j<m;j++){
            if(j+k<m)pq.push({j+k,a[i-1][j+k]});
            while(pq.top().x<j-k){pq.pop();}
            a[i][j]+=pq.top().d;
            //printf("%d ",a[i][j]);
            if(i==n-1)q.push(a[i][j]);
        }
    }
    printf("%d",q.top());
    return 0;
}
/*
8 5 2
5 0 0 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
