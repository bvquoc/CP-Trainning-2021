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

const int mod=1e9+7;
const int N=1e5;


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
int a[N+5];
int m,n;
void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]=max(a[x],y);
    }
    for (int i=1;i<=1e5;i++)
    {
        a[i]=max(a[i-1],a[i]);
    }
    cin>>m;
    int mn=1e9;
    for (int i=1;i<=m;i++)
    {
        int x;cin>>x;mn=min(mn,x);
    }
    int ans=0;
    while (mn<=1e5)
    {
//        cout<<mn<<' '<<a[mn]<<endl;
        if (a[mn]<mn) {cout<<-1;return;}
        mn=a[mn]+1;ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
