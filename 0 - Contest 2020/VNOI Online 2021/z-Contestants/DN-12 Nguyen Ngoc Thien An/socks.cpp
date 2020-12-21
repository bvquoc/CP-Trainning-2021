#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int mod=998244353;
const int N=5e5;


pii origin;
void operator-=(pii &A, pii B) {
    A.X -= B.X;
    A.Y -= B.Y;
}
bool ccw(pii O, pii A, pii B) {
    A -= O, B -= O;
    return A.X * B.Y > A.Y * B.X;
}
bool cmp(pii A, pii B) { return ccw(origin, A, B); }

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t);
        t=(t*t);
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}
int c[N+5];
vector<int> dsk[N+5];
int n,k;
void sub1()
{
//    cout<<"HAHA";
    int res=0;
    for (int i=1;i<=n;i++) if (c[i]) res++;
    for (int i=1;i<=k;i++)
    {
        int x;cin>>x;
        if (c[x]) res--;
        else res++;
        c[x]=!c[x];
        if (res>=2) cout<<1<<"\n";else cout<<0<<"\n";
    }
}
int color[N+5];
void dfs(int u,int p,int C)
{
    color[u]=C;
    for (int v:dsk[u])
    {
        if (v==p) continue;
        dfs(v,u,C);
    }
}
int SC[5];
void sub2()
{
//    cout<<"HAHA";
    int u=0;
    for (int i=1;i<=n;i++) if (dsk[i].size()==3)
    {
        u=i;
        dfs(dsk[i][0],i,1);
        dfs(dsk[i][1],i,2);
        dfs(dsk[i][2],i,3);
    }
    int res=0;
    for (int i=1;i<=n;i++) if (c[i])
    {
        SC[color[i]]++;
    }
//    cout<<SC[1]<<' '<<SC[2]<<' '<<SC[3]<<' '<<c[u]<<endl;
    for (int i=1;i<=k;i++)
    {
        int x;cin>>x;
        if (c[x]) SC[color[x]]--;
        else SC[color[x]]++;
        c[x]=!c[x];
        int d=0;
        for (int j=1;j<=3;j++) if (SC[j]) d++;
//        cout<<SC[1]<<' '<<SC[2]<<' '<<SC[3]<<' '<<c[u]<<endl;
        if (d==3)  {cout<<2<<"\n";continue;}
        if (d==2)  {cout<<1<<"\n";continue;}
        if (d==1&&c[u]) {cout<<1<<"\n";continue;}
        cout<<0<<"\n";
    }
}
//int check(int u,int p)
//{
//    int ans=0;
//    if (c[u]) return 1;
//    for (int v:dsk[u])
//    {
//        if (v==p) continue;
//        if (check(v,u))
//    }
//}
//void sub3()
//{
//    for (int i=1;i<=n;i++) if (c[i])
//    {
//        int d=0;
//        for (int j:dsk[i])
//            d+=Check(j,i);
//    }
//    for (int i=1;i<=n;i++)
//}
void solve()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++)
    {
        int x,y;cin>>x>>y;
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    pii res=mp(0,0);
    for (int i=1;i<=n;i++) if (dsk[i].size()>res.X) res=mp(dsk[i].size(),1);
    else if (dsk[i].size()==res.X) res.Y++;
    if (res.X<=2) sub1();
    if (res.X==3&&res.Y==1) sub2();
//    sub3();
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();

}
