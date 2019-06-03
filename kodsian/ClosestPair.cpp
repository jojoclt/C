#include <bits/stdc++.h>
using namespace std;
const int n = 1e5+5;
struct Point {int x, y;} p[n], t[n];
bool cmpx(Point i, Point j) {return i.x < j.x;}
bool cmpy(Point i, Point j) {return i.y < j.y;}
int q,N,r,d;
int t1,t2;
long long distance(Point i, Point j){
    return 1ll*(j.x-i.x)*(j.x-i.x) + 1ll*(j.y-i.y)*(j.y-i.y);
}
long long DnC(int L, int R)
{
    if (L >= R) return LLONG_MAX;
    int M = (L + R) >> 1;
 
    long long d = min(DnC(L,M), DnC(M+1,R));
 
    int N = 0;
    for (int i=M;   i>=L && p[M].x - p[i].x < d; --i) t[N++] = p[i];
    for (int i=M+1; i<=R && p[i].x - p[M].x < d; ++i) t[N++] = p[i];
    sort(t, t+N, cmpy); 
 
    for (int i=0; i<N-1; ++i)
        for (int j=1; j<=3 && i+j<N; ++j)
            d = min(d, distance(t[i], t[i+j]));
 
    return d;
}
 
long long closest_pair(){
    sort(p, p+N, cmpx);
    return DnC(0, N-1);
}

int main(){
    scanf("%d",&q);
    while (q--){
        scanf("%d%d%d",&N,&r,&d);
        for (int i = 0; i < N; i++){
            scanf("%d%d",&t1,&t2);
            p[i] = {t1,t2};
        }
        if (sqrt(closest_pair()) - 2 * r < d) printf("N\n");
        else printf("Y\n");
    }
}