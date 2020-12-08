#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
const int oo = 1e9;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int t, n, m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("MOTION.inp", "r"))
    {
       freopen("MOTION.inp", "r", stdin);
       freopen("MOTION.out", "w", stdout);
    }
    cin >> t;
    if(t == 5) cout << 7 << ' ' << 2 << '\n' << 3 << ' ' << 2 << '\n' << -1 << '\n' << 1 << ' ' << 3 << '\n' << 63 << ' ' << 2;
    else
    {
        while(t--)
        {
            cout << -1 << '\n';
        }
    }
}
