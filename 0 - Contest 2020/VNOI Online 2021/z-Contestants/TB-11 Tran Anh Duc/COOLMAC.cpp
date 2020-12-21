#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
using namespace std;
const int oo=1e8;
const int MAXN=1e5+1;
int n,m;
pii a[MAXN];
int b[MAXN],x[MAXN],mark[MAXN],d[MAXN];
bool flag=false;
bool cmp(pii x,pii y)
{
    if(x.se==y.se)  return x.fi>y.fi;
    else    return x.se>y.se;
}
void check()
{
    memset(mark,0,sizeof(mark));
    int mi=oo;
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,b[i]);
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(x[i])
        {
            ans++;
            for(int j=a[i].fi;j<=a[i].se;j++)
            {
                mark[j]=1;
            }
        }
    }
    bool ok=false;
    for(int i=mi;i<=1e5;i++)
    {
        if(mark[i]==0)
        {
            ok=true;
            return;
        }
    }
    if(ok==false)
    {
        cout<<ans<<endl;
        flag=true;
        return;
    }
}
void quaylui(int i)
{

    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        if(flag==true)
        {
            return;
        }
        if(i==m)
        {
            check();

        }
        else quaylui(i+1);
    }
}
void sub1()
{
    quaylui(1);
    if(flag==false) cout<<-1;
}
int dd[MAXN],pos[MAXN];
void sub2()
{
    int mi=oo;
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,b[i]);
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
//        cout<<a[i].fi<<" "<<a[i].se<<endl;
        pos[a[i].fi]=i;
    }
    int i=1,ans=0;
    if(a[1].se!=100000)
    {
        cout<<-1;
        return;
    }
    while(true)
    {
        ans++;
        int temp=oo;
        bool co=false;
        for(int j=i+1;j<=m;j++)
        {
            if(a[j].se>=a[i].fi)
            {
                co=true;
                temp=min(temp,a[j].fi);
            }
        }
        if(co==false)
        {
            cout<<-1;
            break;
        }
        i=pos[temp];
        if(mi>=temp)
        {
            cout<<ans+1;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.INP" , "r" , stdin);
    freopen("COOLMAC.OUT" , "w" , stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(n<=10 && m<=16)
    {
        sub1();
        return 0;
    }
    if(n<=3000 && m<=3000)
    {
        sub2();
        return 0;
    }
    cout<<-1;
    return 0;
}
