#include<stdio.h>
#include<math.h>
main(){
  int x,y,z;
  char id[5];
  printf("Enter your ID:");
  scanf(" %s",id);
  printf("Enter your salary:");
  scanf("%d",&x);
  printf("Enter your overtime salary:");
  scanf("%d",&y);
  z=x+y;
  if(z>=100000)printf("Tax=10%%");
  else if(z>=70000)printf("Tax=7%%");
  else if(z>=50000)printf("Tax=5%%");
  else if(z>=30000)printf("Tax=3%%");
  else printf("Tax=1%");
}
