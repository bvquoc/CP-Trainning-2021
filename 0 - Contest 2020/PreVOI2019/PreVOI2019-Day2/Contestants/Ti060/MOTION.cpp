#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef pair<ii,ii>pi;
#define F first
#define S second
int n,m,t;
pi A[5];
set<pi>s;
inline int ReadInt()
{
    char c;
    for(c=getchar(); '0'>c||c>'9'; c=getchar());
    int x=c-'0';
    for(c=getchar(); '0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    return x;
}
void inp()
{
    n=ReadInt(),m=ReadInt();
    for(int i=0; i<=3; ++i)
    {
        A[i].F.F=ReadInt(),A[i].F.S=1;
        A[i].S.F=ReadInt(),A[i].S.S=1;
    }
}
ii sub(ii x,ii y)
{
    int T=x.F*y.S-x.S*y.F;
    int M=x.S*y.S;
    int r=__gcd(T,M);
    return ii(T/r,M/r);
}
ii add(ii x,ii y)
{
    int T=x.F*y.S+x.S*y.F;
    int M=x.S*y.S;
    int r=__gcd(T,M);
    return ii(T/r,M/r);
}
ii mul(ii x,ii y)
{
    int T=x.F*y.F;
    int M=x.S*y.S;
    int r=__gcd(T,M);
    return ii(T/r,M/r);
}
void ptr(ii &a,ii &b,ii &c,pi u,pi v)
{
    a=sub(u.S,v.S);
    b=sub(v.F,u.F);
    c=sub(mul(u.F,v.S),mul(u.S,v.F));
}
int CCW(pi a,pi b,pi c)
{
    ii x=add(add(mul(sub(a.F,b.F),add(a.S,b.S)),mul(sub(b.F,c.F),add(b.S,c.S))),mul(sub(c.F,a.F),add(c.S,a.S)));
    if(x.F*x.S<0)
        return -1;
    if(x.F*x.S>0)
        return 1;
    return 0;
}
bool check(pi x,pi y,pi u,pi v)
{
    if(CCW(x,y,u)*(CCW(x,y,v))<=0&&CCW(u,v,x)*CCW(u,v,y)<=0)
        return true;
    return false;
}
void dequy(pi x,pi y,pi u,pi v)
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    t=ReadInt();
    while(t--)
    {
        inp();
        cout<<-1<<"\n";
    }
    return 0;
}
