#include<bits/stdc++.h>
using namespace std;

#define f(a, b, c) for(int a = (b), _c = (c); a <= _c; ++a)
#define fr(a, b, c) for(int a = (b), _c = (c); a >= _c; --a)
#define ff first
#define ss second
#define ld long double
#define ll long long
#define vt vector                       //   \|/          (__)
#define pb push_back                    //        `\------(oo)
#define all(x) (x).begin(), (x).end()   //          ||    (__)
#define sz(x) ((int)((x).size()))       //          ||-vv||     \|/
#define ar array                        //      \|/
#define lb lower_bound
#define ub upper_bound
#define bit(x, i) (((x) >> (i)) & 1ll)
#define mask(i) (1ll << (i))
#define Time cerr<<"[It took "<<fixed<<setprecision(3)<<double(clock()-time)/CLOCKS_PER_SEC<<"s]"<<"\n"
#define dbg(...) cout<<"#"<<__LINE__<<":["<<#__VA_ARGS__<<"] = [",DBG(__VA_ARGS__)

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void DBG() { cout << "]" << endl; }

template<class H, class... T> void DBG(H h, T... t) {
        cout << to_string(h); if(sizeof...(t)) cout << ", "; DBG(t...);
}

template<class T> bool umin(T& a, const T& b) {
        return b<a?a=b, 1:0;
}

template<class T> bool umax(T& a, const T& b) {
        return a<b?a=b, 1:0;
}
// init done

#define MOD (ll)(1e9 + 7)
#define ii pair<ll, int>
#define oo (ll)(2e18 + 7)
#define N (ll)(1e5 + 5)

int n, m, k, l;
int fr[N];
ll d[N][mask(5)];

vt<ii> g[N];

void dij()
{
        f(i, 1, n) f(j, 0, mask(k) - 1)
                d[i][j] = oo;

        d[1][fr[1]] = 0;
        priority_queue<ar<ll, 3>, vt<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
        pq.push({d[1][fr[1]], 1, fr[1]});

        while(sz(pq)) {
                ar<ll, 3> t = pq.top(); pq.pop();

                ll du = t[0], u = t[1], sta = t[2];
                if(du != d[u][sta])
                        continue;
                for(auto i : g[u]) {
                        ll v = i.ss, w = i.ff;
                        int nxtSta = sta | fr[v];
                        if(umin(d[v][nxtSta], du + w))
                                pq.push({d[v][nxtSta], v, nxtSta});
                }
        }

        ll ans = oo;
        f(i, 0, mask(k) - 1)
                if(__builtin_popcount(i) >= l)
                        umin(ans, d[n][i]);
        if(ans == oo)
                ans = -1;
        cout << ans << "\n";
}

void bin(int val)
{
        fr(i, k - 1, 0)
                cout << bit(val, i);
        cout << "\n";
}

void test_case()
{
        cin >> n >> m >> k >> l;
        f(i, 1, n) {
                int t; cin >> t;
                f(j, 1, t) {
                        int x;
                        cin >> x;
                        --x;
                        fr[i] |= mask(x);
                }
        }

//        f(i, 1, n)
//                bin(fr[i]);

        f(i, 1, m) {
                int u, v, w;
                cin >> u >> v >> w;
                g[u].pb({w, v});
                g[v].pb({w, u});
        }

        dij();
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "dhaka"
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);

        int test = 1;
//        cin >> test;
        while(test--) {
                test_case();
                // break;
        }

        Time;
        return 0;
}

//        int n = Rand(1, 1e5);
//        vt<ii> e;
//        f(i, 1, 1e5) {
//                int u = Rand(1, n);
//                int v = Rand(1, n);
//                while(u == v) {
//                        u = Rand(1, n);
//                        v = Rand(1, n);
//                }
//                e.pb({u, v});
//        }
//        sort(all(e));
//        e.erase(unique(all(e)), e.end());
//        int m = sz(e);
//        int k = Rand(1, 5);
//        int l = Rand(1, 5);
//        fi << n << " " << m << " " << k << " " << l << "\n";
//        f(i, 1, n) {
//                int t = Rand(0, k);
//                fi << t << " ";
//                f(j, 1, t) {
//                        fi << Rand(1, k) << " ";
//                }
//                fi << "\n";
//        }
//        for(auto i : e) {
//                fi << i.ff << " " << i.ss << " " << Rand(1,10) << "\n";
//        }
