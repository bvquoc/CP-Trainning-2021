#include <bits/stdc++.h>

using namespace std;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
    int n, m;
    ll t, k;
    cin >> n >> m >> t >> k;

    vector<ll> a(n), b(m);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll res1 = 0, res2 = 0;
    for (ll timer = 0; true; swap(a, b), swap(res1, res2))
    {
        int p = --upper_bound(all(a), timer) - a.begin();
        if (p >= 0 && p < a.size())
        {
            maximize(timer, a[p] + k);
            if (timer >= t) break;
        }

        p = lower_bound(all(a), timer) - a.begin();
        if (p >= 0 && p < a.size())
        {
            res1 += min(t, a[p]) - timer;
            timer = min(t, a[p]);
            if (timer >= t) break;
        }
    }
    
    cout << res1 << ' ' << res2;
    return 0;
}