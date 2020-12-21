#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <long, long>
#define NAME "GIFT11"

using namespace std;

const long N = 2e3 + 5;
const ll oo = 1e18, mod = 998244353;

long T, n;
string a[N];

bool check (string t)
{
    long sum = 0;
    for (long i = 0; i < t.size(); ++i)
    {
        if (i % 2) sum -= (t[i] - 48);
        else sum += (t[i] - 48);
    }
    return (sum % 11 == 0);
}

ll brute (long i, long mask, string t)
{
    if (i > n) return check (t);

    ll res = 0;
    for (long j = 1; j <= n; ++j)
    {
        if (!(mask >> (j - 1) & 1L))
            res = res % mod + brute (i + 1, mask | (1 << (j - 1)), t + a[j]) % mod;
    }
    return res % mod;
}

int main()
{
    freopen (NAME".INP", "r", stdin);
    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (long i = 1; i <= n; ++i) cin >> a[i];
        if (n <= 10) cout << brute (1, 0, "") << '\n';
    }

    return 0;
}
