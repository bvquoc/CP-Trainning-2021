#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define sz(a) int(a.size())
using namespace std;
const int N = 5e5+1;

int n, q, cl[N], deg;
vector<int> ke[N];

void sub1()
{
    int cnt = 0;
    forinc(i,1,n) cnt += cl[i];
    if(cnt > 1) cout << 1;
	else cout << 0;
	cout << '\n';
    while(q--)
    {
        int u; cin >> u;
        if(!cl[u])
        {
            cl[u] = 1;
            cnt++;
        }
        else
        {
            cl[u] = 0;
            cnt--;
        }
        if(cnt > 1) cout << 1;
        else cout << 0;
        cout << '\n';
    }
    exit(0);
}
int id[N], lt, dd[5];
void DFS(int u,int par)
{
    id[u] = lt;
    for(int v:ke[u]) if(v!=par) DFS(v, u);
}

void sub2(int root)
{
    for(int u:ke[root])
    {
        ++lt;
        DFS(u, root);
    }
    int n_red = 0, n_child = 0;
    forinc(i,1,n) if(cl[i])
    {
        n_red++;
        if(!dd[id[i]]) n_child++;
        dd[id[i]]++;
    }
    if(n_child == 1)
	{
		if(n_red > 1) cout << 1;
		else cout << 0;
	}
	if(n_child == 2) cout << 1;
	if(n_child == 3) cout << 2;
	cout << '\n';
    while(q--)
    {
        int u; cin >> u;
        if(!cl[u])
        {
            cl[u] = 1; n_red++;
            if(u != root)
            {
                if(!dd[id[u]]) n_child++;
                dd[id[u]]++;
            }
        }
        else
        {
            cl[u] = 0; n_red--;
            if(u != root)
            {
                dd[id[u]]--;
                if(!dd[id[u]]) n_child--;
            }
        }
        if(n_child == 1)
        {
            if(n_red > 1) cout << 1;
            else cout << 0;
        }
        if(n_child == 2) cout << 1;
        if(n_child == 3) cout << 2;
        cout << '\n';
    }
    exit(0);
}

int tin[N], tout[N], index;
void dfs(int u,int p)
{
    tin[u] = ++index;
    for(int v:ke[u]) if(v!=p) dfs(v, u);
    tout[u] = index;
}

void xuly3(vector<int> &ver)
{
    sort(ver.begin(), ver.end(), [](int a,int b)
    {
        return tin[a] > tin[b];
    });
    int minid = n+1, par = 0;
    for(int u:ver)
    {
        if(minid <= tout[u]) ++par;
        minid = min(minid, tin[u]);
    }
    if(ver.size() <= 1) cout << 0;
    else
    {
        int n_ver = ver.size() - par;
        if(n_ver > 2) cout << n_ver-1;
        if(n_ver == 2)
        {
            if(par) cout << 2;
            else cout << 1;
        }
        if(n_ver == 1) cout << 1;
    }
    cout << '\n';
}

void sub3()
{
    vector<int> ver;
    forinc(i,1,n) if(cl[i])
        ver.push_back(i);
    dfs(1,0);
    xuly3(ver);
    while(q--)
    {
        int u;
        cin >> u;
        if(!cl[u])
        {
            cl[u] = 1;
            ver.push_back(u);
        }
        else
        {
            cl[u] = 0;
            for(int i=0; i<ver.size(); ++i)
                if(ver[i]==u)
                {
                    ver[i] = ver.back();
                    ver.pop_back();
                    break;
                }
        }
		xuly3(ver);
    }
}

void readinp()
{
    cin >> n >> q;
    forinc(i,1,n) cin >> cl[i];

    forinc(i,1,n-1)
    {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
        deg = max({deg, sz(ke[u]), sz(ke[v])});
    }
}

int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    readinp();
    if(deg <= 2) sub1();
    if(deg <= 3)
    {
        int root = 0, s2 = 1;
        forinc(i,1,n) if(sz(ke[i]) == 3)
        {
            if(!root) root = i;
            else
            {
                s2 = 0;
                break;
            }
        }
        if(s2) sub2(root);
    }
    sub3();
}
