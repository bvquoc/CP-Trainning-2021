#include <bits/stdc++.h>
#define long long long
#define FOR(i, st, en) for (int i = st, _en = (en); i <= _en; ++i)
#define REP(i, en) for (int i = 0, _en = (en); i < _en; ++i)
#define FORD(i, st, en) for (int i = st, _en = (en); i >= _en; --i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define MASK(n) (1LL << (n))
#define BIT(x, i) (((x)>>(i)) & 1LL)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define taskname "DECOR"
#define file                              \
	freopen(taskname".INP", "r", stdin); \
	freopen(taskname".OUT", "w", stdout)
using namespace std;
template<class T> inline void minimize(T& x, const T& y) {
	if (x > y) x = y;
}
template<class T> inline void maximize(T& x, const T& y) {
	if (x < y) x = y;
}
// ----------------------------------------------------------------------------------
typedef pair<int, int> ii;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
#define maxn 500005
#define left __lft
#define right __rgt

int n, m, k, a[maxn];
int numZero;
// ----------------------------------------------------------------------------------
void sub1() {
    int res = 0, resleft = n+1, resright = 0;
    int left = n+1, right = 0;
    FOR(i, 1, n) {
        if (a[i] == 1) {
            minimize(left, i);
            maximize(right, i);
            if (right-left+1 > res) res = right-left+1, resleft = left, resright = right;
        }
        else {left = n+1; right = i;}
    }

    if (resleft == n+1 && resright == 0) cout << -1 << endl;
    else cout << resleft << " " << resright << endl;
}

void sub2() {
    queue<int> que;
    int res = 0, resleft = n+1, resright = 0;
    int left = n+1, right = 0;
    FOR(i, 1, n) {
        if (a[i] == 1) {
            minimize(left, i);
            maximize(right, i);
            if (right-left+1 > res) res = right-left+1, resleft = left, resright = right;
        }
        else {
            if (que.size() == k) left = que.front()+1, que.pop();
            que.push(i);
            minimize(left, i);
            maximize(right, i);
            if (right-left+1 > res) res = right-left+1, resleft = left, resright = right;
        }
    }

    if (resleft == n+1 && resright == 0) cout << -1 << endl;
    cout << resleft << " " << resright << endl;
}

void test_case() {
    cin >> n >> m >> k;
    FOR(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
        if (a[i] == 0) numZero++;
    }
    if (numZero <= k) {cout << 1 << " " << n << endl; return;}
    if (m == 0 && k == 0) {sub1(); return;}
    if (m == 0) {sub2(); return;}
}

int main() {
	fastio;
	file;

	test_case();
	return 0;
}

/*
(\_/)
( •_•)
/>(:3)<
Mlem Mlem */

