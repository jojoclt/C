#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int n,m,c,d,e;
f(int x){
    c=0;
    d=-1;
    for(int i=x;i<n;i++){
        for(int j=d+1;j<m;j++){
            if(a[i]==b[j]){
                c++;
                d=j;
                break;
            }
        }
    }
    if(c>e)e=c;
    c=0;
    d=-1;
    for(int i=x;i<m;i++){
        for(int j=d+1;j<n;j++){
            if(b[i]==a[j]){
                c++;
                d=j;
                break;
            }
        }
    }
    if(c>e)e=c;
    if(x<n-1)f(x+1);
}
int main(){
    scanf("%s",a);
    scanf("%s",b);
    n=strlen(a);
    m=strlen(b);
    f(0);
    printf("%d",e);
    return 0;
}
/*
helloworld
llow

*/
