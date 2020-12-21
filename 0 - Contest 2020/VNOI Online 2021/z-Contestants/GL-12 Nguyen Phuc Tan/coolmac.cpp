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
#define ii pair<int, int>
#define oo (ll)(1e9 + 7)
#define N (ll)(1e6 + 5)

int m, n;
ii a[N];
int t[N];
int limit = oo;

void sub1()
{
        int ans = oo;
        f(i, 0, mask(m) - 1) {
                vt<ii> jac;
                f(j, 0, m - 1) {
                        if(bit(i, j)) {
                                jac.pb({a[j + 1].ff, a[j + 1].ss});
                        }
                }
                sort(all(jac));
                int ma = limit; bool ok = 1;
                for(auto j : jac) {
                        if(j.ff > ma) {
                                ok = 0;
                                break;
                        }
                        umax(ma, j.ss);
                }
                if(ma < 100000)
                        ok = 0;
                if(ok)
                        umin(ans, __builtin_popcount(i));
        }
        if(ans == oo)
                ans = -1;
        cout << ans << "\n";
}

void sub2()
{
        vt<int> dp(m + 1, oo);
        sort(a + 1, a + m + 1);
        f(i, 1, m)
                if(a[i].ff <= limit && a[i].ss >= limit)
                        dp[i] = 1;
        f(i, 1, m) {
                f(j, 1, i - 1) if(dp[j] != oo) {
                        if(a[i].ff <= a[j].ss) {
                                umin(dp[i], dp[j] + 1);
                        }
                }
        }

        int ans = oo;
        f(i, 1, m)
                if(a[i].ss == 100000)
                        umin(ans, dp[i]);
        if(ans == oo)
                ans = -1;
        cout << ans << "\n";
}

int T[N];

void upd(int p, int val, int id = 1, int l = 1, int r = m)
{
        if(l == r) {
                T[id] = val;
                return;
        }
        int mid = (l + r) >> 1;
        if(p <= mid)
                upd(p, val, id << 1, l, mid);
        else
                upd(p, val, id << 1 | 1, mid + 1, r);
        T[id] = min(T[id << 1], T[id << 1 | 1]);
}

int get(int le, int ri, int id = 1, int l = 1, int r = m)
{
        if(le > r|| ri < l || le > ri)
                return oo;
        if(l >= le && r <= ri)
                return T[id];
        int mid = (l + r) >> 1;
        return min(get(le, ri, id << 1, l, mid),
                   get(le, ri, id << 1 | 1, mid + 1, r));
}

int bs(int i)
{
        int l = 1, r = i - 1, res = 0;
        while(l <= r) {
                int mid = (l + r) >> 1;
                if(a[mid].ss >= a[i].ff)
                        res = mid, r = mid - 1;
                else
                        l = mid + 1;
        }
        return res;
}

void sub3()
{
        sort(a + 1, a + m + 1, [](ii A, ii B) {
                return A.ss < B.ss;
        });

        vt<int> dp(m + 1, oo);

        f(i, 1, m) {
                if(a[i].ff <= limit && a[i].ss >= limit) {
                        dp[i] = 1;
                        upd(i, 1);
                }
        }
        f(i, 1, m)
                upd(i, dp[i]);

//        f(i, 1, m) {
//                cout << dp[i] << " " << get(i, i) << "\n";
//        }

        f(i, 1, m) {
                int p = bs(i);
                if(p == 0)
                        continue;
                umin(dp[i], get(p, i - 1) + 1);
                upd(i, dp[i]);
        }

        int ans = oo;
        f(i, 1, m)
                if(a[i].ss == 100000)
                        umin(ans, dp[i]);

        if(ans == oo)
                ans = -1;
        cout << ans << "\n";
}

void test_case()
{
        cin >> m;
        f(i, 1, m)
                cin >> a[i].ff >> a[i].ss;
        cin >> n;
        f(i, 1, n)
                cin >> t[i], umin(limit, t[i]);

        if(n <= 10 && m <= 16) {
                sub1();
                return;
        }

        if(n <= 3000 && m <= 3000) {
                sub2();
                return;
        }

        sub3();
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "coolmac"
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);

        int test = 1;
        // cin >> test;
        while(test--) {
                test_case();
                // break;
        }

//        Time;
        return 0;
}

//        int m = Rand(1, 10);
//        fi << m << "\n";
//        fi << Rand(1, 500) << " " << 100000 << "\n";
//        f(i, 1, m - 1) {
//                int l = Rand(1, 500); int r = Rand(1, 500);
//                if(l > r)
//                        swap(l, r);
//                fi << l << " " << r << "\n";
//        }
//        int n = Rand(1, 10);
//        fi << n << "\n";
//        f(i, 1, n)
//                fi << Rand(1, 500) << " ";
