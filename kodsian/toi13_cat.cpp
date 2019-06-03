#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[2000001];
long long i,l=0,r=0,mid;

bool check(long long c){
    long long mem = 0;
    for (int i = 0; i < n; i++){
        if (c < a[i]){
            if (!mem){
                mem = a[i];
            }
            else if (mem == a[i]){
                mem = 0;
            }
            else if (mem != a[i]){
                return 0;
            }
        }
    }
    return 1;
}
void Bsearch(){
    bool flag = false;
    while (l <= r){
        mid = l + r >> 1;
//        cout << mid << " "<< check(mid-1) << " " << check(mid) << " " << check(mid+1) << endl;
        if (check(mid) == 0 && check(mid+1) == 0){
            l = mid+1;
        }
        else if (check(mid) == 1 && check(mid-1) == 1){
            r = mid-1;
        }
        else{
            flag = 1;
            if (check(mid-1) == 0 && check(mid) == 1)
                printf("%lld",mid);
            else if (check(mid) == 0 && check(mid+1) == 1)
                printf("%lld",mid+1);
            break;
        }
    }
    if (!flag) printf("0");
}

int main(){
//    freopen("1.in","r",stdin);
    scanf("%lld",&n);
    for (i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        r = max(r,a[i]+1);
    }
    Bsearch();
}

/*
6
3
3
2
5
5
2

7
8
2
3
10
2
10
11

6
3
5
2
2
5
3
*/
