#include <iostream>
#include <fstream>
#define N 1000002

using namespace std;

int n, r[N], c[30];

int gr(int x) { return (r[x] > 0 ? r[x] = gr(r[x]) : x); }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("paint.inp", "r", stdin);
	freopen("paint.out", "w", stdout);
    int i, m; cin >> m;
    for (i = 1; i <= m; ++i)
    {
        int t, a, b;
        char chr;
        cin >> t >> chr;
        a = chr - 'a' + 1;
        if (t < 2)
        {
            ++n;
            if (c[a]) r[n] = c[a];
                else { c[a] = n; r[n] = -a; }
            continue;
        }
        cin >> chr; b = chr - 'a' + 1;
        if (!c[a] || a == b) continue;
        if (c[b]) r[c[a]] = c[b];
            else { r[c[a]] = -b; c[b] = c[a]; }
        c[a] = 0;
    }
    for (i = 1; i <= n; ++i) cout << char(-r[gr(i)] - 1 + 'a');
	return 0;
}
