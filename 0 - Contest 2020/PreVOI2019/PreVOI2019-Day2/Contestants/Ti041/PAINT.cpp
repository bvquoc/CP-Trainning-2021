/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/
#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e6 + 5;
char dp[N][26], turnInto[N][26];
int q, ptr = -1;
char a[N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	out("ans1.out");
	#else
	inout("PAINT", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> q;
	int curPos = 0;
	fw (i, 0, q) {
		int type;
		char x, y;
		cin >> type >> x;
		if (type == 1) {
			ptr++;
			a[ptr] = x;
			fw (j, 0, 26) turnInto[ptr][j] = char(j + 'a');
		} else {
			cin >> y;
			fw (j, 0, 26) if (turnInto[ptr][j] == x) turnInto[ptr][j] = y;
		}
	}
	bw (i, ptr + 1, 0) fw (j, 0, 26) {
		int afterCha = turnInto[i][j] - 'a';
		if (i < ptr) dp[i][j] = dp[i + 1][afterCha];
		else dp[i][j] = afterCha + 'a';
	}
	fw (i, 0, ptr + 1) cout << dp[i][a[i] - 'a'];
	return 0;
}
