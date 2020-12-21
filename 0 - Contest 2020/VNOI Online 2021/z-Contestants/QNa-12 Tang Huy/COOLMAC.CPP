#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int m,n,s=N-5,f=N-5,res=1;
struct Point
{
    int x,y;
}a[N];
bool cmp(Point a,Point b)
{
    return ((a.x<b.x)||((a.x==b.x)&& (a.y<b.y)));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+m+1,cmp);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        s=min(s,t);
    }
    int y=s;
    for (int i=1;i<=m;i++)
    {
        if (f<=y) break;
        else
        {
            if (a[i].x<=s)
            {
                if (y<a[i].y) y=a[i].y;
            }
            else if (a[i].x<=y)
            {
                res++;
                s=y;
                y=max(y,a[i].y);
            }
        }
    }
    if (y<f) res=-1;
    cout<<res;
}
