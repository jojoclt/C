#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[1000],b[1000];
void f(int x){
    if(a[x]>b[c]){
        c++;
        b[c]=a[x];
    }
    else {
        for(int i=1;i<=c;i++){
            if(b[i]>a[x]&&b[i-1]<a[x])
                b[i]=a[x];
        }
    }
    if(x<n-1)f(x+1);
}
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    b[1]=a[0];
    c=1;
    f(1);
    printf("%d",n-c);
}
