#include<stdio.h>
#include<math.h>
int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
main(){
    int a[3],i,d;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    if(a[2]%4==3){
        m[1]=29;
    }
    d=a[0]-1;
    for(i=0;i<a[1]-1;i++){
        d+=m[i];
    }
    for(i=1;i<a[2];i++){
        d+=365;
        if(i%4==3)d++;
    }
    d%=7;
    if(d==6)printf("Saturday");
    else if(d==0)printf("Sunday");
    else if(d==1)printf("Monday");
    else if(d==2)printf("Tuesday");
    else if(d==3)printf("Wednesday");
    else if(d==4)printf("Thursday");
    else if(d==5)printf("Friday");
}
