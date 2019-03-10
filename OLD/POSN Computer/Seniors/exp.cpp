#include<bits/stdc++.h>
using namespace std;
queue<int>q;
main(){
    q.push(55);
    q.push(52);
    printf("%d ",q.front());
    q.pop();
    printf("%d ",q.front());
}
