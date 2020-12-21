#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N=2*1e5+5;

typedef pair<int, int> ii;

int n, q, ans;
int a[N], child[N], lab[N];
vector<int> ke[N];

int cnt[4];

void dfs(int u, int par)
{
    child[u]=a[u];
    for (int v:ke[u]) if (v!=par)
    {
        dfs(v, u);
        child[u]+=child[v];
    }
    if (child[u]>a[u] && par) child[u]-=a[u];
}

void sub3()
{

    for (int t=0;t<=q;t++)
    {
        if (t)
        {
            int x;
            cin>>x;
            a[x]=1-a[x];
        }

        ans=0;
        for (int i=1;i<=n;i++) if (a[i])
        {
            dfs(i, 0);
            for (int v:ke[i]) if (child[v])
            {
                if (child[v]==child[i]-1) ans=(child[i]+1)/2;
                else ans=(child[i])/2;
                break;
            }
            break;
        }
        cout<<ans<<"\n";
    }
}

void dfs2(int u, int par, int label)
{
    lab[u]=label;
    if (a[u]) cnt[label]++;
    for (int v:ke[u]) if (v!=par) dfs2(v, u, label);
}

void sub2()
{
    int root=1;
    for (int i=1;i<=n;i++) if (ke[i].size()>2) root=i;

    int label=0;
    for (int i:ke[root]) dfs2(i, root, label++);

    for (int t=0;t<=q;t++)
    {
        if (t)
        {
            int x;
            cin>>x;
            a[x]=1-a[x];

            if (x!=root)
            {
                if (!a[x]) cnt[lab[x]]--;
                else cnt[lab[x]]++;
            }
        }

        int d=0, s=0;
        for (int i=0;i<label;i++) d+=(cnt[i]>0), s+=cnt[i];

        if (d!=1)
            cout<<(d+1)/2<<"\n";
        else
            cout<<((s+a[root])>1)<<"\n";
    }
}

void solve()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++)
    {
        int u, v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    if (n*q<=10000000) sub3();
    else sub2();

//    sub2();
}

int main()
{
	freopen("socks.inp","r",stdin);
	freopen("socks.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	solve();

	return 0;
}
