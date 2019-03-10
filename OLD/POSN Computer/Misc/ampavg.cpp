#include<bits/stdc++.h>
using namespace std;

int main(){
  int y[20000],a[20000],b,t,k,max;
  b=t=k=0;
  for(int i=0;i<20000;i++)
    scanf("%d",&y[i]);
  for(int i=0;i<20000;i++){
    if(y[i]!=0){
      a[k]=y[i];
      k++;
      if(i==19999){
        max=0;
        for(int j=0;j<k;j++)
          if(a[j]>max)max=a[j];
        t+=max;
        b++;
        k=0;
      }
    }
    else if(y[i]==0&&y[i-1]!=0){
      max=0;
      for(int j=0;j<k;j++)
        if(a[j]>max)max=a[j];
      t+=max;
      b++;
      k=0;
      }
  }
  printf("%d/",t);
  printf("%d=\n",b);
  double x=(double)t/(double)b;
  printf("%.6lf",x);
  return 0;
}
