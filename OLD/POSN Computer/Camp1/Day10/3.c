#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    char n[1005];
    int a[10],b[10],c[10],i,j,min=1005,m,tmp;
    scanf(" %s",n);
    for(i=0;i<10;i++){a[i]=0;b[i]=1005;}
    for(i=0;i<strlen(n);i++){
        if(n[i]=='0'){a[0]++;if(i<b[0])b[0]=i;}
        else if(n[i]=='1'){a[1]++;if(i<b[1])b[1]=i;}
        else if(n[i]=='2'){a[2]++;if(i<b[2])b[2]=i;}
        else if(n[i]=='3'){a[3]++;if(i<b[3])b[3]=i;}
        else if(n[i]=='4'){a[4]++;if(i<b[4])b[4]=i;}
        else if(n[i]=='5'){a[5]++;if(i<b[5])b[5]=i;}
        else if(n[i]=='6'){a[6]++;if(i<b[6])b[6]=i;}
        else if(n[i]=='7'){a[7]++;if(i<b[7])b[7]=i;}
        else if(n[i]=='8'){a[8]++;if(i<b[8])b[8]=i;}
        else if(n[i]=='9'){a[9]++;if(i<b[9])b[9]=i;}
    }
    for(i=0;i<10;i++){
        printf("%d = %d\n",i,a[i]);
    }
}

