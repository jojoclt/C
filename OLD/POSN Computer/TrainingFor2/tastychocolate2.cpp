#include<bits/stdc++.h>
using namespace std;
int n,c,d;
int a[1000],b[1000];

main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        b[i]=a[i];
        if(a[i]>=a[i+1]){
            a[i]=a[i+1]-1;
            c++;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(b[i]<=b[i-1]){
            b[i]=b[i-1]+1;
            d++;
        }
    }
    //printf("%d %d\n",c,d);
    printf("%d",min(c,d));
}
/*
6
3 1 5 5 10 9
7
5 2 4 4 5 7 7
*/
