#include<bits/stdc++.h>
using namespace std;
int n,i,j;
int m(int m, int d){
    if (d<m) return d;
    else return m;
}
void swap(int a[], int b[], int x, int y);
void f(int a[], int b[], int c[], int d[], int l);
int main(){
    scanf("%d",&n);
    int a[n],b[n],c[n+1],d[n+1];
    for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
    f(a,b,c,d,0);
    return 0;
}

void swap(int a[], int b[], int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
    temp = b[x];
    b[x] = b[y];
    b[y] = temp;
}
void f(int a[], int b[], int c[], int d[], int l)
{
    printf("start%d-%d\n",l,n-1);
    c[0]=1;
    d[0]=0;
    if (l == n-1){
        c[n]=a[n-1]*c[n-1];printf("C=%d ",c[n]);
        d[n]=b[n-1]+d[n-1];printf("D=%d \n",d[n]);
        if(d[n]>c[n])min=m(d-c);
        else min=m(c-d);
    }
    else
    {
        for (i = l; i <= n-1; i++)
        {
            swap(a,b,l,i);
            c[i+1]=a[i]*c[i];printf("C=%d ",c[i+1]);
            d[i+1]=b[i]+d[i];printf("D=%d\n",d[i+1]);
            f(a, b, c, d, l+1);
            swap(a,b,l,i);
        }
    }
}
