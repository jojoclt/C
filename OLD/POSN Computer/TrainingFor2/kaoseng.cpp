#include<bits/stdc++.h>
using namespace std;
struct code{
  int a,b,c;
};
char a[1000],b[1000],c[100][1000];
int n,i;
int main(){
  scanf("%s",a);
  scanf("%s",b);
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%s",c[i]);
  for(i=0;i<n;i++){
    queue<code>q;
    q.push({0,0,0});
    int d=strlen(c[i]);
    while(1){
      if(q.empty()){
        printf("No\n");
        break;
      }
      code t=q.front();
      q.pop();
      if(t.c==d){
        printf("Yes\n");
        break;
      }
      if(a[t.a]==c[i][t.c])q.push({t.a+1,t.b,t.c+1});
      if(b[t.b]==c[i][t.c])q.push({t.a,t.b+1,t.c+1});
    }
  }
  return 0;
}
