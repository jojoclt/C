#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int w,l,i,j,x=0;
int a[1005][1005];
void c(int i, int j){
  a[i][j]=0;
  if(i>0&&a[i-1][j]==1)c(i-1,j);
  if(j>0&&a[i][j-1]==1)c(i,j-1);
  if(i<w-1&&a[i+1][j]==1)c(i+1,j);
  if(j<l-1&&a[i][j+1]==1)c(i,j+1);
}
int main() {
  scanf("%d %d",&w,&l);
  //int a[w][l];
  for(i=0;i<w;i++){
    for(j=0;j<l;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<w;i++){
    for(j=0;j<l;j++){
      if(a[i][j]){
        c(i,j);
        x++;
      }
    }
  }
  printf("%d",x);
  return 0;
}
