#include<bits/stdc++.h>
using namespace std;
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fori(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define forv(x,y) for(auto &x:y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))
#define gg exit(0);

const int maxn = 1e5 + 10;
int n,m,a[maxn],b[maxn],l;
vector<int> ke[maxn];

void nhap()
{
    fasty;
    #define task "coolmac"
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
main()
{
    //freopen("task.inp","r",stdin);
    //freopen("coolmac.out","w",stdout);

    nhap();
    cin>>n;
    fori(i,1,n) cin>>l>>a[i],ke[a[i]].pb(l);
    cin>>m;
    fori(i,1,m) cin>>b[i];

    sort(b+1,b+m+1);
    sort(a+1,a+n+1,greater<int>());
    fori(i,1,n) sort(all(ke[a[i]]));

    int i = 1,x = b[1],y = 1e5,kq = 0,ok = 0;
    while(i<=n)
    {
       int j = 1e9;
       while(i<=n && a[i]>=y)
       {
           forv(v,ke[a[i]]) if(v<=y)
           {j = min(j,v);break;}
           ++i;
       }
       if(j==1e9) break;
       ++kq;
       if(j<=x) {ok=1;break;}
       else y = j;
    }
    if(ok) cout<<kq;
    else cout<<-1;
}
