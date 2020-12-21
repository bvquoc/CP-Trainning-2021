#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <long, long>
#define NAME "PERMEOW"

using namespace std;

const long N = 2e5 + 5;
const ll oo = 1e18, mod = 1e9 + 7;

long n, a[N], b[N], c[N];

void sub1 ()
{
    long res = 0;
    sort (b + 1, b + n + 1);
    for (long i = 1; i <= n; ++i) c[a[i]] = i;
    for (long i = 1; i <= n; ++i)
    {
        if (a[i] != b[i])
        {
            long tmp = c[b[i]];
            c[b[i]] = i;
            c[a[i]] = tmp;
            swap (a[i], a[tmp]);
            ++res;
        }
    }
    cout << res;
}

int main()
{
    freopen (NAME".INP", "r", stdin);
    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    bool _sub1 = 1;
    cin >> n;
    for (long i = 1; i <= n; ++i) cin >> a[i];
    for (long i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if (b[i] != a[i]) _sub1 = 0;
    }
    sub1 ();

    return 0;
}
