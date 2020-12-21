#include <bits/stdc++.h>

using namespace std;
int Chain[100009], ChainHead[100009], Position[100009], level[100009], parent[100009][19], Subsize[100009];
int n, q, ChainID, pos, a[100009], tree[4000009], arr[100009];
const int bit = 17;
vector < int > adj[100009];
void dfs(int u, int pa)
{
    parent[u][0] = pa;
    level[u] = level[pa] + 1;
    Subsize[u] = 1;
    for (int v:adj[u])
        if (v != pa)
        {
            dfs(v,u);
            Subsize[u] += Subsize[v];
        }
}
void pre()
{
    for (int i = 1; i <= bit; i++)
        for (int j = 1; j <= n; j++)
            if (parent[j][i-1] != 0)
                parent[j][i] = parent[parent[j][i-1]][i-1];
}
int LCA(int u, int v)
{
    if (level[u] > level[v])
        swap(u,v);
    int depth = level[v] - level[u];
    for (int i = bit; i >= 0; i--)
        if ((depth>>i)&1)
            v = parent[v][i];
    if (u == v)
        return u;
    for (int i = bit; i >= 0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}
void HLD(int u, int pa)
{
    int Heavy_Child = -1, Heavy_Size = 0;
    Chain[u] = ChainID;
    Position[u] = ++pos;
    for (int v:adj[u])
        if (v != pa)
        {
            if (Heavy_Size < Subsize[v])
            {
                Heavy_Child = v;
                Heavy_Size = Subsize[v];
            }
        }
    if (Heavy_Child != -1)
        HLD(Heavy_Child,u);
    for (int v:adj[u])
        if (v != pa && v != Heavy_Child)
        {
            ChainID++;
            ChainHead[ChainID] = v;
            HLD(v,u);
        }
}
void build(int id, int l, int r)
{
    if (l == r)
        tree[id] = arr[l];
    else
    {
        int mid = (l+r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}
void update(int id, int l, int r, int pos)
{
    if (l > pos || r < pos)
        return;
    if (l == r)
    {
        tree[id] = (tree[id]) ? 0:1;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    tree[id] = tree[id*2] + tree[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
        return tree[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void ans()
{
    int cnt = 0;
    for (int i = 0; i <= ChainID; i++)
        if (i != ChainID)
        {
            int x = get(1,1,n,Position[ChainHead[i]],Position[ChainHead[i+1]]-1);
            if (x > 0)
                cnt++;
        }
        else
        {
            int x = get(1,1,n,Position[ChainHead[i]],n);
            if (x > 0)
                cnt++;
        }
    if (cnt <= 2)
        cout << 1;
    else
        cout << cnt - 1;
    cout << '\n';
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    pre();
    ChainHead[0] = 1;
    HLD(1,0);
    for (int i = 1; i <= n; i++)
        arr[Position[i]] = a[i];
    build(1,1,n);
    ans();
    for (int i = 1; i <= q; i++)
    {
        int p;
        cin >> p;
        update(1,1,n,Position[p]);
        ans();
    }
    return 0;
}
