#include <bits/stdc++.h>
using namespace std;
int n,a[1000],b[1000],i,j,mid,l,r,t = 0;
int c[1000],d[1000];
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (i = 0; i < n; i++)
        scanf("%d",&b[i]);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (b[i] == a[j]){
                c[i] = j+1;
                break;
            }
        }
    }
//    for (i = 0; i < n; i++) printf("%d ",c[i]);
    printf("\n");
    d[0] = c[0];
    for (i = 1; i < n; i++){
        if (c[i]> d[i-1]){
            d[i] = c[i];
            //printf("con%d\n",i);
            t++;
        }
        else{
            l = 0, r = t;
            //printf("!! l %d r %d %d\n",l,r,l+r>>1);
            while(l <= r){
                mid = l + r >> 1;
                if (c[i] < d[mid]){
                    r = mid-1;
                    //printf("FU%d\n",r);
                }
                else{
                    l = mid+1;
                    //printf("CK%d\n",l);
                }
                //printf("%d\n",i);
                //printf("??%d %d\n",mid,d[mid]);
            }//printf("mid %d trol%d\n",mid,i);
            d[mid] = c[i];

        }
    }
    //for (i = 0; i < n; i++) printf("%d ",d[i]);
    printf("%d",t);
}
/*
8
5 1 9 21 6 2 3 0
1 2 9 5 3 6 0 21

4
*/
