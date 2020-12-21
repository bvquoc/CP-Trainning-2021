#include <bits/stdc++.h>

#define task                "PERMEOW"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)          for(auto (a) : (u))

#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)       ((a) & (~mask(i)))

#define ft                  first
#define sd                  second
#define pb                  push_back
#define mp                  make_pair

#define sz(a)		        (int(a.size()))
#define all(a)		        a.begin(),a.end()

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;

const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double eps = 0.0000001;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

int st[4 * maxn];

void upd(int id, int l, int r, int pos, int val) {
    if(pos < l || r < pos) return ;
    if(l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, pos, val);
    upd(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

/** End of template **/

int n, a[maxn], b[maxn];
bool sub1 = true, sub2 = true;

int pos[maxn];
/**
5
3 1 4 2 5
3 1 4 2 5

5
1 3 2 4 5
1 3 2 4 5

5
1 2 3 4 5
1 2 3 4 5
**/

void subtask1() {
    ll ans = 0;
    do {
        rep(i, 1, n)
            pos[a[i]] = i;

        rep(i, 1, n) {
            int step = pos[i] - get(1, 1, n, 1, pos[i]) - 1;
            ans = (ans + step) % mod;
            upd(1, 1, n, pos[i], 1);
        }

        bool diff = true;
        rep(i, 1, n) {
            upd(1, 1, n, i, 0);
            if(a[i] != b[i])
                diff = false;
        }

        if(diff == true) break;
    } while(next_permutation(a + 1, a + n + 1));

    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n;
    rep(i, 1, n)
        cin >> a[i];
    rep(i, 1, n)
        cin >> b[i];

    rep(i, 1, n) {
        if(a[i] != b[i])
            sub1 = false;
        if(a[i] != i)
            sub2 = false;
        if(b[i] != n - i + 1)
            sub2 = false;
    }

    subtask1();
    return 0;
}
