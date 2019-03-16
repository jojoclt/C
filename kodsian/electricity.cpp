#include <bits/stdc++.h>
using namespace std;
int n,k;
int i,a[500005];
long long mem[500005];
priority_queue <pair<int,int>> pq;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    mem[1] = a[1];
    pq.push(make_pair(-mem[1],1));
    for (i = 2; i <= n; i++){
        while (pq.top().second < i-k) pq.pop();
        mem[i] = a[i]-pq.top().first;
        pq.push(make_pair(-mem[i],i));
    }
    // for(i = 1; i <= n; i++) cout << mem[i] << " ";
    cout << mem[n];
}

/*
7 3 1 4 2 6 2 4 2 
*/