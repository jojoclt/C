#include <bits/stdc++.h>
using namespace std;

int main(){
    int low, high, i, flag,a[1000];
    scanf("%d%d",&low,&high);

    while (low < high){
        flag = 0;
        for(i = 2; i <= low/2; ++i){
            if(low % i == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            a[low] = 1;

        ++low;
    }

    for (i = low; i <= high; i++){
        if (a[i*i]) printf("%d ",i*i);
    }
    return 0;
}
