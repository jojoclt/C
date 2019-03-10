#include <bits/stdc++.h>
using namespace std;

int n,m,k,i,j;
int a[105][10005];
struct cube{
    int x,val;
    bool operator < (cube a) const{
        return a.val > val;
    }
};
priority_queue <int> q;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (i = 1; i < n; i++){
        deque <cube> heap;

            for (j = 0; j <= k; j++){
                while(!heap.empty() && j > 0 && heap.back().val < a[i-1][j]) heap.pop_back();
                heap.push_back({j,a[i-1][j]});
            }
            for (j = 0; j < m; j++){
                while(!heap.empty() && heap.front().x < j-k) heap.pop_front();
                if (j > 0 && j + k < m) {
                    while(!heap.empty() && heap.back().val < a[i-1][j+k]) heap.pop_back();
                    heap.push_back({j+k,a[i-1][j+k]});
                }
                a[i][j] += heap.front().val;
                //printf("%d ",a[i][j]);
                if (i == n-1) q.push(a[i][j]);
            }
            //printf("\n");

    }
    printf("%d",q.top());
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0

49

2 10 3
1 2 3 4 5 6 7 8 9 10
1 9 2 8 3 7 4 6 5 5

16

3 2 0
99 98
30 40
60 52

190

*/
