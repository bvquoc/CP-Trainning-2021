#include <bits/stdc++.h>
#define name "SOCKS"
#define pb push_back

using namespace std;
const int N=1e5+10;
vector <int> ke[N];

bool st[N];
int k,n,q,cnt[4],I;

bool checksub1()
{
    for (int i=1; i<=n; i++)
    {
        if (ke[i].size()>2) return 0;
    }
    return 1;
}


int vs[N],z;

void dfs1(int u,int p)
{
    vs[u]=z;
    cnt[z]+=st[u];
    for (auto v:ke[u])
    {
        if (v!=p) dfs1(v,u);
    }
}

bool checksub2()
{
    I=1;
    for (int i=1; i<=n; i++)
    {
        if (ke[i].size()>ke[I].size())
        {
            I=i;
            if (ke[i].size()>3) return 0;
        }
    }

    for (auto v:ke[I])
    {
        ++z;
        cnt[z]=0;
        dfs1(v,I);
    }
    return 1;
}

int s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r"))
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin>>n>>q; int goc=1;
    for (int i=1; i<=n; i++)
    {
        cin>>st[i];
        if (st[i]) s++;
    }
    for (int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }

    if (checksub1() )
    {
        while (q--)
        {
            int x;
            cin>>x;
            if (st[x]) s--;
            else s++;
            st[x]=1-st[x];
            if (s>1) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
    else
    if (checksub2() )
    {
        while (q--)
        {
            int x;
            cin>>x;
            if (st[x]) cnt[vs[x]]--;
            else cnt[vs[x]]++;
            st[x]=1-st[x];

            if (cnt[1] && cnt[2] && cnt[3]) cout<<2;
            else
            if (s>1)
            {
                cout<<1;
            }
            else cout<<0;
            cout<<'\n';
        }
    }
}
