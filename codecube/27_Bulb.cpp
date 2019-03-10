#include <bits/stdc++.h>
using namespace std;
int mem[1100000];
queue <int> q;
int n,i,t,tmp,c;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&tmp);
        c |= tmp << i;
    }
    if (c == 0){
        printf("0");
        return 0;
        }
    q.push(0);
    while(!q.empty()){
        t = q.front(); q.pop();
        if (mem[c]){
            printf("%d",mem[c]);
            return 0;
        }
        for (i = 0; i < n; i++){
            tmp = t;
            if (i == 0){
                tmp ^= 1 << 0;
                if (n > 1) tmp ^= 1 << 1;
            }
            else if (i == n-1){
                tmp ^= 1 << n-2;
                tmp ^= 1 << n-1;
            }
            else{
                tmp ^= 1 << i-1;
                tmp ^= 1 << i;
                tmp ^= 1 << i+1;
            }
            if (mem[tmp]) continue;
            mem[tmp] = mem[t] + 1;
//            cout << "mem[";
//            bit(tmp);
//            cout <<  "]= " << mem[tmp]<<endl;
            q.push(tmp);
        }
    }
    printf("-1");
}
