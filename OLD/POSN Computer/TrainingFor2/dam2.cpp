#include <bits/stdc++.h>
using namespace std;
int n,w,sum,cn,mx,mxc,ans,anc;
deque<int>q;
int main() {
  int x;
  scanf("%d%d",&n,&w);
  for(int i=0;i<w;i++){
    scanf("%d",&x);
    q.push_back(x);
  }
  for(int j=0;j<w;j++){
    sum+=q[j];
    cn++;
    if(mx<sum){
      mx=sum;
      mxc=cn;
    }
    if(sum<0){
      sum=0;
      cn=0;
    }
  }
  if(mx>0){
    ans=mx;
    anc=mxc;
  }
  for(int i=w;i<n;i++){
    sum=mx=mxc=cn=0;
    scanf("%d",&x);
    q.pop_front();
    q.push_back(x);
    for(int j=0;j<w;j++){
      sum+=q[j];
      cn++;
      if(mx<sum){
        mx=sum;
        mxc=cn;
      }
      if(sum<0){
        sum=0;
        cn=0;
      }
    }
    if(mx>ans){
      ans=mx;
      anc=mxc;
    }
  }
  for(int i=w-1;i>0;i--){
    sum=mx=mxc=cn=0;
    q.pop_front();
    for(int j=0;j<i;j++){
      sum+=q[j];
      cn++;
      if(mx<sum){
        mx=sum;
        mxc=cn;
      }
      if(sum<0){
        sum=0;
        cn=0;
      }
    }
    if(mx>=ans&&mxc<anc){
      ans=mx;
      anc=mxc;
    }
  }
  printf("%d\n%d",ans,anc);
  return 0;
}
