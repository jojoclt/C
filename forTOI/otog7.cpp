#include <bits/stdc++.h>
using namespace std;
struct cube{
    int x,val;
    bool operator < (cube t) const{
        return val > t.val;
    }
};
int n,m,cnt = 1e9;
int i,j;
int a[20][20];
int main(){
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    for (i = 1; i < n; i++){
        priority_queue <cube> heap;
        for (j = 0; j <= 1; j++){
            heap.push({j,a[i-1][j]});
        }
        for (j = 0; j < m; j++){
            if (j > 0 && j + 1 < m) heap.push({j+1,a[i-1][j+1]});
            while (heap.top().x < j-1) heap.pop();
            a[i][j] += heap.top().val;
            //printf("%d ",a[i][j]);
			if (i == n-1) cnt = min(cnt,a[i][j]);
		}
		//printf("\n");

    }
    cout<<cnt;

}
