#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define ins insert
#define era erase
#define ll long long
#define pii pair < int, int >
#define N 500009

using namespace std;
int n, q, x, u, v;
int c[N];
vector < int > a[N];

//---------------------------------------
void sub_1()
{
    int dem = 0;
    for(int i=1; i<=n; ++i)
        dem+= c[i];
    cout << (dem > 1) << '\n';
    for(int i=1; i<=q; ++i)
    {
        cin >> x;
        if(c[x] == 1)
            dem--;
        else dem++;
        c[x] = 1 - c[x];
        cout << (dem > 1) << '\n';
    }
    exit(0);
}

//--------------------------------------------------------------------
int d[N];
void dfs(int u)
{
    for(int i=0; i<a[u].size(); ++i)
    {
        int v = a[u][i];
        if(d[v] == 0)
        {
            d[v] = d[u];
            dfs(v);
        }
    }
    return ;
}
void sub_2()
{
    int dem[5], tam;
    for(int i=1; i<=n; ++i)
    {
        if(a[i].size() == 3)
            tam = i;
    }

    d[tam] = 4;
    dem[4] = dem[1] = dem[2] = dem[3] = 0;

    for(int i=0; i<=2; ++i)
    {
        u = a[tam][i];
        d[u] = i +1;
        dfs(u);
    }

    for(int i=1; i<=n; ++i)
    {
        if(c[i] == 1)
            dem[d[i]]++;
       // cout << d[i] << '\n';
    }

    if(dem[1] + dem[2] + dem[3] + dem[4] <= 1)
        cout << 0;
    else if(dem[1] + dem[2] + dem[3] + dem[4] == 2)
        cout << 1;
    else if(dem[1] + dem[2] + dem[3] + dem[4] == 3 && c[tam] == 1)
        cout << 1;
    else if(dem[1] * dem[2] * dem[3] == 0)
        cout << 1;
    else cout << 2;
    cout << '\n';

    for(int i=1; i<=q; ++i)
    {
        cin >> x;
        if(c[x] == 1)
            dem[d[x]]--;
        else dem[d[x]]++;
        c[x] = 1 - c[x];
        if(dem[1] + dem[2] + dem[3] + dem[4] <= 1)
            cout << 0;
        else if(dem[1] + dem[2] + dem[3] + dem[4] == 2)
            cout << 1;
        else if(dem[1] + dem[2] + dem[3] + dem[4] == 3 && c[tam] == 1)
            cout << 1;
        else if(dem[1] * dem[2] * dem[3] == 0)
            cout << 1;
        else cout << 2;
        cout << '\n';
    }
}

//---------------------------------------------------------------
int l[N], par[N][22], leaf[N];
int DFS(int u, int p)
{
    l[u] = l[p] +1;
    par[u][0] = p;
    for(int k=1; k<=20; ++k)
    {
        par[u][k] = par[par[u][k -1]][k -1];
    }

    for(int i=0; i<a[u].size(); ++i)
    {
        int v = a[u][i];
        if(v != p)
            DFS(v, u);
    }
}

int get_lca(int x, int y)
{
    if(l[x] > l[y])
        swap(x, y);

    for(int i=19; i>=0; --i)
        if(l[par[y][i]] >= l[x])
            y = par[y][i];

    if(x == y)
        return x;

    for(int i=19; i>=0; --i)
        if(par[x][i] != par[y][i])
            x = par[x][i],
            y = par[y][i];

    if(x == y)
        return x;
    return par[x][0];
}

vector < int > vt;
void sub_3()
{
    DFS(1, 0);
    int dem = 0;
    for(int i=1; i<=n; ++i)
    if(c[i] == 1)
    {
        int kt = 0;
        for(int j=1; j<=n; ++j)
        if(c[j] == 1 && i != j)
        {
            u = get_lca(i, j);
            if(u == i)
            {
                kt = 1;
                break;
            }
        }
        if(kt == 0)
            leaf[i] = 1,
            dem++;
    }

    if(dem == 0)
        cout << 0;
    else if (dem == 1)
        cout << c[1];
    else cout << dem /2 + dem % 2;
    cout << '\n';
    while(q--)
    {
        cin >> x;
        if(leaf[x] == 1)
        {
            dem--;
            leaf[x] = 0;
        }
        else
        {
            vt.resize(0);
            for(int i=1; i<=n; ++i)
                if(leaf[i] == 1)
            vt.pb(i);

            int kt = 1;
            for(int i=0; i<vt.size(); ++i)
            {
                u = vt[i]; v = get_lca(u, x);
                if(v == u)
                {
                    leaf[u] = 0;
                    leaf[x] = 1;
                    kt = 0;
                    break;
                }
                else if(v == x)
                {
                    kt = 2;
                    break;
                }
            }
            if(kt == 1)
                dem++,
                leaf[x] = 1;
        }
        c[x] = 1 - c[x];
        if(dem == 0)
            cout << 0;
        else if (dem == 1)
            cout << c[1];
        else cout << dem /2 + dem % 2;
            cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> q;
    for(int i=1; i<=n; ++i)
        cin >> c[i];

    int kt = 0, dem = 0;
    for(int i=1; i<n; ++i)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        if(a[u].size() == 3)
            dem++;
        if(a[v].size() == 3)
            dem++;
        if(a[u].size() > 2)
            kt = 1;
    }

    if(kt == 0)
        sub_1();
    if(dem == 1)
        sub_2();
    sub_3();
    return 0;
}
