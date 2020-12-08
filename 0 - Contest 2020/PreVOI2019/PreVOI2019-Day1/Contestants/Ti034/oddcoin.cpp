//----------Just Me & You---------
#include <bits/stdc++.h>
#include <bitset>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define oo 1000000007
#define Mod 1000000007
#define ll long long
#define pii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define sz(x) int(x.size())
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define Lozer "oddcoin"
#define mn 100005

using namespace std;

int w[100005];
int to[20]= {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0,oo};
int tp[20];

void Sub1(int x,int t)
{
    forr(i,1,20)
    {
        w[i]=oo;
    }
    w[1]=1;
    w[3]=1;
    w[5]=1;
    w[10]=1;
    w[x]=1;
    forr(i,1,t)
    {
        forr(j,1,i-1)
        {
            w[i]=min(w[j]+w[i-j],w[i]);
        }
    }
    cout<<w[t]<<'\n';
}

void Sub2(int x,int t)
{
    forr(i,0,100000)
    {
        w[i]=oo;
    }
    forr(i,1,15)
    {
        w[to[i]]=1;
    }
    w[x]=1;
    forr(i,1,t)
    {
        if(w[i]==1)
        {
            continue;
        }
        forr(j,1,i-1)
        {
            w[i]=min(w[j]+w[i-j],w[i]);
        }
    }
    cout<<w[t]<<'\n';
}

void Sub4(int x,int t)
{
    int ti=t;
    int res=0;
    int p=15;
    while(t>0 && p>0)
    {
        if(ti>=to[p])
        {
            res+=ti/to[p];
            ti=ti%to[p];
        }
        p--;
    }
    int ans=0;
    forr(i,1,17)
    {
        tp[i]=to[i];
        if(i==16)
        {
            tp[i]=x;
        }
    }
    sort(tp+1,tp+17+1);
    p=17;
    while(t>0 && p>0)
    {
        if(t>=tp[p])
        {
            ans+=t/tp[p];
            t=t%tp[p];
        }
        p--;
    }
    cout<<min(ans,res)<<'\n';
}

void Work()
{
    int test;
    cin>>test;
    while(test--)
    {
        int x,t;
        cin>>x>>t;
        if(x<=20 && t<=20)
        {
            Sub1(x,t);
            continue;
        }
        Sub2(x,t);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    Work();
    return 0;
}
