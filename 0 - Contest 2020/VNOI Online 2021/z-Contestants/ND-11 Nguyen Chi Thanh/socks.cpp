#include <bits/stdc++.h>
#define nmax 500010
#define ll long long
#define pb push_back
#define eb emplace_back

using namespace std;
int n,q,cnt,a[nmax],f[nmax],g[nmax],con[nmax];
vector<int> vt[nmax];
int pt[4];
void sub1()
{
    if (cnt>1) cout<<1; else cout<<0; cout<<'\n';
    while (q--)
    {
        int x; cin>>x;
        if (a[x]==1) cnt--; else cnt++;
        a[x]^=1;
        if (cnt>1) cout<<1; else cout<<0; cout<<'\n';
    }
}
void dfs1(int u,int cha,int kt)
{
    for (int v:vt[u])
        if (v!=cha)
        {
            f[v]=kt;
            if (a[v]==1) pt[kt]++;
            dfs1(v,u,kt);
        }
}
void sub2()
{
    int l;
    for (int i=1;i<=n;i++)
        if (vt[i].size()==3)
        {
            l=i;
            break;
        }

    int type=0;
    for (int v:vt[l])
    {
        ++type;
        f[v]=type; if (a[v]==1) pt[type]++;
        dfs1(v,l,type);
    }

    if (cnt<2) cout<<0<<'\n';
    else if (pt[1]*pt[2]*pt[3]==0) cout<<1<<'\n';
    else cout<<2<<'\n';
    while (q--)
    {
        int x; cin>>x;
        if (a[x]==1)
        {
            --cnt; --pt[f[x]];
        }
        else
        {
            ++cnt; ++pt[f[x]];
        }
        a[x]^=1;
        if (cnt<2) cout<<0<<'\n';
        else if (pt[1]*pt[2]*pt[3]==0) cout<<1<<'\n';
        else cout<<2<<'\n';
    }
}
bool kt1()
{
    for (int i=1;i<=n;i++)
        if (vt[i].size()>2) return 0;
    return 1;
}
bool kt2()
{
    int sl=0;
    for (int i=1;i<=n;i++)
        if (vt[i].size()>3) return 0;
    else if (vt[i].size()==3)
    {
        ++sl;
        if (sl>1) return 0;
    }
    return 1;
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==1) cnt++;
    }
    for (int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        vt[u].pb(v); vt[v].pb(u);
    }

    if (kt1())
    {
        sub1();
        return 0;
    }
    else if (kt2())
    {
        sub2();
        return 0;
    }
    return 0;
}
