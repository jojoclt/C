#include<bits/stdc++.h>
using namespace std;
int n;
int m=1e9;
int a[1005][1005];
int mem[1005][1005][5];
int cx[4]={1,0,-1,0};
int cy[4]={0,1,0,-1};
struct node{
    int x,y,d;
};
bool check(int x,int y)
{
    if(x>=0 && y>=0 && y<n & x<n)return 1;
    return 0;
}
queue<node>q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[j][i]);
    q.push({0,0,0});
    q.push({0,0,1});
    while(!q.empty()){
        node t = q.front();
        //printf("%d %d to \n",t.x,t.y);
        q.pop();
        if(a[t.x+cx[t.d]][t.y+cy[t.d]]==1 || !check(t.x+cx[t.d],t.y+cy[t.d])){
            for(int i=0;i<4;i++){
                if(!mem[t.x+cx[i]][t.y+cy[i]][i] && i!=t.d&&i!=(t.d+2)%4&& check(t.x+cx[i],t.y+cy[i])&&a[t.x+cx[i]][t.y+cy[i]]!=1){
                    mem[t.x+cx[i]][t.y+cy[i]][i] = mem[t.x][t.y][t.d]+1;
                    //printf("type1 %d %d %d\n",t.x+cx[i],t.y+cy[i],mem[t.x+cx[i]][t.y+cy[i]][i]);
                    q.push({t.x+cx[i],t.y+cy[i],i});
                }
            }
        }
        else{
            if(!mem[t.x+cx[t.d]][t.y+cy[t.d]][t.d] &&check(t.x+cx[t.d],t.y+cy[t.d])){
                mem[t.x+cx[t.d]][t.y+cy[t.d]][t.d] = mem[t.x][t.y][t.d]+1;
                //printf("type2 %d %d %d\n",t.x+cx[t.d],t.y+cy[t.d],mem[t.x+cx[t.d]][t.y+cy[t.d]][t.d]);
                q.push({t.x+cx[t.d],t.y+cy[t.d],t.d});
            }
        }
    }

	if(mem[n-1][n-1][0]>mem[n-1][n-1][1]&&mem[n-1][n-1][1]!=0)
        printf("%d",mem[n-1][n-1][1]);
    else if(mem[n-1][n-1][0]) printf("%d",mem[n-1][n-1][0]);
    else printf("%d",mem[n-1][n-1][1]);
    return 0;
}
