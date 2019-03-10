#include<bits/stdc++.h>
using namespace std;
main(){
    int n,t,i,j,k,x=0;
    char c;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)a[i]=-1;
    for(i=0;i<n;i++){
        cin>>c;
        if(c=='P'){
            scanf("%d",&t);
            for(j=0;j<n;j++){
                if (t>a[j]){
                    for(k=n;k>j;k--){
                        a[k]=a[k-1];
                    }
                    a[j]=t;
                    break;
                }
            }
        }
        else if (c=='Q'){
            b[x]=a[0];
            x++;
            for(j=1;j<n;j++)
                a[j-1]=a[j];
        }
    }
    for(i=0;i<x;i++)printf("%d\n",b[i]);
    return 0;
}
