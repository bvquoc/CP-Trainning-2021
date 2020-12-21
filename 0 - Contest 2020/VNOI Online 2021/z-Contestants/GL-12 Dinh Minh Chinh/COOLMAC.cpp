#include <bits/stdc++.h>
#define long long long
#define FOR(i, st, en) for (int i = st, _en = (en); i <= _en; ++i)
#define REP(i, en) for (int i = 0, _en = (en); i < _en; ++i)
#define FORD(i, st, en) for (int i = st, _en = (en); i >= _en; --i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define MASK(n) (1LL << (n))
#define BIT(x, i) (((x)>>(i)) & 1LL)
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define taskname "COOLMAC"
#define file                              \
	freopen(taskname".INP", "r", stdin); \
	freopen(taskname".OUT", "w", stdout)
using namespace std;
template<class T> bool minimize(T& x, const T& y) {
	if (x > y) {x = y; return true;}
	return false;
}
template<class T> bool maximize(T& x, const T& y) {
	if (x < y) {x = y; return true;}
	return false;
}
// ----------------------------------------------------------------------------------
typedef pair<int, int> ii;
const int inf = 1e5+1;
const int mod = 1e9+7;
#define maxn 100010
#define left __lft
#define right __rgt

int m, n, x = inf+10;
pair<int, int> seg[maxn];
int IT[maxn<<3];
int sum[maxn];
// ----------------------------------------------------------------------------------
int get(int id, int left, int right, int u, int v) {
    if (v < left || u > right) return 0;
    if (u <= left && right <= v) return IT[id];
    int mid = (left+right)>>1;
    int L = get(id<<1, left, mid, u, v);
    int R = get(id<<1|1, mid+1, right, u, v);
    return L + R;
}

void update(int id, int left, int right, int u, int v) {
    if (v < left || u > right) return;
    if (u <= left && right <= v) {
        IT[id] = right-left+1;
        return;
    }
    int mid = (left+right)>>1;
    update(id<<1, left, mid, u, v);
    update(id<<1|1, mid+1, right, u, v);
    IT[id] = IT[id<<1] + IT[id<<1|1];
}

void bruteUpdate(int left, int right) {
    FOR(i, left, right) sum[i] = 1;
}

int bruteGet(int left, int right) {
    int res = 0;
    FOR(i, left, right) res += sum[i];
    return res;
}

inline bool cmp(const ii &x, const ii &y) {
    return x.second > y.second || (x.second == y.second && x.first < y.first);
}

void test_case() {
    scanf("%d", &m);
    REP(i, m) {
        scanf("%d %d", &seg[i].first, &seg[i].second);
        seg[i].first++; seg[i].second++;
    }
    scanf("%d", &n);
    REP(i, n) {
        int tmp; scanf("%d", &tmp);
        tmp++;
        minimize(x, tmp);
    }

    sort(seg, seg+m, cmp);
    int res = 0;
    REP(i, m) {
        if (seg[i].second < x) continue;
        seg[i].first = max(seg[i].first, x);
        int val = bruteGet(seg[i].first, seg[i].second);
        if (val < seg[i].second-seg[i].first+1) {
            res++;
            bruteUpdate(seg[i].first, seg[i].second);
        }
    }

    int val = bruteGet(x, inf);
    if (val < inf-x+1) res = -1;
    cout << res << endl;
}

int main() {
	// fastio;
	file;

	test_case();
	return 0;
}

/*
(\_/)
( •_•)
/>(:3)<
Mlem Mlem */

