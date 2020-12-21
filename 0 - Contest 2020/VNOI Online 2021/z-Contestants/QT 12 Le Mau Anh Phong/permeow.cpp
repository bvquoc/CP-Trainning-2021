#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200007;

bool ok[MAXN];
int n;

int main()
{
    if (fopen("tst.inp", "r"))
    {
        freopen("tst.inp", "r", stdin);
        freopen("tst.out", "w", stdout);
    }
    else
    {
        freopen("PERMEOW.INP", "r", stdin);
        freopen("PERMEOW.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector <pair <int, int> > V;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        V.push_back({x, i});
    }
    sort(V.begin(), V.end());

    int t = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < V.size(); ++j)
            if (!ok[j] && V[j].second < V[t].second) ++V[j].second;
        ok[t] = 1;
        ans += V[t].second - i;
        ++t;
    }
    cout << ans;
    return 0;
}
