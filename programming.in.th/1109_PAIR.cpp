#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
    bool operator < (node t) const{
        return y < t.y;
    }
}x[100005];
int t[100005],i,n;
long long cnt = 0;;
void mergeArray(int a, int b, int c, int d) {
    int i = a, j = c, k = 0;
    while (i <= b && j <= d) {
        if (x[i].x < x[j].x){
            cnt += (long long)(x[i].x)*(j-c);
            t[k++] = x[i++].x;
        }
        else{
            cnt += (long long)(x[j].x)*(b-i+1);
            t[k++] = x[j++].x;
        }
    }
    //collect remain
    while (i <= b){
        cnt += (long long)(x[i].x)*(j-c);
        t[k++] = x[i++].x;
    }
    while (j <= d){
        t[k++] = x[j++].x;
    }
    for (i = a, j = 0; i <= d; i++, j++)
        x[i].x = t[j];
}
void mergeSort(int i, int j){
    if (i < j){
        int m = (i + j) >> 1;
        mergeSort(i,m);
        mergeSort(m+1,j);

        mergeArray(i,m,m+1,j);
    }
}
int main(){
    cin >> n;
    for (i = 0; i < n; i++) cin >> x[i].x >> x[i].y;
    sort(x,x+n);
    mergeSort(0,n-1);
    cout << cnt;
//    for (i = 0; i < n; i++) cout << x[i] << " ";
}