#include <bits/stdc++.h>

#define task "Oddcoin"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define DEBUG(X) { cerr << #X << " = " << (X) << '\n'; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << '\n'; }
#define sz(x) ((int)(x).size())
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
int res = 0, X, T, A, ans;
vi coin, coin1;
int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	coin.pb(1);coin.pb(3);coin.pb(5);
	coin.pb(10);coin.pb(30);coin.pb(50);
	coin.pb(100);coin.pb(300);coin.pb(500);
	coin.pb(1000);coin.pb(3000);coin.pb(5000);
	coin.pb(10000);coin.pb(30000);coin.pb(50000);
	cin >> T;
    while (T--)
    {
        cin >> X >> A;
        coin1 = coin;
        coin1.pb(X);
        ans = 1e9 + 7;
        sort(ALL(coin1));
        int pos = upper_bound(ALL(coin1), A) - coin1.begin();
        //DEBUG(pos);
        //for (int v : coin1) cout << v << ' ';
        //cout << '\n';
        rep(x, 1, (1 << pos) - 1)
        {
            res = 0;
            int A1 = A;
            Rep(i, pos - 1, 0)
            {
                if (x & (1 << i))
                {
                    res += A1 / coin1[i];
                    A1 %= coin1[i];
                }
            }
            if (A1 > 0) continue;
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}
