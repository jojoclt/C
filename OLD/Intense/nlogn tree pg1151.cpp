#include <bits/stdc++.h>
using namespace std;
int a[1000005],m[1000005];
int main(){
    int n,key,c;
    int i = 0,j = 0,k;
    //fill(&m[0],&m[1005],-1000);
    scanf("%d",&n);
    int l = 0, r = n - 1,mid;

    for (c = 0; c < n; c++)
        scanf("%d",&a[c]);
    while (i < n){
        if (!m[j] && m[j-1] < a[i]){
            m[j] = a[i];
            j++;
        }
        else{
            while (l <= r){
                mid = l + r >> 1;
                if (m[mid] <= a[i]){
                    k = m[mid];
                    l = mid+1;
                }
                else r = mid-1;
            }
            m[k] = a[i];
            j++;

        }
        for (c = 0; m[c] != '\0';c++){
            printf("%d ",m[c]);
        }printf("\n");
        i++;

    }
    for (c = 0; m[c] != '\0';)
        c++;


    printf("%d",c);

}
