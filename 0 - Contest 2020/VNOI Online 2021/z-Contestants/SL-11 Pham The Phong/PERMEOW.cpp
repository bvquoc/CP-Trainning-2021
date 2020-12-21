#include <bits/stdc++.h>
#define maxn 100005
#define maxm 30005
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;

map<vector<int>, bool> mp;
int n, res = 0;
vector<int> a, b;

int bubbleSort(vector<int> a) {
	int cnt = 0;
	fw(0, n - 2, i) {
		bool sorted = true;
		fw(0, n - i - 2, j)
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				cnt = (cnt + 1) % mod;
				sorted = false;
			}
		if (sorted) break;
	}
	return cnt;
}

newbieCoder {
	effective;
	fileIO("PERMEOW");
	cin >> n;
	a.resize(n);
	b.resize(n);
	fw(0, n - 1, i)
		cin >> a[i];
	fw(0, n - 1, i)
		cin >> b[i];
	bool ok = true;
	fw(0, n - 1, i)
		if (a[i] != b[i]) {
			ok = false;
			break;
		}
	if (ok)
		return cout << bubbleSort(a) % mod, 0;
	mp[b] = 1;
	while (!mp[a]) {
		//if (mp[a]) break;
		res += bubbleSort(a);
		mp[a] = 1;
		//for (auto i : a)
		//    cout << i << ' ';
		//cout << '\n';
		next_permutation(a.begin(), a.end());
	}
	res = (res + bubbleSort(b) % mod) % mod;
	cout << res;
}
