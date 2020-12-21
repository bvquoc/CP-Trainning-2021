#include <bits/stdc++.h>

using namespace std;

#define N 2005
#define MOD 1000000007
#define ll long long

int n, a[N], b[N];

void read()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int j = 1; j <= n; j ++)
        cin >> b[j];
}

int id[N];

void solve()
{
    ll res = 0;
    for(int i = 1; i < n; i ++)
        for(int j = i + 1; j <= n; j ++)
            if(a[j] < a[i])
                res ++;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    read();
    solve();
    return 0;
}
