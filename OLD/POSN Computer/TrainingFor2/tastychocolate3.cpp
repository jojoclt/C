#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[1000],b[1000];

main(){
    c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]>=a[i+1]&&i<n-1){
                //printf("%d %d\n",a[i],a[i+1]);
            c++;
        }
    }
    printf("%d",c);
}
/*
6
3 1 5 5 10 9
7
5 2 4 4 5 7 7
12
135 132 3 68 46 13 6 135 132 465 468 135
*/
