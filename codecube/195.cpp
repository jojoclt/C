#include <bits/stdc++.h>
using namespace std;
int arr[700005],v[700005];
int m,n;
int i,t,t1;
int s;
int _max,c;
bool k;
int f(int x){
    return lower_bound(v,v+m-c-1,x) - v;
}
int main(){
    scanf("%d%d",&m,&n);
    for (i = 0; i < m; i++){
        scanf("%d",&arr[i]);
        _max = max(_max,arr[i]);
    }
    if (m == 1){
        for (i = 0; i < n; i++){
            scanf("%d",&t);
            printf("%d ",arr[0]+t);
        }
        return 0;
    }
    sort(arr,arr+m);
    t = 0;
    for (i = 0; i < m; i++){
        t = arr[i+1] - arr[i] - 1;
        s += t;
        if (t) v[i] = s, k = true;
        else arr[i] = v[i] = INT_MAX,c++;
    }
    sort(arr,arr+m);
    sort(v,v+m-1);
    // for (i = 0; i < m-c-1; i++) printf("%d ",v[i]); return 0;
    // for (i = 0; i < m-c; i++) printf("%d ",arr[i]); return 0;
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        if (!k) printf("%d ",_max+t);
        else{
            s = f(t);
            // printf("X%dX",s);
            if (s == m-c-1) printf("%d ",_max+t-v[s-1]);
            else{
                t1 = (s == 0) ? 0:v[s-1];
                // printf("%d",t1);
                // printf("arr[s] = %d t %d v[s-1] %d\n",arr[s],t,(s-1 >= 0) ? v[s-1] : 0);
                printf("%d ",arr[s]+(t-t1));
            }
        }
   }
}