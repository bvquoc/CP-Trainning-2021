#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int maxn = 1e5 + 7, v[15] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

int q, f[maxn], x, t;

void solve()
{
    cin >> x >> t;
    vector<int> val;
    for (int i = 0; i < 15; ++i) val.push_back(v[i]);
    val.push_back(x);
    sort(val.begin(), val.end());

    f[0] = 0;
    for (int i = 1; i < maxn; ++i)
    {
        f[i] = i;
        for (int j = 0; j < 16; ++j)
            if (i >= val[j]) f[i] = min(f[i], f[i - val[j]] + 1);
    }

    int res = 0, fin = 15;
    while (t >= maxn)
    {
        while (fin >= 0 && val[fin] > t) --fin;
        res += (t / val[fin]), t %= val[fin];
    }

    cout << res + f[t] << "\n";
}

void enter()
{
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    io;
    cin >> q;
    while (q--) solve();
}

int main()
{
    enter();
}
