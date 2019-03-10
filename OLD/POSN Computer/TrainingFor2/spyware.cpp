#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int a[100000];
vector<int>v[100000];
priority_queue<int>pq[100000];
priority_queue<int>b;
int mem[100000];
void f(int x,int c){
    vector<int>q;
    while(!v[x].empty()){
        //printf("x=%d v[x]=%d a[v[x]]=%d c=%d\n",x,v[x].back(),a[v[x].back()-1],c );
        if(!mem[v[x].back()]){
            pq[c].push(a[v[x].back()-1]);
            mem[v[x].back()]=1;
            q.push_back(v[x].back());
        }
        v[x].pop_back();
    }
    while(!q.empty()){
        f(q.back(),c+1);
        q.pop_back();
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    a[k-1]=0;
    f(k,0);
    int c=0;
    while(!pq[c].empty()){
        //printf("normal +%d\n",pq[c].top());
        sum+=pq[c].top();
        b.push(-pq[c].top());
        pq[c].pop();
        if(c>0){
           while(!pq[c].empty()){
               if(-pq[c].top()<b.top()){
                    //printf("%d\n",b.top());
                    sum+=b.top();
                    b.pop();
                    b.push(-pq[c].top());
                    //printf("+%d\n",pq[c].top());
                    sum+=pq[c].top();
               }
               pq[c].pop();
               if(pq[c].empty())break;
            }
        }
        c++;
    }
    printf("%d",sum);
    return 0;
}
/*
5 5 2
8 8 3 10 7
1 2
2 4
1 3
1 4
4 5

6 5 1
5 4 6 7 8 10
1 2
1 3
2 4
2 5
3 6
*/
