#include<bits/stdc++.h>
#define ii pair<double,double>
#define x first
#define y second
using namespace std;
double m,n;
ii a,b,c,d;
ii dd(ii a,ii b,double tg)
{
    ii kc;
    kc.x=b.x-a.x;
    kc.y=b.y-a.y;
    ii cc;
    cc.x=abs(a.x+kc.x*tg);
    long sl=0;
    while(cc.x>m)
        cc.x-=m,sl++;
    if(sl%2 && cc.x==m)
        cc.x=0;
    cc.y=abs(a.y+kc.y*tg);
    sl=0;
    while(cc.y>n)
        cc.y-=n,sl++;
    if(sl%2 && cc.y==n)
        cc.y=0;
    return cc;
}
int main()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long test; cin>>test;
    while(test--)
    {
        cin>>m>>n>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        bool chua=1;
        for(double i=1;i<=100 && chua;i+=1)
        for(double j=1;j<=100 && chua;j+=1)
        {
            double tg=i/j;
            if(dd(a,b,tg)==dd(c,d,tg))
            {
                chua=0;
                cout<<i<<' '<<j<<'\n';
            }
        }
        if(chua)cout<<-1<<'\n';
    }
    return 0;
}
