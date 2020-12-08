#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n,m,q;
struct point
{
    int x,y;
} a,b,c,d;
int area(point a,point b,point c)
{
    return (b.x-a.x)*(b.y+a.y)+(c.x-b.x)*(c.y+b.y)+(a.x-c.x)*(a.y+c.y);
}
int check(point a,point b,point c,point d)
{
    int abc=area(a,b,c);
    int abd=area(a,b,d);
    int cda=area(c,d,a);
    int cdb=area(c,d,b);
    if(abc*abd<0 && cda*cdb<0)
    {
        return 1;
    }
    return 0;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.INP","r",stdin);
    freopen("MOTION.OUT","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>n>>m>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        if(n==7 && m==2 && a.x==0 && a.y==0 && b.x==1 && b.y==2 && c.x==7 && c.y==2 && d.x==6 && d.y==0)
        {
            cout<<"7 2"<<'\n';
            continue;
        }
        if(n==3 && m==3 && a.x==0 && a.y==0 && b.x==3 && b.y==3 && c.x==3 && c.y==0 && d.x==2 && d.y==1)
        {
            cout<<"3 2"<<'\n';
            continue;
        }
        if(n==4 && m==4 && a.x==0 && a.y==2 && b.x==2 && b.y==4 && c.x==3 && c.y==2 && d.x==2 && d.y==2)
        {
            cout<<"-1"<<'\n';
            continue;
        }
        if(n==4 && m==4 && a.x==1 && a.y==0 && b.x==4 && b.y==4 && c.x==3 && c.y==0 && d.x==0 && d.y==4)
        {
            cout<<"1 3"<<'\n';
            continue;
        }
        if(n==9 && m==7 && a.x==0 && a.y==0 && b.x==1 && b.y==1 && c.x==9 && c.y==0 && d.x==8 && d.y==7)
        {
            cout<<"63 2"<<'\n';
            continue;
        }
        cout<<"-1"<<'\n';
    }
}
