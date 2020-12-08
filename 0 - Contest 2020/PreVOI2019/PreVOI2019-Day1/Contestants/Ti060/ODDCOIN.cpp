#include <bits/stdc++.h>

using namespace std;
int q;
int x,t;
int d[]={1,3,5};
vector<int>f;
inline int ReadInt()
{
    char c;
    for(c=getchar(); '0'>c||c>'9'; c=getchar());
    int x=c-'0';
    for(c=getchar(); '0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    return x;
}
void init()
{
    int a=1;
    for(int i=1;i<=5;++i)
    {
        for(int j=0;j<=2;++j)
        f.push_back(a*d[j]);
        a*=10;
    }
}
int solve(int r)
{
    if(r<0)return 2*1e9;
    int ans=0;
    while(r)
    {
        int vt=upper_bound(f.begin(),f.end(),r)-f.begin()-1;
        int k=r/f[vt];
        r-=k*f[vt];
        ans+=k;
    }
    return ans;
}
int Get(int m)
{
    if(m<0)return 2*1e9;
    return m+solve(t-x*m);
}
void process()
{
    double l=-2.0,r=(int)t/x+2.9;
    while(r-l>1.0)
    {
        double m1=(double)(2.0*l+r)/3.0;
        double m2=(double)(l+2.0*r)/3.0;
        if(Get(m1)<=Get(m2))r=m2;
        else l=m1;
    }
    cout<<Get(r)<<"\n";
}
void sub12()
{
    int ans=2*1e9;
    for(int i=0;i<=t/x;++i)
        ans=min(ans,i+solve(t-x*i));
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    q=ReadInt();
    init();
    while(q--)
    {
        x=ReadInt(),t=ReadInt();
        if(t<=1e5)
        sub12();
        else
        process();
    }
    return 0;
}
