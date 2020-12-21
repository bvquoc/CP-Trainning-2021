#include <bits/stdc++.h>
#define fi "SOCKS.inp"
#define fo "SOCKS.out"

using namespace std;

struct node
{
    vector<int> ke;
    int bac;
};

int n, q, a[500011], maxrank;
bool f[5011][5011];
node b[500011];

void INP()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        b[u].ke.push_back(v);
        b[v].ke.push_back(u);
        b[u].bac++;
        b[v].bac++;
        maxrank = max(maxrank, max(b[u].bac, b[v].bac));
    }
}

void Solve()
{
    if (maxrank == 1 || maxrank == 2)
    {
        int dem = 0;
        for (int i = 1; i <= n; i++)
            if (a[i]) dem++;
        if (dem > 1) cout << "1" << endl; else cout << "0" << endl;
    }
}

int main()
{
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    INP();
    Solve();
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        a[t] ^= 1;
        Solve();
    }
    return 0;
}
