#include <bits/stdc++.h>

#define task                "COOLMAC"
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

int m, n, cnt, t[maxn];
pair<int, int> a[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.sd == b.sd) return a.ft < b.ft;
    return a.sd < b.sd;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> m;
    rep(i, 1, m)
        cin >> a[i].ft >> a[i].sd;
    cin >> n;
    int minn = 1e9;
    rep(i, 1, n) {
        cin >> t[i];
        minn = min(minn, t[i]);
    }

    sort(a + 1, a + m + 1, cmp);

    int Lf = 100000, id = m;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(1) {
        while(id > 0 && a[id].sd >= Lf) {
            pq.push(a[id].ft);
            id--;
        }

        if(sz(pq) == 0) {
            cout << -1;
            return 0;
        }

        cnt++;
        Lf = pq.top();
        pq.pop();

        if(Lf <= minn || id == 0)
            break;
    }

    if(Lf > minn)
        cout << -1;
    else cout << cnt << "\n";

    return 0;
}

