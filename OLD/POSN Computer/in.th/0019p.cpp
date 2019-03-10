#include<bits/stdc++.h>
using namespace std;
int n,i,mi=1<<31-1;
int j[10];
int m(int m, int d){
    if (d<m) return d;
    else return m;
}
void f(int a[], int b[], int c[], int d[], int l);
int main(){
    scanf("%d",&n);
    int a[n],b[n],c[n+1],d[n+1];
    for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
    f(a,b,c,d,0);
    printf("%d",mi);
    return 0;
}


void f(int a[], int b[], int c[], int d[], int l)
{
    //for(i=1;i<n+1;i++)printf("%d ",c[i]);
    c[0]=1;
    d[0]=0;
    if (l == n-1){
        c[n]=a[n-1]*c[n-1];//printf("l=%d C=%d ",l,c[l+1]);
        d[n]=b[n-1]+d[n-1];//printf("D=%d \n",d[n]);
        if(d[n]>c[n])mi=m(mi,d[n]-c[n]);
        else mi=m(mi,c[n]-d[n]);
    }
    else
    {
        for (j[l] = l; j[l] <= n-1; j[l]++)
        {
            swap(a[l],a[j[l]]);
            swap(b[l],b[j[l]]);
            //printf("a[l]=%d b[l]=%d c[l]=%d d[l]=%d\n",a[l],b[l],c[l],d[l]);
            c[l+1]=a[l]*c[l];//printf("l=%d C=%d ",l,c[l+1]);
            d[l+1]=b[l]+d[l];//printf("D=%d\n",d[l+1]);
            if(d[l+1]>c[l+1])mi=m(mi,d[l+1]-c[l+1]);
            else mi=m(mi,c[l+1]-d[l+1]);
            //printf("brb i=%d\n",j[l]);
            f(a, b, c, d, l+1);
            //printf("ok this is done for i=%d\n",j[l]);
            swap(a[l],a[j[l]]);
            swap(b[l],b[j[l]]);
        }
    }
}
