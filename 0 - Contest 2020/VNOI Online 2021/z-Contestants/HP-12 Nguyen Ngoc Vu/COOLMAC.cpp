#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1e5+10;
int n,m,st=1e9,res,t[mn];

void upd(int i,int val)
{
    i++;
    for(;i<=mn-9;i+=i&-i) t[i]=max(t[i],val);
}

int get(int i)
{
    i++;
    int kq=0;
    for(;i;i-=i&-i) kq=max(kq,t[i]);
    return kq;
}

main()
{
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forinc(i,1,n)
    {
        int l,r;
        cin >> l >> r;
        upd(l,r);
    }
    cin >> m;
    forinc(i,1,m)
    {
        int x;
        cin >> x;
        st=min(st,x);
    }
    while(st<1e5)
    {
        int z=get(st);
        if(z<st) return cout << -1,0;
        st=z+1;
        res++;
    }
    cout << res;
}
