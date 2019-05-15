#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,i;
    bool operator < (node t) const{
        return x > t.x;
    }
}a[502];
int n,length[505],dp[505];
int i,j,t;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        length[i] = 1;
        dp[i] = -1;
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].i = i+1;
    }
    sort(a,a+n);
    
    for (j = 0; j < n; j++){
        for (i = 0; i < j; i++){
            if (a[i].y < a[j].y && a[i].x > a[j].x && length[j] < length[i]+1){
                length[j] = length[i] + 1;
                dp[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) if (t < length[i]) t = length[i], j = i;
    printf("%d\n",t);
    stack <int> st;
    for (i = j; i >= 0; i = dp[i]) st.push(a[i].i);
    while (!st.empty()){
        printf("%d ",st.top()); st.pop();
    }

}