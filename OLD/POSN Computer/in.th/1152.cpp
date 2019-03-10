#include<bits/stdc++.h>
using namespace std;
int n,sum;
priority_queue<int>q[1999];
priority_queue<int>a;
int main(){
    scanf("%d",&n);
    int k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&k);
            q[j+i].push(k);
        }
    for(int i=1;i<2*n-1;i++){
        sum+=q[i].top();
        a.push(-q[i].top());
        q[i].pop();
        while(!q[i].empty()){
            if(a.top()>-q[i].top()&&i<2*n-2){
                sum+=a.top();
                a.pop();
                a.push(-q[i].top());
                sum+=q[i].top();
            }
        q[i].pop();
        }
    }
    printf("%d",sum);
    return 0;
}
/*
5
50 36 10 13 2
17 5 16 42 41
49 12 38 9 25
18 4 36 31 11
30 6 3 46 50
5
30 46 17 43 35
31 24 7 8 49
42 11 11 3 31
32 10 42 35 35
27 3 29 47 43
*/
