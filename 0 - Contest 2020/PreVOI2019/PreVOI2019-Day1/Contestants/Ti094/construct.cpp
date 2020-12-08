#include <iostream>
#include <fstream>
#define N 100002

using namespace std;

int n, m, qu[N], q = 0;
long long a[N], f[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("construct.inp", "r", stdin);
	freopen("construct.out", "w", stdout);
    int T, i, j; cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (i = 1; i <= n; ++i)
            { cin >> j; a[i] = j; }
        for (i = 1; i <= m; ++i)
        {
            int t, l, r; cin >> t >> l >> r;
            if (t < 2)
            {
                int k; cin >> k;
                for (; l <= r; ++l) a[l] += k;
                continue;
            }
            long long re = 0;
            for (j = r, q = 0; j >= l; --j)
            {
                while (q && a[qu[q]] >= a[j]) --q;
                if (q) f[j] = a[qu[q]];
                    else f[j] = 0;
                qu[++q] = j;
            }
            for (j = l, q = 0; j <= r; ++j)
            {
                while (q && a[qu[q]] > a[j]) --q;
                if (q) f[j] = max(f[j], a[qu[q]]);
                    else f[j] = max(f[j], 0ll);
                re += a[j] - f[j]; qu[++q] = j;
            }
            cout << re << '\n';
        }
    }
	return 0;
}
