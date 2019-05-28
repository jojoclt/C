#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
/*
 * AUTHOR  : benbendog
 * PROBLEM : find the closest pair
 * SOLUTION: sweep line algorithm 
 * time    : O(nlogn)
 */
 
using namespace std;
int R,D,N;
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    bool operator<(const point & p)const
    {
        return y < p.y;
    }
};
int cmp(const point & p1,const point & p2)
{
    return p1.x < p2.x;
}
double dist(const point & p1,const point & p2)
{
    int v1 = p1.x - p2.x;
    int v2 = p1.y - p2.y;
    return sqrt(v1*v1 + v2*v2) - (2*R);
}
int main(){
    // input
    int n,i,r,l,q;
    double d;
    cin >> q;
    while (q--){
        scanf("%d%d%d",&N,&R,&D);
        point A[N],t;
        set<point> s;
        set<point>::iterator t1,t2;
        for(i = 0 ; i < n ; i++) scanf("%d%d",&A[i].x,&A[i].y);
        
        sort(A,A+n,cmp);
        
        d = dist(A[0],A[1]);
        r = 2;
        l = 0;
        while(A[l].x <= A[r].x - d)l++;
        for(; l < r ; l++)s.insert(A[l]);
        // output s
        while(r<n)
        {
            // check the point in the set
            t1 = s.lower_bound(point(A[r].x,A[r].y-d));
            t2 = s.upper_bound(point(A[r].x,A[r].y+d));
            for(;t1!=t2;t1++)
            {
                d = min(d,(double)dist(A[r],*t1));
            }
            s.insert(A[r]);
            if(r<(n-1))
            {
                while(A[l].x <=A[r+1].x - d)
                {
                    s.erase(A[l]);
                    l++;
                }
            }
            r++;
        }
        if (d < D) printf("N\n");
        else printf("Y\n");
    }
}