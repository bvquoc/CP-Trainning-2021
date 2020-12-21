#include <bits/stdc++.h>
#define maxn 2005
#define maxk 25
#define fw(a, b, c) for (ll c = a; c <= b; c++)
#define bw(a, b, c) for (ll c = a; c >= b; c--)
#define fileIO(TASK)                  \
	freopen(TASK ".inp", "r", stdin); \
	freopen(TASK ".out", "w", stdout);
#define effective            \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define newbieCoder main()
#define timing cerr << "Executed in " << clock() * 1000 / CLOCKS_PER_SEC << " ms";
#define SUB(a) cerr << "Hello Tsukasa, this is the Solution of subtask " << a;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;

int T;
vector<pii> a[maxn];

namespace Tsukasa {
	string STR(int a) {
		string res = "";
		while (a) {
			int t = a % 10;
			res += char(t + '0');
			a /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	bool isMul(string s) {
		int k = s.length();
		ll res = 0, sum = 0;
		s = ' ' + s;
		fw(1, k, i) {
			if (i % 2)
				res += (s[i] - '0');
			else sum += (s[i] - '0');
		}
		return (abs(res - sum) % 11 == 0);
	}

	inline void add (ll &c, int b) {
		c += b;
		if (c >= mod)
			c -= mod;
	}

	void Solve() {
		//sort(a.begin(), a.end());
		fw(1, T, i) {
		    ll res = 0;
            do {
                string s = "";
                for (auto k : a[i]) {
                    s += STR(k.second);
                    //cout << k.first << ' ';
                    //cout << k.second << ' ';
                }
                if (isMul(s))
                    add(res, 1);
                //cout << '\n';
                //cout << s << '\n';
            } while (next_permutation(a[i].begin(), a[i].end(), [](pii A, pii B) { return A.first < B.first; }));
            cout << res << '\n';
		}
	}
}

newbieCoder {
	effective;
	fileIO("GIFT11");
	scanf("%d", &T);
	fw(1, T, i) {
	    int n;
	    scanf("%d", &n);
	    fw(0, n - 1, j) {
	        int x;
	        scanf("%d", &x);
	        a[i].push_back(pii(j, x));
	    }
	}
    Tsukasa::Solve();
}
