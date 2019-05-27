#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector <int> a;
int main(){
    int n,m,q,i,l,r,mid;
    int tmp1,tmp2;
    int c[100000];
    vector <int> a;
    scanf("%d%d%d",&n,&m,&q);

    for (i = 0; i < m; i++){
        scanf("%d%d",&tmp1,&tmp2);
        a.push_back(tmp1);
        a.push_back(tmp1+tmp2);
    }
    for (i = 0; i < q; i++)
        scanf("%d",&c[i]);
    sort(a.begin(),a.end());
    for (i = 0; i < a.size(); i++){
        if (a[i] == a[i+1]){
            a[i] = inf;
            a[i+1] = inf;
        }
    }

    a.push_back(1);
    a.push_back(n+1);
    sort(a.begin(),a.end());
    
//    for (i = 0; i < a.size(); i++)
//        printf("%d ",i);printf("\n");
//    for (i = 0; i < a.size(); i++){
//        printf("%d ",a[i]);
//    }printf("\n");
        for (i = 0; i < q; i++){
            int upper = upper_bound(a.begin(),a.end(),c[i])-a.begin();
            printf("%d\n",a[upper]-a[upper-1]);//min that higher than key

//            l = 0, r = a.size()-1;
//            while (l <= r){
//                mid = l + r >> 1;
//                //printf("%d %d %d\n",mid,l,r);
//                if (a[mid] > c[i]){
//                    r = mid-1;
//                }
//                else if (a[mid] < c[i])l = mid+1;
//                else if (a[mid] == c[i]) break;
//                //printf("l = %d, r = %d\n",l,r);
//            }
//            printf("%d",a[mid]-a[mid-1]);
        }
}

/*
10 3 2
2 4
4 5
3 7
7
5

3
2
*/
