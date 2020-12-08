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

int q, x, t, last;
vector < int > coin;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("ODDCOIN.inp", "r"))
    {
       freopen("ODDCOIN.inp", "r", stdin);
       freopen("ODDCOIN.out", "w", stdout);
    }
    coin.push_back(0);
    coin.push_back(1); coin.push_back(3); coin.push_back(5); coin.push_back(10); coin.push_back(30); coin.push_back(50);
    coin.push_back(100); coin.push_back(300); coin.push_back(500);
    coin.push_back(1000); coin.push_back(3000);
    coin.push_back(30000); coin.push_back(50000);
    cin >> q;
    while(q--)
    {
        int x, t, res = 0;
        cin >> x >> t;
        for(int i = 0; i < coin.size(); i++)
            if(coin[i] == last)
            {
                coin[i] = x;
                last = x;
                break;
            }
        sort(coin.begin(), coin.end());
        //for(int i : coin) cout << i << ' ';
        //cout << '\n';
        for(int i = coin.size() - 1; i >= 0; i--)
        {
            res += (t / coin[i]);
            t %= coin[i];
        }
        cout << res << '\n';
    }
}
