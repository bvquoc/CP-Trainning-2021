#include <bits/stdc++.h>

#define task                "SOCKS"
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

/** End of template **/

int count_red;
int n, q, red[maxn];

void subtask1() {
    if(count_red >= 2)
        cout << 1 << "\n";
    else cout << 0 << "\n";
    while(q--) {
        int id;
        cin >> id;
        if(red[id] == 1)
            count_red--;
        else count_red++;
        red[id] = 1 - red[id];
        if(count_red >= 2)
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}

int b[maxn], branch, d[maxn], cnt[maxn];
vector<int> adj[maxn];
int red_branch[4];

void dfs(int u, int p) {
    int cnt = 0;
    b[u] = branch;
    repa(v, adj[u]) {
        if(v == p) continue;
        if(u == p) ++branch;
        dfs(v, u);
    }
}

void subtask2() {
    int root = 0;
    rep(i, 1, n)
        if(d[i] == 3)
            root = i;
    dfs(root, root);
    branch = 0;

    rep(i, 1, n)
        if(red[i] == true) {
            red_branch[b[i]]++;
            if(red_branch[b[i]] == 1)
                branch++;
        }

    if(branch == 3)
        cout << 2 << "\n";
    else if(branch == 0)
        cout << 0 << "\n";
    else cout << 1 << "\n";

    while(q--) {
        int id;
        cin >> id;
        if(red[id] == 1) {
            red_branch[b[id]]--;
            if(red_branch[b[id]] == 0)
                branch--;
            count_red--;
        }
        else {
            red_branch[b[id]]++;
            if(red_branch[b[id]] == 1)
                branch++;
            count_red++;
        }

        red[id] = 1 - red[id];
        if(branch == 3)
            cout << 2 << "\n";
        else if(branch == 0 || count_red == 1)
            cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n >> q;
    rep(i, 1, n) {
        cin >> red[i];
        if(red[i] == 1)
            count_red++;
    }
    cnt[0] = n;
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        cnt[d[u]]--, cnt[d[v]]--;
        d[u]++, d[v]++;
        cnt[d[u]]++, cnt[d[v]]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(cnt[1] + cnt[2] == n)
        subtask1();
    else if(cnt[1] + cnt[2] + cnt[3] == n && cnt[3] == 1)
        subtask2();

    return 0;
}

/**
8 7
1 0 0 0 1 0 1 0
1 2
1 3
2 4
4 5
4 6
3 7
7 8
1
6
6
5
3
3
4
**/
