#include<bits/stdc++.h>
using namespace std;
int i,j,k,maxx=-1e9;
int mem[10005];
int pw,mt,n,t1,t2;
vector<int>v[10005];
int dp(int nt,int eng)
{
    if(eng==pw||v[nt].empty())
    {
        maxx = max(maxx,nt);
        return 0;
    }
    mem[nt] = eng;
    for(int i=0; i<v[nt].size(); i++)
    {
        if(eng+1<mem[v[nt][i]])
            dp(v[nt][i],eng+1);
    }

}
int main()
{
    fill(&mem[0],&mem[10005],1e9);
    scanf("%d%d%d",&pw,&mt,&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
    }
     dp(1,0);
     printf("%d",maxx);


}
