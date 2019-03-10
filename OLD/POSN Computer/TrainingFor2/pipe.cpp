#include <bits/stdc++.h>
using namespace std;
struct coor{
  int x,y,d;
  bool operator <(coor a)const{
    return a.d<d;
  }
};
int n,k,b[15000],sum;
coor a[15000];
priority_queue<coor>v;
priority_queue<int>q;
int head(int x){
  if(x==b[x])return x;
  else return head(b[x]);
}
int main() {
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    a[i].x=x;
    a[i].y=y;
  }
  for(int i=0;i<n;i++){
    b[i]=i;
    for(int j=i+1;j<n;j++){
      int d;
      d=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
      v.push({i,j,d});
      v.push({j,i,d});
    }
  }
  while(!v.empty()){
    coor t=v.top();
    v.pop();
    if(head(t.x)!=head(t.y)){
      b[head(t.x)]=head(t.y);
      printf("%d--%d\n",t.x,t.y);
      q.push(t.d);
    }
  }
  for(int i=0;i<k-1;i++){q.pop();}
  while(!q.empty()){
    printf("+%d\n",q.top());
    sum+=q.top();
    q.pop();
  }
  printf("%d",sum);
  return 0;
}

/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
