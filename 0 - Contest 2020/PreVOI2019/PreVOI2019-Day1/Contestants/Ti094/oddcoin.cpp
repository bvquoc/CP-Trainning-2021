#include <iostream>
#include <fstream>

using namespace std;

int x[16], t, d[2000002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("oddcoin.inp", "r", stdin);
	freopen("oddcoin.out", "w", stdout);
    int i, j, Q;
    for (i = j = 1, Q = 0; i <= 5; ++i, j *= 10)
    {
        x[Q++] = 1 * j;
        x[Q++] = 3 * j;
        x[Q++] = 5 * j;
    }
    cin >> Q;
    d[0] = 0;
    while (Q--)
    {
        cin >> x[15] >> t;
        for (i = 1; i <= t; ++i) d[i] = 1e9;
        for (i = 1; i <= t; ++i)
            for (j = 0; j < 16; ++j)
                if (i >= x[j]) d[i] = min(d[i], d[i - x[j]] + 1);
        cout << d[t] << '\n';
    }
	return 0;
}
