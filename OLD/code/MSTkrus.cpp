#include <bits/stdc++.h> // kruskal
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node a)const
    {
        return a.val < val;
    }
};
int i,n,e,a,b,val,head[1000],ans = 0;
int c(int x){
    if (head[x] != x) return c(head[x]);
    else return x;
}
//UVA908
priority_queue<node>heap;
int main(){
    scanf("%d%d",&n,&e);
    for (i = 0; i < e; i++){
        scanf("%d%d%d",&a,&b,&val);
        heap.push({a,b,val});
    }
    for (i = 0; i <= n; i++) head[i] = i;
    while (!heap.empty()){
        node t = heap.top(); heap.pop();
        cout<< t.val<<endl;
        printf("x head(%d)=%d y head(%d)=%d\n",t.x,c(t.x),t.y,c(t.y));
        if (c(t.x) != c(t.y)){
            head[c(t.x)] = c(t.y);
            ans += t.val;
        }
    }

    printf("%d",ans);
}

/*

5 8
1 2 2
1 4 3
2 3 2
2 4 2
3 4 1
3 5 2
4 5 3
1 5 4

7
*/
