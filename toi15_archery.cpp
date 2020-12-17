#include<bits/stdc++.h>

using namespace std;

long long mx[500005],pos[500005];
long long mxx = 1e18;
long long everyboxgototmx = 0;
vector<long long> v;
unordered_map<long long,long long> ump,ump2;

int main()
{
    int n;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&mx[i]);
        mxx = min(mxx,mx[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&pos[i]);
        ump2[pos[i]]++;
        if(pos[i]<mxx) everyboxgototmx += pos[i]+mx[i]-mxx;
        else everyboxgototmx += pos[i]-mxx;
        if(pos[i]<=mxx) v.push_back(pos[i]);
        ump[pos[i]] += mx[i];
    }
    v.push_back(mxx);
    long long ans1 = 1e18,ans2 = 1e18;
    long long t = everyboxgototmx;
    sort(v.rbegin(),v.rend());
    //printf("%lld ",v[0]);
    long long before;
    for(i=0;i<v.size();i++)
    {
        long long l = v[i];
        printf("t = %18lld ump[%d] = %18lld ump2[l] = %18lld ans1 = %18lld\n",t,l,ump[l],ump2[l],ans1);
        if(l!=mxx)
        {
            int c = l;
            t += ((before-l)*n);
            while(c!=before)
            {
                t = t-ump[c];
                c++;
            }
        }
        if(ans1>t)
        {
            ans1 = t;
            ans2 = l;
        }
        else if(ans1==t)
        {
            ans2 = l;
        }
        before = l;
    }
    printf("%lld %lld",ans2,ans1);

}