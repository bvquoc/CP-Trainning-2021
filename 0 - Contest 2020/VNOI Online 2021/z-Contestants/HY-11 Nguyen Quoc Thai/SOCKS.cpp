#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;
int n, q;
int t[MAXN];
vector < int > ke[MAXN], ek[MAXN];
set < int > v;
int S;
void read()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> t[i];
        if(t[i]) v.insert(i);
    }
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ek[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) if(ek[i].size() == 0) S = i;
}
int h[MAXN], tr[20][MAXN];
void DFS(int u)
{
    for(auto v : ke[u])
    {
        if(v == tr[0][u]) continue;
        tr[0][v] = u;
        for(int i = 1; i <= 17; ++i) tr[i][v] = tr[i-1][tr[i-1][v]];
        h[v] = h[u] + 1;
        DFS(v);
    }
}
int LCA(int u, int v)
{
    if(h[u] < h[v]) swap(u,v);
    int d = h[u] - h[v];
    for(int i = 17; i >= 0; --i)
        if((d >> i) & 1) u = tr[i][u];
    if(u == v) return u;
    for(int i = 17; i >= 0; --i)
    {
        if(tr[i][u] != tr[i][v])
        {
            u = tr[i][u];
            v = tr[i][v];
        }
    }
    return tr[0][u];
}
int dem;
void calc()
{
    dem = 0;
    vector < int > s;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        s.push_back(*i);
    }
    vector < int > c;
    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(s[i] == S) continue;
        for(int j = i+1; j < s.size(); ++j)
        {
            int U = s[i], V = s[j];
            int x = LCA(U,V);
            //cerr << U << " " << V << '\n';
            //cerr << x << '\n';
            if(x == U || x == V) ++dem;
        }
    }
    cout << dem << '\n';
}
void sub1()
{
    int dem = 0;
    DFS(S);
    calc();
    while(q--)
    {
        int x;
        cin >> x;
        if(t[x]) t[x] = 0;
        else t[x] = 1;
        if(t[x] == 1) v.insert(x);
        else v.erase(x);
        calc();
    }
}
int main()
{
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    read();
    sub1();
    return 0;
}
