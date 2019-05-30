#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int q,i,j;
int n,r,d;
struct Point{
    int x,y;
    double getLen(const Point& a){
        return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y)) - (2 * r);
    }
}point[1000005];
double ans;
bool cmp(const Point& a, const Point& b){
    return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}
int main(){
    scanf("%d",&q);
    while (q--){
        ans = inf;
        scanf("%d%d%d",&n,&r,&d);
        for (i = 0; i < n; i++) scanf("%d%d",&point[i].x,&point[i].y);

        sort(point,point+n,cmp);
        for (i = 0; i < n; i++){
            for (j = i+1; j < n; j++){
                if (point[i].x + ans < point[j].x) break;
                double d = point[i].getLen(point[j]);
                if (d < ans) ans = d;
            }
        }
        
        if (ans < d) printf("N\n");
        else printf("Y\n");
    }
}