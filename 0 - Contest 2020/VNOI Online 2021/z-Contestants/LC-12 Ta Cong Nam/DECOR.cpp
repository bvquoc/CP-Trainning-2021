#include <bits/stdc++.h>

#define task                "DECOR"
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

const int maxn = 5e5 + 5;
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
        st[id] += val;
        return ;
    }
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, pos, val);
    upd(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get_pos(int id, int l, int r, int pos) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(st[id * 2] < pos)
        return get_pos(id * 2 + 1, mid + 1, r, pos - st[id * 2]);
    else return get_pos(id * 2, l, mid, pos);
}

/** End of template **/

int n, m, k, light[maxn];
vector<int> adj[maxn];

void sub12() {
    int R = 0, needed = 0, ans = 0, start = 0;
    rep(L, 1, n) {
        if(L > R) {
            R = L;
            needed = 1 - light[L];
        }

        while(R <= n && needed <= k) {
            R++;
            needed += 1 - light[R];
        }

        if(ans < R - L) {
            start = L;
            ans = R - L;
        }

        needed -= 1 - light[L];
    }

    if(ans == 0)
        cout << "-1\n";
    else
        cout << start << " " << ans << "\n";
}

int scc[maxn], scc_left[maxn], cnt;
vector<int> scc_list[maxn];

void dfs(int u) {
    scc[u] = cnt;
    scc_list[cnt].pb(u);
    scc_left[cnt] += light[u];
    repa(v, adj[u])
        if(scc[v] == 0)
            dfs(v);
}

int F[maxn];
bool T[maxn];

void full() {
    rep(i, 1, n)
        if(scc[i] == 0)
            ++cnt, dfs(i);

    rep(i, 1, cnt)
        sort(scc_list[i].begin(), scc_list[i].end());

    F[0] = 0;
    int used_light = k;

    F[1] = 1;
    scc_left[scc[1]]--;
    if(scc_left[scc[1]] < 0) {
        used_light--;
        upd(1, 1, n, 1, 1);
    }

    rep(i, 2, n) {
        if(scc_left[scc[i]] > 0)
            F[i] = F[i - 1];
        else {
            if(used_light > 0) {
                used_light--;
                F[i] = F[i - 1];
            }
            else {
                int posl = get_pos(1, 1, n, 1);
                upd(1, 1, n, posl, -1);
                rep(j, F[i - 1], posl)
                    scc_left[scc[j]]++;
                F[i] = posl + 1;
            }
            int pos = lower_bound(scc_list[scc[i]].begin(), scc_list[scc[i]].end(), F[i]) - scc_list[scc[i]].begin();
            upd(1, 1, n, scc_list[scc[i]][pos], 1);
        }

        scc_left[scc[i]]--;
    }

    int ans = 0, start = 0;

    rep(i, 1, n) {
        if(i - F[i] + 1 > ans) {
            ans = i - F[i] + 1;
            start = F[i];
        }
    }

    cout << start << " " << ans << "\n";
}

void full_k0() {
    rep(i, 1, n)
        if(scc[i] == 0)
            ++cnt, dfs(i);

    rep(i, 1, cnt)
        sort(scc_list[i].begin(), scc_list[i].end());

    F[0] = 0;
    int used_light = k;

    F[0] = mod;
    rep(i, 1, n) {
        if(scc_left[scc[i]] > 0)
            F[i] = min(F[i - 1], i);
        else {
            rep(j, F[i - 1], i - 1) {
                scc_left[scc[j]]++;
                if(scc_left[scc[i]] > 0) {
                    F[i] = j;
                    break;
                }
            }
            if(scc_left[scc[i]] <= 0)
                F[i] = mod;
        }
        scc_left[scc[i]]--;
    }

    int ans = 0, start = 0;

    rep(i, 1, n) {
        if(i - F[i] + 1 > ans) {
            ans = i - F[i] + 1;
            start = F[i];
        }
    }

    cout << start << " " << ans << "\n";
}

void check_1() {
    rep(i, 1, n)
        if(light[i] == 1) return ;
    if(k > 0) return ;
    cout << "-1";
    exit(0);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n >> m >> k;
    rep(i, 1, n) {
        char c;
        cin >> c;
        light[i] = int(c - '0');
    }
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    check_1();
    if(m == 0) sub12();
    else if(k == 0) full_k0();
    else full();

    return 0;
}
