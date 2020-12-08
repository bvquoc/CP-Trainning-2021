#include <bits/stdc++.h>
#define task "construct"

using namespace std;

const int N = 1e5 + 5;

int n, m;
long long a[N], ans, l[N], r[N];
stack<long long> st;
set<int> s;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0, q, L, R, k; i < m; ++i)
    {
        cin >> q >> L >> R;
        if (q == 1)
        {
            cin >> k;
            for (int j = L; j <= R; ++j) a[j] += k;
            continue;
        }
        while (!st.empty()) st.pop();
        for (int j = L; j <= R; ++j)
        {
            while (!st.empty() && st.top() >= a[j]) st.pop();
            l[j] = st.empty() ? 0 : st.top();
            st.push(a[j]);
        }
        while (!st.empty()) st.pop();
        for (int j = R; j >= L; --j)
        {
            while (!st.empty() && st.top() >= a[j]) st.pop();
            r[j] = st.empty() ? 0 : st.top();
            st.push(a[j]);
        }
        while (!st.empty()) st.pop();
        ans = 0;
        for (int j = L; j <= R; ++j)
        {
            while (!st.empty() && st.top() > a[j]) st.pop();
            if (!st.empty() && st.top() == a[j]) continue;
            ans += a[j] - max(l[j], r[j]);
            st.push(a[j]);
        }
        cout << ans << '\n';
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
	return 0;
}
