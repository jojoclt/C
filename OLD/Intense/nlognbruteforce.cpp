#include <bits/stdc++.h>
using namespace std;
int a[1000005],m[1000005];
int main(){
    int n,key,c;
    int i = 0,j = 0,k;
    //fill(&m[0],&m[1005],-1000);
    scanf("%d",&n);

    for (c = 0; c < n; c++)
        scanf("%d",&a[c]);
    while (i < n){
        if (m[j-1] < a[i]){
            m[j] = a[i];
            j++;
        }
        else{
            c = 0;
            while (a[i] > m[c]) c++;
            //printf("x%d\n",c);
            m[c] = a[i];
        }
        i++;
//        for (c = 0; m[c] != '\0';c++){
//            printf("%d",m[c]);
//        }printf("\n");

    }
    for (c = 0; m[c] != '\0';){
            c++;
        }

    printf("%d",c);

}
