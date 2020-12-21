#include <bits/stdc++.h>

#define TASK "COOLMAC"

using namespace std;

const int maxn = 1e5 + 5;
const int hig = 1e5;

int n, m, low, res = 1e9 + 69;
pair <int, int> a[maxn];

namespace Sub1
{
    void Solve(int state)
    {
        int l = 1e9 + 69, r = 1e9 + 69;
        for (int i = 0; i < n; i ++)
        {
            if ((state >> i) & 1)
            {
                int j = i + 1;
                if (a[j].second < low) continue;
                if (a[j].first > r) return;
                if (r == 1e9 + 69) r = 0;
                l = min(l, a[j].first);
                r = max(r, a[j].second);
            }
        }
        if (l <= low && r >= hig)
        {
            int k = __builtin_popcount(state);
            res = min(res, k);
        }
    }

    void Main()
    {
        for (int state = 0; state < (1 << n); state ++)
            Solve(state);
        cout << (res == 1e9 + 69 ? -1 : res) << "\n";
    }
}

namespace Sub3
{
    vector <int> S;

    bool inter(pair <int, int> u, pair <int, int> v)
    {
        return !(u.second < v.first || u.first > v.second);

    }

    void Main()
    {
        for (int i = 1; i <= n; i ++)
        {
            if (a[i].second < low) continue;
            if (!S.empty() && a[i].second < a[S.back()].second) continue;
            if (!S.empty() && !inter(a[S.back()], a[i])) {cout << -1; return;}
            while (S.size() >= 2 && inter(a[S[S.size() - 2]], a[i])) S.pop_back();
            if (S.size() == 1 && a[i].first <= low) S.pop_back();
            S.push_back(i);
        }
        if (S.empty()) cout << -1;
        else
        {
            int l = a[S.front()].first;
            int r = a[S.back()].second;
            if (l <= low && r >= hig) cout << S.size();
            else cout << -1;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	cin >> m;
	low = 1e9 + 69;
	for (int x, i = 1; i <= m; i ++)
    {
        cin >> x;
        low = min(low, x);
    }
//    Sub1::Main();
    Sub3::Main();
	return 0;
}
