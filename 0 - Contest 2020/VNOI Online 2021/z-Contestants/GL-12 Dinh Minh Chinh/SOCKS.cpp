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
#define taskname "SOCKS"
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
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
#define maxn 100005

int n, q;
int c[maxn];
vector<int> adj[maxn];
// ----------------------------------------------------------------------------------
void sub1() {
    int cnt = 0;
    vector<int> id(n+1);
    int u; FOR(i, 1, n) if (adj[i].size() == 1) {u = i; break;}
    int last = -1;
    while (cnt < n) {
        id[++cnt] = u;
        for (int v : adj[u]) if (v != last) {
            last = u; u = v;
            break;
        }
    }

    set<int> st;
    FOR(i, 1, n) if (c[i] == 1) st.insert(id[i]);

    while (q--) {
        int x; cin >> x;
        c[id[x]] = 1-c[id[x]];
        if (c[id[x]] == 0) st.erase(id[x]);
        else st.insert(id[x]);
        if (st.size() <= 1) cout << 0 << endl;
        else cout << 1 << endl;
    }
}

void sub2() {
    int cnt = 0;
    vector<int> id(n+1);
    int u; FOR(i, 1, n) if (adj[i].size() == 1) {u = i; break;}
    int last = -1;
    while (cnt < n) {
        id[++cnt] = u;
        for (int v : adj[u]) if (v != last) {
            last = u; u = v;
            break;
        }
    }
    vector<int> type(n+1, 0);
    int root; FOR(i, 1, n) if (adj[i].size() == 3) {root = i; break;}
    int ua = 0, ub = 0, uc = 0; for (int v : adj[root]) {
        if (!ua) ua = v;
        else if (!ub) ub = v;
        else if (!uc) uc = v;
    }
    type[root] = -1;
    last = root;
    while (true) {
        type[ua] = 1;
        for (int v : adj[ua]) if (v != last) {
            last = ua; ua = v;
        }
        if (type[ua] > 0) break;
    }
    last = root;
    while (true) {
        type[ub] = 2;
        for (int v : adj[ub]) if (v != last) {
            last = ub; ub = v;
        }
        if (type[ub] > 0) break;
    }
    last = root;
    while (true) {
        type[uc] = 3;
        for (int v : adj[uc]) if (v != last) {
            last = uc; uc = v;
        }
        if (type[uc] > 0) break;
    }

    set<int> sta, stb, stc;
    FOR(i, 1, n) if (c[id[i]] == 1) {
        if (type[i] == 1) sta.insert(i);
        else if (type[i] == 2) stb.insert(i);
        else stc.insert(i);
    }
    while (q--) {
        int x; cin >> x;
        c[x] = 1-c[x];
        if (c[x] == 0) {
            if (type[x] == 1) sta.erase(x);
            else if (type[x] == 2) stb.erase(x);
            else if (type[x] == 3) stc.erase(x);
        }
        else {
            if (type[x] == 1) sta.insert(x);
            else if (type[x] == 2) stb.insert(x);
            else if (type[x] == 3) stc.insert(x);
        }

        int sizea; if (sta.size() == 0) sizea = 0; else if (sta.size() == 1) sizea = 1; else sizea = 2;
        int sizeb; if (stb.size() == 0) sizeb = 0; else if (stb.size() == 1) sizeb = 1; else sizeb = 2;
        int sizec; if (stc.size() == 0) sizec = 0; else if (stc.size() == 1) sizec = 1; else sizec = 2;

        int num = 0;
        num += sizea > 0; num += sizeb > 0; num += sizec > 0;
        if (num == 0) cout << 0 << endl;
        else if (num == 1) cout << 0 << endl;
        else if (num == 2) cout << 1 << endl;
        else cout << 2 << endl;
    }
}

void test_case() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> c[i];
    REP(i, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    int typeT = 0;
    FOR(i, 1, n) if (adj[i].size() == 3) typeT++;
    if (typeT == 0) {sub1(); return;}
    if (typeT == 1) {sub2(); return;}
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
